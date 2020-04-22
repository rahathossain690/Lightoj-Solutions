#include <bits/stdc++.h>
using namespace std;
  typedef long long ll;
typedef pair<int, int> pii;
#define pb          push_back
#define endl        "\n"
#define mp          make_pair
#define min(a,b)    (a<b?a:b)
#define max(a,b)    (a>b?a:b)
const int sz = 1005;
  int n, m, u, v, t = 1, tc, mon[sz], tot, mean;
vector<int> node[sz];
bool vis[sz], yes;
pii lol;
  pii dfs(int in){
  vis[in] = 1;
  int ans = mon[in], p, cur = 1;
  pii temp;
  for(int i = 0; i < node[in].size(); i++){
    if(!vis[ node[in][i] ]){
      temp = dfs( node[in][i] );
      ans += temp.first;
      cur += temp.second;
    }
  }
  return mp(ans, cur);
}
  int main(){
  for(scanf("%d", &tc); t <= tc; t++){
    scanf("%d %d", &n, &m);
    yes = true, tot = 0;
    for(int i = 1; i <= n; i++) scanf("%d", mon + i), tot += mon[i];
    for(int i = 0; i < m; i++){
      scanf("%d %d", &u, &v);
      node[u].pb(v);
      node[v].pb(u);
    }
    mean = tot / n;
    if(tot % n != 0) {
      yes = false;
      goto SHESH;
    }
    memset(vis, 0, sizeof vis);
    for(int i = 1; i <= n; i++){
      if(!vis[i]){
        lol = dfs(i);
        if(lol.first / lol.second != mean) yes = false;
      }
    }
    SHESH:
    printf("Case %d: ", t);
    if(yes)puts("Yes");
    else puts("No");
    for(int i = 1; i <= n; i++) node[i].clear();
  }
    return 0;
}