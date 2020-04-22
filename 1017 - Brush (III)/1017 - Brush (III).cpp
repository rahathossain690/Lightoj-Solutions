#include "bits/stdc++.h"
using namespace std;
  #define max(a,b)    (a>b?a:b)
const int sz = 101;
  int a[sz], n, w, l, k, dp[sz][sz], t = 1, tc;
  int cnt(int in, int tk){
  if(tk == 0) return 0;
  if(in == n) return 0;
  if(dp[in][tk] != -1) return dp[in][tk];
  int temp = upper_bound(a, a + n, a[in] + w) - a;
  temp -= in;
  return dp[in][tk] = max( temp + cnt(temp + in, tk - 1) , cnt(in + 1, tk) );
}
  int main(){
  for(scanf("%d", &tc); t <= tc; t++){
    scanf("%d %d %d", &n, &w, &k);
    for(int i = 0; i < n ; i ++){
      scanf("%d %d", &l, &a[i]);
    }
    sort(a, a + n);
    memset(dp, -1, sizeof dp);
    printf("Case %d: %d\n", t, cnt(0, k));
  }
    return 0;
}