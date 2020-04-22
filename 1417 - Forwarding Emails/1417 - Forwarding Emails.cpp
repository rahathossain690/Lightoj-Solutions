#include<bits/stdc++.h>
using namespace std;
  /*
O H !   G O D !
*/
  typedef long long       ll;
typedef pair<int, int>  Pair;
const int N = 50005, inf = 1<<30;
  int t, tc, u, v, n, m, cur, comp[N], dp[N];
vector<int> node[N], ulta[N], top, Gtop, G[N];
Pair info[N];
bool vis[N];
  void clear(){
  for(int i = 1; i <= n; i++) node[i].clear(), ulta[i].clear();
  top.clear();
  Gtop.clear();
  memset(vis, 0, sizeof vis);
  memset(comp, -1, sizeof comp);
  for(int i = 1; i <= cur; i++) G[i].clear();
  cur = 0;
}
  void dfs_top(int in){
  if(vis[in]) return ;
  vis[in] = 1;
  for(int i = 0; i < node[in].size(); i++) dfs_top(node[in][i]);
  top.push_back(in);
}
  Pair dfs_deep(int in, int curComp){
  if(comp[in] != -1) return make_pair(inf, 0);
  int f = in, s = 1;
  comp[in] = curComp;
  for(int i = 0; i < ulta[in].size(); i++){
    Pair qq = dfs_deep(ulta[in][i], curComp);
    f = min(f, qq.first);
    s += qq.second;
  }
  return make_pair(f, s);
}
  void tsort(int in){
  if(vis[in]) return;
  vis[in] = 1;
  for(int i = 0; i < G[in].size(); i++){
    tsort(G[in][i]);
  }
  Gtop.push_back(in);
}
  int dfs_fin(int in){
  if(vis[in]) return dp[in];
  vis[in] = 1;
  int ans = info[in].second, temp = 0;
  for(int i = 0; i < G[in].size(); i++){
    temp = max( dfs_fin(G[in][i]), temp );
  }
  return dp[in] = ans + temp;
}
  int solve(){
  scanf("%d", &n);
  m = n;
  clear();
  while(m--){
    scanf("%d %d", &u, &v);
    node[u].push_back(v);
    ulta[v].push_back(u);
  }
  for(int i = n; i >= 1; i--) if(!vis[i]) dfs_top(i);
  for(int i = top.size() - 1; i >= 0; i--){
    if(comp[ top[i] ] == -1){
      cur++;
      info[cur] = dfs_deep( top[i], cur );
    }
  }
  if(cur == 1) return 1;
  for(int u = 1; u <= n; u++){
    for(int j = 0; j < node[u].size(); j++){
      v = node[u][j];
      if( comp[u] != comp[v]){
        G[ comp[u] ].push_back( comp[v] );
      }
    }
  }
  memset(vis, 0, sizeof vis);
  for(int i = 1; i <= cur; i++) if(!vis[i]) tsort(i);
  int ans = -1, ind = -1;
  memset(vis, 0, sizeof vis);
  for(int i = Gtop.size() - 1; i >= 0; i--){
    if(!vis[ Gtop[i] ]){
      int temp = dfs_fin(Gtop[i]);
      if(temp >= ans){
        ans = temp;
        ind = i;
      }
      if(temp == ans){
        if(info[ Gtop[ind] ].first > info[ Gtop[i] ].first ) ind = i;
      }
    }
  }
  return info[ Gtop[ind] ].first;
}
  int main(){
  for(scanf("%d", &tc); t < tc; printf("Case %d: %d\n", ++t, solve()));
}