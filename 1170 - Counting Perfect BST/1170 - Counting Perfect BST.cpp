#include <bits/stdc++.h>
using namespace std;
  typedef long long       ll;
typedef pair<int, int>  pii;
#define pb              push_back
#define endl            "\n"
#define mp              make_pair
const ll MX = 10000000000, mod = 100000007;
  int t, tc, item;
ll a, b, dp[103000];
vector<ll> p;
set<ll> q;
set<ll> ::iterator it;
  ll go(int n){
  if(n == 0) return 1;
  if(dp[n] != -1) return dp[n];
  ll ans = 0;
  for(int i = 1; i <= n; i++) ans = (ans + (go(i - 1) * go(n - i)) % mod) % mod;
  return dp[n] = ans;
}
  int main(){
  for(ll i = 2; i * i <= MX ; i++){
    ll res = i;
    for(; res * i <= MX;) q.insert(res *= i);
  }
  for(it = q.begin(); it != q.end(); it++) p.pb(*it);
  memset(dp, -1, sizeof dp);
  for(scanf("%d", &tc); t < tc; t++){
    scanf("%lld %lld", &a, &b);
    item = (int)(upper_bound(p.begin(), p.end(), b) - lower_bound(p.begin(), p.end(), a));
    if(item == 0){
      printf("Case %d: 0\n", t + 1);
      continue;
    }
    printf("Case %d: %lld\n", t + 1, go(item));
  }
    return 0;
}