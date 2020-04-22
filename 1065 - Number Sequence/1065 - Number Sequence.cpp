#include <bits/stdc++.h>
using namespace std;
  typedef long long ll;
typedef pair<ll, ll> pii;
#define pb            push_back
#define endl          "\n"
#define mp          make_pair
const int mod = 10000;
  int t, tc, a, b, n, m, md[] = {1, 10, 100, 1000, 10000};
pair<pii, pii> I, fib, ans;
  pair<pii, pii> mul(pair<pii, pii> a, pair<pii, pii> b){
  pair<pii, pii> ans;
  ans.first.first = (a.first.first * b.first.first + a.first.second * b.second.first) % mod;
  ans.first.second = (a.first.first * b.first.second + a.first.second * b.second.second) % mod;
  ans.second.first = (a.second.first * b.first.first + a.second.second * b.second.first) % mod;
  ans.second.second = (a.second.first * b.second.first + a.second.second * b.second.second) % mod;
  return ans;
}
  pair<pii, pii> power(pair<pii, pii> a, int p){
  if(p == 0) return I;
  if(p == 1) return fib;
  pair<pii, pii> ans = power(a, p / 2);
  ans = mul(ans, ans);
  if(p & 1) ans = mul(ans, fib);
  return ans;
}
  int main(){
  I.first = mp(1, 0);
  I.second = mp(0, 1);
  fib.first = mp(1, 1);
  fib.second = mp(1, 0);
  for(scanf("%d", &tc); t < tc; t++){
    scanf("%d %d %d %d", &a, &b, &n, &m);
    printf("Case %d: ", t + 1);
    if(n == 0) printf("%d\n", a % md[m]);
    else if(n == 1)printf("%d\n", b % md[m]);
    else {
      ans = power(fib, n - 1);
      printf("%lld\n", ((ans.first.first * b) + (ans.first.second * a)) % md[m]);
    }
  }
    return 0;
}