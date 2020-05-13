#include<bits/stdc++.h>
using namespace std;
 
const int N = 100001;
int n, tree[3 * N], lazy[3 * N], q, cmd;
int T, TC;

// build not used here
// void build(int node, int left, int right){
// 	if(left == right){
// 		tree[node] = a[left];
// 		return;
// 	}
// 	int mid = (left + right) >> 1;
// 	build(node << 1, left, mid);
// 	build(1 + (node << 1), mid + 1, right);
// 	tree[node] = tree[node << 1] + tree[1 + (node << 1)];
// }

//  update if it is not updated
//  complete overlap: update tree and lazy
//  else recurse

void update(int node, int left, int right, int l, int r, int val){ //cout << node << " " << left << " " << right << " " << l << " " << r << " " << (r < left and right < l) << endl;
	if(lazy[node] != -1){ // not updated
		tree[node] = (right - left + 1) * lazy[node];
		if(left != right){ // not leaf node
			lazy[node << 1] = lazy[node];
			lazy[1 + (node << 1)] = lazy[node];
		}
		lazy[node] = -1;
	}
	if(r < left or right < l) return; // not in range
	if(l <= left and right <= r){ // completely inside
		tree[node] = (right - left + 1) * val;
		if(left != right){ // not leaf
			lazy[node << 1] = val;
			lazy[1 + (node << 1)] = val;
		}
		return;
	}
	int mid = (left + right) >> 1;
	update(node << 1, left, mid, l, r, val);
	update(1 + (node << 1), mid + 1, right, l, r, val);
	tree[node] = tree[node << 1] + tree[1 + (node << 1)];
}

// update if not updated
// if inside no worry
// else recurse

int query(int node, int left, int right, int l, int r){
	if(r < left or right < l) return 0; // not in range
	//cout << left << " " << right << " " << tree[node] << " " << lazy[node] << endl; 
	if(lazy[node] != -1){ // not updated
		tree[node] = (right - left + 1) * lazy[node]; //cout << " " << (right - left + 1) * lazy[node] << endl;
		if(left != right){ // not leaf node
			lazy[node << 1] = lazy[node];
			lazy[1 + (node << 1)] = lazy[node];
		}
		lazy[node] = -1;
	}
	//cout << left << " " << right << " " << tree[node] << " " << lazy[node] << endl << endl; 
	if(l <= left and right <= r) return tree[node];
	int mid = (left + right) >> 1;
	int ans1 = query(node << 1, left, mid, l, r);
	int ans2 = query(1 + (node << 1), mid + 1, right, l, r);
	return ans1 + ans2;
}

int solve(){
	memset(tree, 0, sizeof tree);
	memset(lazy, -1, sizeof lazy);
	scanf("%d %d", &n, &q);
	int l, r, val;
	while(q--){
		scanf("%d %d %d", &cmd, &l, &r);
		if(cmd == 1){
			scanf("%d", &val);
			update(1, 0, n - 1, l, r, val);
			//for(int i = 0; i <n ; i++) cout << query(1, 0, n - 1, i, i) << " "; cout << endl;
		} else {
			int ans = query(1, 0, n - 1, l, r);
			int jin = (r - l + 1);
			int g = __gcd(ans, jin); //cout << ans << " " << jin << " " << g << endl;
			ans /= g;
			jin /= g;
			printf("%d", ans);
			if(jin != 1) printf("/%d", jin);
			puts("");
		}
	}
}

int main(){
	for(scanf("%d", &TC); T < TC; T++){
		printf("Case %d:\n", T + 1);
		solve();
	}
}