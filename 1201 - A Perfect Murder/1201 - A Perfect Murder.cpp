#include <bits/stdc++.h>
using namespace std;
  // thanks to reyad vai
  typedef long long       ll;
typedef pair<int, int>  pii;
#define pb              push_back
#define endl            "\n"
#define ff              first
#define ss              second
#define BOOST           ios_base::sync_with_stdio(false)
#define mp              make_pair
const int sz = 10005;
  int n, m, t, u, v, tc, ans, dp[sz][3];
vector<int> node[sz];
bool vis[sz];
  void clear(){
  for(int i = 1; i <= n; i++) node[i].clear();
  ans = 0;
  memset(vis, 0, sizeof vis);
  memset(dp, -1, sizeof dp);
}
  int go(int in, int p, int c){
  if(dp[in][c] != -1) return dp[in][c];
  int ans = c;
  vis[in] = 1;
  for(int i = 0; i < node[in].size(); i++){
    if(node[in][i] == p) continue;
    if(c) ans += go(node[in][i], in, 0);
    else ans += max( go(node[in][i], in, 1) , go(node[in][i], in, 0) );
  }
  return dp[in][c] = ans;
}
  int main(){
  for(scanf("%d", &tc); t < tc; t++){
    scanf("%d %d", &n, &m);
    clear();
    while(m--){
      scanf("%d %d", &u, &v);
      node[u].pb(v);
      node[v].pb(u);
    }
    for(int i = 1; i <= n; i++){
      if(!vis[i]) {
        ans += max(go(i, 0, 0), go(i, 0, 1));
      }
    }
    printf("Case %d: %d\n", t + 1, ans);
  }
  return 0;
}