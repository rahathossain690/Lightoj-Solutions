#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
ll mod = 1000000007;
ll ncr[1001][1001], f[1001];
  int main(){
  for(int i = 0; i <= 1000; i++){
    ncr[i][0] = ncr[i][i] = 1;
    for(int j = 1; j < i; j++){
      ncr[i][j] = ncr[i-1][j]+ncr[i-1][j-1];
      if(ncr[i][j] >= mod) ncr[i][j] -= mod;
    }
  }
  f[0] = 1;
  for(int i = 1; i <= 1000; i++) f[i] = (i * 1LL * f[i-1]) % mod;
  int t = 1, tc;
  for(scanf("%d", &tc); t <= tc; t++){
    int m, n, k, sign = -1;
    scanf("%d %d %d", &n, &m, &k);
    ll ans = f[n-k];
    for(int i = 1; i <= m - k; i++, sign *= -1){
      ans += sign * (ncr[m - k][i] * f[n - k - i]) % mod;
      ans %= mod;
    }
    ans *= ncr[m][k];
    ans %= mod;
    if(ans < 0) ans += mod;
    printf("Case %d: %lld\n", t, ans);
  }
}