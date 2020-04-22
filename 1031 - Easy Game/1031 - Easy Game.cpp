#include <bits/stdc++.h>
using namespace std;
  typedef long long       ll;
typedef pair<int, int>  pii;
#define pb              push_back
#define endl            "\n"
#define mp              make_pair
const int sz = 105, inf = 1<<29;
  int n, t, tc, a[sz], sum[sz], A, dp[sz][sz][2];
  int range(int f, int s){
  return sum[s] - sum[f - 1];
}
  int go(int f, int s, int t){
  if(f > s) return 0;
  int &ret = dp[f][s][t];
  if(ret != -1) return ret;
  int ans;
  if(t){
    ans = -inf;
    for(int k = 0; f + k <= s ; k++) ans = max(ans, range(f, f + k) + go(f + k + 1, s, 0));
    for(int k = 0; s - k >= f ; k++) ans = max(ans, range(s - k, s) + go(f, s - k - 1, 0));
    return ret = ans;
  }
  else {
    ans = inf;
    for(int k = 0; f + k <= s ; k++) ans = min(ans, -range(f, f + k) + go(f + k + 1, s, 1));
    for(int k = 0; s - k >= f ; k++) ans = min(ans, -range(s - k, s) + go(f, s - k - 1, 1));
    return ret = ans;
  }
}
  int main(){
  for(scanf("%d", &tc); t < tc; t++){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", a + i), sum[i] = sum[i - 1] + a[i];
    memset(dp, -1, sizeof dp);
    A = go(1, n, 1);
    printf("Case %d: %d\n", t + 1, A);
  }
}