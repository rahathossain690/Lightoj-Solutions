#include<bits/stdc++.h>
using namespace std;


const int N = 150005;

int a[N], BIT[N], n, q, T, TC;
char cmd[4];

void update(int idx){
	while(idx <= N){
		BIT[idx] += 1;
		idx += ((idx) & (-idx));
	}
}

int query(int idx){
	int sum = 0;
	while(idx > 0){
		sum += BIT[idx];
		idx -= ((idx) & (-idx));
	}
	return sum;
}

int findO(long long ans){
	if(n - query(n) < ans or n < ans) return -1;
	int lo = 1, hi = n, mid;
	while(lo <= hi){
		mid = (lo + hi) / 2; 
		int x = mid - query(mid); //cout << lo << " " << hi << " " << mid << " " << query(mid) << " " << x << endl;
		if(lo == hi){
			if(x == ans){
				update(lo);
				return lo;
			} return -1;
		}
		if(x == ans) hi = mid;
		else if (x < ans) lo = mid + 1;
		else hi = mid - 1;	
	}
}

void solve(){
	memset(BIT, 0, sizeof BIT);
	scanf("%d %d", &n, &q);
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
	while(q--){
		long long p;
		scanf("%s %lld", cmd, &p); //cout << cmd << " " << p << endl;
		if (cmd[0] == 'a'){
			a[++n] = p;
		} else {
			int ans = findO(p); //cout << findO(p) << endl;
			if(ans == -1) puts("none");
			else printf("%d\n", a[ans]);
		}
	} //for(int i = 1; i <= n; i++) cout << query(i) << " ";
}

int main(){
	for(scanf("%d", &TC); T < TC; T++){
		printf("Case %d:\n", T + 1);
		solve();
	}
}