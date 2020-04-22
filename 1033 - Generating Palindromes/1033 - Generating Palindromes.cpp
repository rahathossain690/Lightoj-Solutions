#include "bits/stdc++.h"
using namespace std;
  char a[101];
int dp[101][101];
  int TASNIM_VAI_JINDABAD(int i, int j){
  if(i >= j) return 0;
  if(dp[i][j] != -1) return dp[i][j];
  if(a[i] == a[j]) return dp[i][j] = TASNIM_VAI_JINDABAD(i + 1, j - 1);
  else return dp[i][j] = 1 + min( TASNIM_VAI_JINDABAD(i + 1, j), TASNIM_VAI_JINDABAD(i, j - 1) );
}
  int main(){
  int t = 1, tc;
  for(scanf("%d", &tc); t <= tc; t++){
    scanf("%s", a);
    memset(dp, -1, sizeof dp);
    printf("Case %d: %d\n", t, TASNIM_VAI_JINDABAD(0, strlen(a) - 1));
  }
}