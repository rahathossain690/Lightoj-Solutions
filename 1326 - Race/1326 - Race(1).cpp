#include "bits/stdc++.h"
using namespace std;
/*
  Ordered Bell
*/
typedef long long ll;
ll mod = 10056, ncr[1001][1001], ans[1001];
  int main(){
  int t = 1, tc = 0;
  ncr[0][0] = 1;
  for(int i = 1; i <= 1000; i++){
    ncr[i][0] = ncr[i][i] = 1;
    for(int j = 1; j < i; j++){
      ncr[i][j] = ncr[i-1][j-1] + ncr[i-1][j];
      if(ncr[i][j] > mod) ncr[i][j] -= mod;
    }
  }
  ans[1] = ans[0] = 1;
  for(int i = 2; i <= 1000; i++){
    for(int j = 1; j <= i; j++){
      ans[i] += ncr[i][j] * ans[i - j];
      ans[i] = ans[i] % mod;
    }
    if(ans[i] < 0) ans[i] += mod;
  }
  for(scanf("%d", &tc); t <= tc; t++){
    int n;
    scanf("%d", &n);
    printf("Case %d: %d\n", t, ans[n]);
  }
}