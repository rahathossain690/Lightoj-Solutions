#include<bits/stdc++.h>
using namespace std;
  typedef long long ll;
const int mod = 1000000007; // the world isn't a right place for you
  ll t, tc, n, k, ans;
  ll bigmod(ll a, ll b){
  if(b == 0) return 1;
  ll ans = bigmod(a, b / 2);
  ans = (ans * ans) % mod;
  if(b&1) ans = (ans * a) % mod;
  return ans;
}
  int main(){
  for(scanf("%lld", &tc); t < tc; t++){
    scanf("%lld %lld", &n, &k);
    ans = 0;
    for(ll i = 1; i <= n; i++){
      ans = (ans + bigmod(k, __gcd(n, i))) % mod;
    }
    ans = (ans * bigmod(n, mod - 2)) % mod;
    printf("Case %lld: %lld\n", t + 1, ans);
  }
}