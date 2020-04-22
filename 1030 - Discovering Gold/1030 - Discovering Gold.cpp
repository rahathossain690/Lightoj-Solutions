#include "bits/stdc++.h"
using namespace std;
  #define td(n) scanf("%d",&n)
  int n,a[104];
double dp[101];
  double go(int i){
  if(dp[i]!=-1) return dp[i];
  if(i == n-1) return (double)a[n-1];
  double ans = 0;
  int limit = min (n-i-1, 6), k = limit;
  for(int j = 1;k--;j++)ans += go(i+j);
  return dp[i] = a[i]+ (ans/limit);
}
  int main(){
  int t=1,tc;
  for(td(tc);t<=tc;t++){
    td(n);
    for(int i = 0; i<n;i++)td(a[i]),dp[i] = -1;
    printf("Case %d: %.6lf\n",t,go(0));
  }
}