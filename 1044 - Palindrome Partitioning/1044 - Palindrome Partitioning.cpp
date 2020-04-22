#include "bits/stdc++.h"
using namespace std;
const int inf = 999999999;
  char a[100001];
int dp[100001], n;
  bool ispal(int i, int j){
  for(;i < j;i++,j--)if(a[i]!=a[j]) return 0;
  return 1;
}
  int go(int in){
  if(in == n) return 0;
  if(dp[in] != -1) return dp[in];
  int ans = inf;
  for(int i = in; i < n; i++){
    if(ispal(in, i))ans = min ( ans, go( i + 1 ) );
  }
  return dp[in] = 1 + ans;
}
  int main(){
  int t = 1, tc = 0;
  for(scanf("%d", &tc); t <= tc; t++){
    scanf("%s", a);
    n = strlen(a);
    memset(dp, -1, sizeof dp);
    printf("Case %d: %d\n", t, go(0));
  }
}