#include "bits/stdc++.h"
using namespace std;
  // reyad vai <3 :')
  typedef long long ull;
#define min(a,b)    (a<b?a:b)
#define max(a,b)    (a>b?a:b)
const int sz = 32;
  int t = 1, tc, l1, l2, l, dp[sz][sz];
ull dp2[sz + sz][sz][sz];
char a[sz], b[sz];
  int lcs(int m, int n){
  if(m == -1 || n == -1) return 0;
  if(dp[m][n] != -1) return dp[m][n];
  if(a[m] == b[n]) return dp[m][n] = 1 + lcs(m - 1, n - 1);
  return dp[m][n] = max( lcs(m - 1, n), lcs(m, n - 1) );
}
  ull total(int len, int m, int n){
  if(len == 0 && m == l1 && n == l2) return 1;
  if(len == 0) return 0;
  if(m == l1 && n == l2) return 0;
  if(m > l1 || n > l2) return 0;
  if(dp2[len][m][n] != -1) return dp2[len][m][n];
  if(a[m] == b[n]) return dp2[len][m][n] = total(len - 1, m + 1, n + 1);
  return dp2[len][m][n] = total(len - 1, m + 1, n) + total(len - 1, m, n + 1);
}
  int main(){
  for(scanf("%d", &tc); t <= tc; t++){
    scanf("%s %s", a, b);
    memset(dp, -1, sizeof(dp));
    memset(dp2, -1, sizeof(dp2));
    l1 = strlen(a);
    l2 = strlen(b);
    l = l1 + l2 - lcs(l1 - 1, l2 - 1);
    printf("Case %d: %d %lld\n", t, l, total(l, 0, 0));
  }
    return 0;
}