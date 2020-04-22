#include<bits/stdc++.h>
using namespace std;
  const int N = 1002;
  typedef long long ll;
typedef pair<int, int> Pair;
  int t, tc, n, a[N], c[N];
ll ans, mod = 1000000007, p;
  int main(){
  for(scanf("%d", &tc); t < tc; t++){
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    for (int i = 0; i < n; i++) scanf("%d", c + i);
    sort(a, a + n);
    sort(c, c + n);
    ans = 1;
    for(int i = 0; i < n; i++){
      p = upper_bound(a, a + n, c[i]) - a;
      ans = (ans * max(p - i, 0LL)) % mod;
    }
    if(ans < 0) ans += mod;
    printf("Case %d: %lld\n", t + 1, ans);
  }
}