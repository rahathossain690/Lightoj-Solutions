#include <bits/stdc++.h>
using namespace std;
  typedef long long       ll;
typedef pair<int, int>  pii;
#define pb              push_back
#define endl            "\n"
#define mp              make_pair
const int sz = 17, inf = 10000;
  #define SET(n, p)       (n|(1<<p))
#define CHECK(n, p)     (n&(1<<p))
  int t, tc, m, n, px[sz], py[sz], cnt, dp[1<<sz][sz], mex, mey;
char a[21][21];
  int dist(int p1, int p2){
  return max(abs(px[p1] - px[p2]), abs(py[p1] - py[p2]));
}
  int go(unsigned int mask, int in){
  if(mask == (1<<cnt) - 1) return dist(0, in);
  if(dp[mask][in] != -1) return dp[mask][in];
  int ans = inf;
  for(int i = 1; i < cnt; i++){
    if(!CHECK(mask, i))
      ans = min(ans, dist(i, in) + go(SET(mask, i), i));
  }
  return dp[mask][in] = ans;
}
  int main(){
  for(scanf("%d", &tc); t < tc; t++){
    cnt = 1;
    scanf("%d %d", &m, &n);
    for(int i = 0; i < m; i++){
      scanf("%s", a[i]);
      for(int j = 0; j < n; j++){
        if(a[i][j] == 'x') px[0] = i, py[0] = j;
        else if(a[i][j] == 'g')px[cnt] = i, py[cnt++] = j;
      }
    }
    printf("Case %d: ", t + 1);
    if(cnt == 1){
      puts("0");
      continue;
    }
    memset(dp, -1, sizeof dp);
    printf("%d\n", go(1, 0));
  }
}