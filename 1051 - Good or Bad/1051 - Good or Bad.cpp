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
  int t, tc, l, dp[sz][sz][sz], ans, ans1, ans2;
char a[sz];
  bool isV(int in){
  if(a[in] == 'A' || a[in] == 'E' || a[in] == 'I' || a[in] == 'O' || a[in] == 'U') return 1;
  return 0;
}
  int go(int in, int c, int v){
  if(in == l) return 1;
  if(dp[in][c][v] != -1) return dp[in][c][v];
  if(a[in] == '?'){
    int ans1 = c >= 4 ? 2 : go(in + 1, c + 1, 0);
    int ans2 = v >= 2 ? 2 : go(in + 1, 0, v + 1);
    if(ans1 == 3 || ans2 == 3) return dp[in][c][v] = 3;
    if((ans1 == 2 && ans2 == 1) || (ans1 == 1 && ans2 == 2)) return dp[in][c][v] = 3;
    return dp[in][c][v] = ans1;
  }
  if(isV(in)) {
    if(v >= 2) return dp[in][c][v] = 2;
    return dp[in][c][v] = go(in + 1, 0, v + 1);
  }
  if(c >= 4) return dp[in][c][v] = 2;
  return dp[in][c][v] = go(in + 1, c + 1, 0);
}
  int main(){
  for(scanf("%d", &tc); t < tc; t++){
    scanf("%s", a);
    l = strlen(a);
    memset(dp, -1, sizeof dp);
    ans = go(0, 0, 0);
    printf("Case %d: ", t + 1);
    if(ans == 1) puts("GOOD");
    else if(ans == 2) puts("BAD");
    else puts("MIXED");
  }
    return 0;
}