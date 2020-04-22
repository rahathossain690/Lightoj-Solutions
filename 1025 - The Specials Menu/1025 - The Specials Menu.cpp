#include "bits/stdc++.h"
using namespace std;
  typedef long long ll;
#define min(a,b)    (a<b?a:b)
#define max(a,b)    (a>b?a:b)
const int sz = 65;
int t = 1, tc;
ll dp[sz][sz];
char a[sz];
  ll go(int l, int r){
  if(l == r) return 1;
  if(l > r) return 0;
  if(dp[l][r] != -1) return dp[l][r];
  if(a[l] == a[r]) return dp[l][r] = 1 + go(l, r - 1) + go(l + 1, r);
  return dp[l][r] = go(l, r - 1) + go(l + 1, r) - go(l + 1, r - 1);
}
  int main(){
  for(scanf("%d", &tc); t <= tc; t++){
    scanf("%s", a);
    memset(dp, -1, sizeof dp);
    printf("Case %d: %lld\n", t, go(0, strlen(a) - 1));
  }
}