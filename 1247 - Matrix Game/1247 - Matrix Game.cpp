#include<bits/stdc++.h>
using namespace std;
  typedef long long ll;
  const int N = 51;
  int t, tc, n, m;
ll c[N], tmp;
  int main(){
    for(scanf("%d", &tc); t < tc; t++){
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; i++){
            c[i] = 0;
            for(int j = 0; j < m; j++){
                scanf("%lld", &tmp);
                c[i] += tmp;
            }
        }
        ll ans = 0;
        for(int i = 0; i < n; i++) ans ^= c[i];
        printf("Case %d: %s\n", t + 1, ans ? "Alice" : "Bob");
    }
}