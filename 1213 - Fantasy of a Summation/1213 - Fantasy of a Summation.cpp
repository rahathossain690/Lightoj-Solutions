#include <bits/stdc++.h>
using namespace std;
  int t = 1, tc;
long long ans, tot, temp, n, k, mod;
  long long bigmod(long long a, long long b){
  if(b == 0) return 1;
  if(b == 1) return a;
  long long ans = bigmod(a, b / 2);
  ans = (ans * ans) % mod;
  if(b % 2 == 1) ans = (ans * a) % mod;
  return ans;
}
  int main(){
  for(scanf("%d", &tc); t <= tc; t++){
    scanf("%lld %lld %lld", &n, &k, &mod);
    tot = 0;
    for(int i = 0; i < n; i++){
      scanf("%lld", &temp);
      tot += temp;
    }
    ans = tot % mod;
    ans = (ans * (k % mod)) % mod;
    ans *= bigmod(n, k-1);
    ans %= mod;
    printf("Case %d: %lld\n", t, ans);
  }
}