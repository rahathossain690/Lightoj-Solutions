#include <bits/stdc++.h>
using namespace std;
  typedef long long       ll;
typedef pair<int, int>  pii;
#define pb              push_back
#define endl            "\n"
#define mp              make_pair
const int sz = 205;
  int n, q, d, m, t, tc;
ll dp[sz][11][21][21], a[sz];
  ll go(int in, int m, int d, int sum){
  if(dp[in][m][d][sum] != -1) return dp[in][m][d][sum];
  if(m == 0) return dp[in][m][d][sum] = (sum == 0);
  if(n == in) return dp[in][m][d][sum] = 0;
  return dp[in][m][d][sum] = go(in + 1, m, d, sum) + go(in + 1, m - 1, d, ((sum + a[in]) % d + d) % d);
}
  int main(){
  for(scanf("%d", &tc); t < tc; t++){
    scanf("%d %d", &n, &q);
    for(int i = 0; i < n; i++) scanf("%lld", a + i);
    printf("Case %d:\n", t + 1);
    memset(dp, -1, sizeof dp);
    while(q--){
      scanf("%d %d", &d, &m);
      printf("%lld\n", go(0, m, d, 0));
    }
  }
    return 0;
}