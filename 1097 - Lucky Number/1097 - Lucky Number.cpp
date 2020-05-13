#include<bits/stdc++.h>
using namespace std;
 
 
const int N = 1429433;
// const int N = 21;

int tree[3 * N];
int T, TC, n;

void update(int node, int left, int right, int p, int plus){
	if(left == right){
		tree[node] += plus; //cout << left << " " << p << " " << node << endl;
		return;
	}
	int mid = (left + right) >> 1;
	if (p <= mid) update(node << 1, left, mid, p, plus);
	else update(1 + (node << 1), mid + 1, right, p, plus);
	tree[node] = tree[(node << 1)] + tree[1 + (node << 1)];
}

int query(int node, int left, int right, int fre){ //cout << node << " " << left << " " << right << " " << fre; 
	if(left == right){ //cout << endl;
		return left;
	}
	int mid = (left + right) >> 1; //cout << " " << tree[node << 1] << endl;
	if(tree[node << 1] >= fre) return query(node << 1, left, mid, fre);
	else return query(1 + (node << 1), mid + 1, right, fre - tree[node << 1]);
}

void pre(){
	for(int i = 1; i < N; i += 2) update(1, 1, N - 1, i, 1);
	vector<int> pos;
	for(int i = 2; i <= 100000;i++){
		int gap = query(1, 1, N - 1, i);
		for(int j = gap; j < N; j += gap){
			pos.push_back( query(1, 1, N - 1, j) );
		}
		for(auto& v: pos) update(1, 1, N - 1, v, -1);//, cout << v << " "; cout << endl;
		pos.clear();
	}
}

int main(){
	for(scanf("%d", &TC), pre(); T < TC; T++){
		scanf("%d", &n);
		printf("Case %d: %d\n", T + 1, query(1, 1, N - 1, n));
	}
}