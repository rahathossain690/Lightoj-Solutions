#include <bits/stdc++.h>
using namespace std;
  typedef long long       ll;
typedef pair<int, int>  pii;
#define pb              push_back
#define endl            "\n"
#define mp              make_pair
const int sz = 16;
  #define SET(n, p)       (n|(1<<p))
#define CHECK(n, p)     (n&(1<<p))
  int t, tc, n, life[sz], a[sz][sz], dp[1<<sz];
  int go(unsigned int mask){
  if(mask == (1<<n) - 1) return 0;
  if(dp[mask] != -1) return dp[mask];
  int ans = 100000000;
  unsigned int temp;
  for(int i = 0; i < n; i++){
    if(!CHECK(mask, i)){
      temp = SET(mask, i);
      ans = min(ans, life[i] + go(temp));
    }
    else{
      for(int j = 0; j < n; j++)
        if(a[i][j] && !CHECK(mask, j)) ans = min(ans, (a[i][j] + life[j] - 1) / a[i][j] + go(SET(mask, j)));
    }
  }
  return dp[mask] = ans;
}
  int main(){
  for(scanf("%d", &tc); t < tc; t++){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", life + i);
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++) scanf("%1d", &a[i][j]);
    memset(dp, -1, sizeof dp);
    printf("Case %d: %d\n", t + 1, go(0));
  }
}