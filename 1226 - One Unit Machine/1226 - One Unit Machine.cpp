#include<bits/stdc++.h>
using namespace std;
  typedef long long ll;
const ll N = 1000005, mod =  1000000007;
  ll f[N];
int n, a, t, tc;
  ll bigmod(ll a, ll b){
  if(b == 0) return 1;
  ll ans = bigmod(a, b / 2);
  ans = (ans * ans) % mod;
  if(b&1) ans = (ans * a) % mod;
  return ans;
}
  ll modinv(ll a){
  return bigmod(a, mod - 2);
}
  ll solve(){
  scanf("%d", &n);
  ll ans = 1, prev = 0;
  while(n--){
    scanf("%d", &a);
    ans *= f[prev + a - 1];
    ans %= mod;
    ans *= modinv(f[a - 1]);
    ans %= mod;
    ans *= modinv(f[prev]);
    ans %= mod;
    prev += a;
  }
  if(ans < 0) ans += mod;
  return ans;
}
  int main(){
  f[0] = 1;
  for(int i = 1; i < N; i++) f[i] = (f[i - 1] * i) % mod;
  for(scanf("%d", &tc); t < tc; printf("Case %d: %lld\n", ++t, solve()));
}