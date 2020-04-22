#include <bits/stdc++.h>
using namespace std;
  typedef long long       ll;
typedef pair<int, int>  pii;
#define pb              push_back
#define endl            "\n"
#define mp              make_pair
const int MAX = 3600, mod = 1000000007;
  bool _s[MAX];
ll p[MAX], pn[MAX], sz, K, P, ans;
int t, tc;
ll dp[505][505];
  void siv(){
  pn[sz] = 1;
  p[sz++] = 2;
  for(int i = 3; i * i < MAX; i += 2){
    if(!_s[i]) for(int j = i * i; j < MAX; j += i + i) _s[j] = 1;
  }
  for(int i = 3; i < MAX; i += 2) if(!_s[i]) pn[sz] = (pn[sz - 1] * (i - 1)) % mod, p[sz++] = i;
}
  ll go(int in, int taken){
  if(taken == 0) return 1;
  if(in == -1) return 0;
  if(dp[in][taken] != -1) return dp[in][taken];
  ll ans2 = go(in - 1, taken);
  ll ans1 = (p[in] * go(in, taken - 1)) % mod;
  return dp[in][taken] = (ans1 + ans2) % mod;
}
  int main(){
  siv();
  memset(dp, -1, sizeof dp);
  for(scanf("%d", &tc); t < tc; t++){
    scanf("%lld %lld", &K, &P);
    ans = (go(P - 1, K - P) * pn[P - 1]) % mod;
    printf("Case %d: %lld\n", t + 1, ans);
  }
    return 0;
}