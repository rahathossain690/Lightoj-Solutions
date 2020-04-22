#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define check(n,i) ((n&(1<<i))!=0)
#define set(n,i) (n|(1<<i))
  int dp[17][5 + (1<<16)],a[17][17],n;
  int make(int in, unsigned int mask){
  if(in == n) return 0;
  if(dp[in][mask] != -1) return dp[in][mask];
  int ans = 0;
  for(int i = 0; i<n; i++){
    if(!check(mask,i))ans = max(ans, a[in][i] + make(in+1, set(mask,i)));
  }
  return dp[in][mask] = ans;
}
  int solve(){
  scanf("%d",&n);
  memset(dp,-1,sizeof(dp));
  unsigned int temp = 0;
  for (int i = 0; i< n ; i ++){
    for(int j = 0; j < n ; j ++) scanf("%d", &a[i][j]);
  }
  int ans = 0;
  for(int i = 0; i < n; i++){
    ans = max(ans, a[0][i] + make(1,set(temp,i)));
  }
  printf("%d\n",ans);
}
  int main(){
  int t = 1, tc;
  for(scanf("%d",&tc); t <= tc; t++){
    printf("Case %d: ",t);
    solve();
  }
}