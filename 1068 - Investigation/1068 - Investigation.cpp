#include <bits/stdc++.h>
using namespace std;
  typedef long long       ll;
typedef pair<int, int>  pii;
#define pb              push_back
#define endl            "\n"
#define mp              make_pair
const int sz = 15;
  int t, tc, k, f, s, p[sz], l, dp[sz][3][150][150];
ll a, b;
  int go(int in, bool tgt, int rm, int fm){
  if(in == -1) return rm == fm && rm == 0;
  if(dp[in][tgt][rm][fm] != -1) return dp[in][tgt][rm][fm];
  int ans = 0;
  if(tgt){
    ans += go(in - 1, 1, (rm * 10 + p[in] + k) % k, (fm + p[in] + k) % k);
    for(int i = p[in] - 1; i >= 0; i--)
      ans += go(in - 1, 0, (rm * 10 + i + k) % k ,(fm + i + k) % k);
  }
  else {
    for(int i = 0; i <= 9; i++)
      ans += go(in - 1, 0, (rm * 10 + i + k) % k ,(fm + i + k) % k);
  }
  return dp[in][tgt][rm][fm] = ans;
}
  int solve(ll n){
  if(n == 0) return 1;
  l = 0;
  while(n > 0){
    p[l++] = n % 10;
    n /= 10;
  }
  memset(dp, -1, sizeof dp);
  return go(l - 1, 1, 0, 0);
}
  int main(){
  for(scanf("%d", &tc); t < tc; t++){
    scanf("%lld %lld %d", &a, &b, &k);
    if(k > 108){
      printf("Case %d: 0\n", t + 1);
      continue;
    }
    f = solve(b);
    s = solve(a - 1);
    printf("Case %d: %d\n", t + 1, f - s);
  }
    return 0;
}