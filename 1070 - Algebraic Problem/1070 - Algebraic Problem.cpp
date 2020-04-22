#include <bits/stdc++.h>
using namespace std;
  typedef unsigned long long ll;
typedef pair<ll, ll> pii;
#define pb            push_back
#define endl          "\n"
#define mp          make_pair
  int t, tc;
ll p, q, n;
pair<pii, pii> I, f, ans;
  pair<pii, pii> mul(pair<pii, pii> a, pair<pii, pii> b){
  pair<pii, pii> ans;
  ans.first.first = (a.first.first * b.first.first + a.first.second * b.second.first);
  ans.first.second = (a.first.first * b.first.second + a.first.second * b.second.second);
  ans.second.first = (a.second.first * b.first.first + a.second.second * b.second.first);
  ans.second.second = (a.second.first * b.first.second + a.second.second * b.second.second);
  return ans;
}
  pair<pii, pii> power(pair<pii, pii> a, ll p){
  if(p == 0) return I;
  if(p == 1) return a;
  pair<pii, pii> ans = power(a, p / 2);
  ans = mul(ans, ans);
  if(p % 2 == 1) ans = mul(ans, a);
  return ans;
}
  int main(){
  f.second = I.first = mp(1, 0);
  I.second = mp(0, 1);
  for(scanf("%d", &tc); t < tc; t++){
    scanf("%llu %llu %llu", &p, &q, &n);
    f.first = mp(p, -q);
    printf("Case %d: ", t + 1);
    if(n == 0) printf("2\n");
    else if(n == 1) printf("%llu\n", p);
    else if(n == 2) printf("%llu\n", p * p - 2 * q);
    else{
      ans = power(f, n - 2);
      printf("%llu\n", ans.first.first * (p * p - 2 * q) + ans.first.second * p);
    }
  }
    return 0;
}