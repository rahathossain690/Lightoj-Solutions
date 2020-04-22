#include <bits/stdc++.h>
using namespace std;
  typedef long long ll;
typedef pair<int, int> pii;
#define pb          push_back
#define endl        "\n"
#define mp          make_pair
#define min(a,b)    (a<b?a:b)
#define max(a,b)    (a>b?a:b)
const int sz = 51;
  int t = 1, tc, n, m, k;
ll dp[sz][sz][sz];
  ll BC(int N, int M, int K){
  if(M == 0 && N == 0) return 1;
  if(M == 0) return 0;
  if(dp[N][M][K] != -1) return dp[N][M][K];
  ll ans = 0;
  for(int i = 1; i <= K; i++)
    if(N >= i) ans += BC(N - i, M - 1, K);
  return dp[N][M][K] = ans;
}
  int main(){
  memset(dp, -1, sizeof dp);
  for(scanf("%d", &tc); t <= tc; t++){
    scanf("%d %d %d", &n, &m, &k);
    printf("Case %d: %lld\n", t, BC(n, m, k));
  }
}