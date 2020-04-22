#include "bits/stdc++.h"
using namespace std;
  #define max(a,b)    (a>b?a:b)
const int sz = 101;
  int n, p[sz], c[sz], w[sz], mw, t = 1, tc, dp[sz][10010];
  int go(int in, int wt){
  if(in == n) return 0;
  if(dp[in][wt] != -1) return dp[in][wt];
  int ans = go(in + 1, wt);
  if(wt + w[in] <= mw) ans = max(ans, p[in] + go(in, wt+ w[in]));
  return dp[in][wt] = ans;
}
  int main(){
  for(scanf("%d", &tc); t <= tc; t++){
    scanf("%d %d", &n, &mw);
    for(int i = 0; i < n; i++){
      scanf("%d %d %d", p + i, c + i, w + i);
      mw -= w[i] * c[i];
    }
    printf("Case %d: ", t);
    if(mw < 0) {
      puts("Impossible");
      continue;
    }
    memset(dp, -1, sizeof dp);
    printf("%d\n", go(0, 0));
  }
  return 0;
}