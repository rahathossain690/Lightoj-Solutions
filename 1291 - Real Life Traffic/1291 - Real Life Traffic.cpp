#include<bits/stdc++.h>
using namespace std;
  const int N = 10002;
#define edge(P,Q) make_pair(min(Q,P),max(Q,P))
  int t, tc, tim, n, m, u, v, disc[N], low[N], cur, as[N], deg[N];
vector<int> node[N];
set< pair<int, int> > brg;
bool vis[N];
  void clear(){
  memset(vis, 0, sizeof vis);
  memset(as, -1, sizeof as);
  memset(deg, 0, sizeof deg);
  brg.clear();
  for(int i = 0; i < n; i++) node[i].clear();
  cur = tim = 0;
}
  void dfs_brg(int in, int par){
  disc[in] = low[in] = ++tim;
  for(int i = 0; i < node[in].size(); i++){
    if(!vis[ node[in][i] ]){
      vis[ node[in][i] ] = 1, dfs_brg( node[in][i], in );
      low[in] = min(low[in], low[ node[in][i] ]);
      if(low[in] < low[ node[in][i] ]) brg.insert( edge(in, node[in][i]) );
    }
    else if(node[in][i] != par) low[in] = min(low[in], disc[ node[in][i] ]);
  }
}
  void dfs_comp(int in, int cur){
  if(as[in] != -1) return;
  as[in] = cur;
  for(int i = 0; i < node[in].size(); i++) {
    if( brg.find( edge(in, node[in][i]) ) != brg.end() ) continue;
    dfs_comp(node[in][i], cur);
  }
}
  int solve(){
  clear();
  scanf("%d %d", &n, &m);
  while(m--){
    scanf("%d %d", &u, &v);
    node[u].push_back(v);
    node[v].push_back(u);
  }
  vis[0] = 1, dfs_brg(0, -1);
  for(int i = 0; i < n; i++) if(as[i] == -1) dfs_comp(i, ++cur);
  for(int i = 0; i < n; i++){
    for(int j = 0; j < node[i].size(); j++){
      if(as[i] == as[ node[i][j] ]) continue;
      deg[ as[i] ]++, deg[ as[ node[i][j] ] ]++;
    }
  }
  int ans = 0;
  for(int i = 1; i <= cur; i++) ans += (deg[i] == 2);
  return (ans + 1) / 2;
}
  int main(){
  for(scanf("%d", &tc); t < tc; printf("Case %d: %d\n", ++t, solve()));
}