#include <bits/stdc++.h>
using namespace std;
  typedef long long ll;
typedef pair<int, int> pii;
#define pb    push_back
#define endl  "\n"
#define mp    make_pair
const int sz = 13;
  int t, tc, n;
ll p[sz], r[sz], mul, ans, temp;
  ll bigmod(int a, int b, int mod){
  if(b == 0) return 1;
  if(b == 1) return a;
  ll ans = bigmod(a, b / 2, mod);
  ans = (ans * ans) % mod;
  if(b&1) ans = (ans * a) % mod;
  return ans;
}
  int main(){
  for(scanf("%d", &tc); t < tc; t++){
    scanf("%d", &n);
    mul = 1;
    ans = 0;
    for(int i = 0; i < n; i++)scanf("%lld %lld", p + i, r + i), mul *= p[i];
    for(int i = 0; i < n; i++){
      temp = (r[i] * (mul / p[i])) % mul;
      temp = (temp * bigmod((mul / p[i]) % p[i], p[i] - 2, p[i])) % mul;
      ans = ans + temp;
      ans %= mul;
    }
    if(ans < 0) ans += mul;
    printf("Case %d: %lld\n", t + 1, ans);
  }
}