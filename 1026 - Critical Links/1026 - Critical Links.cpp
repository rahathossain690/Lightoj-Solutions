#include<bits/stdc++.h>
using namespace std;
  const int N = 10005;
  int n, m, u, v, disc[N], low[N], t, tt, tc;
vector<int> node[N];
set< pair<int, int> > brg;
set< pair<int, int> > :: iterator it;
bool vis[N];
  void clear(){
  t = 0;
  memset(vis, 0, sizeof vis);
  brg.clear();
  for(int i = 0; i < n; i++) node[i].clear();
}
  void dfs(int in, int par){
  disc[in] = low[in] = ++t;
  for(int i = 0; i < node[in].size(); i++){
    if(!vis[node[in][i]]){
      vis[ node[in][i] ] = 1;
      dfs(node[in][i], in);
      low[in] = min( low[in], low[ node[in][i] ] );
      if(low[ node[in][i] ] > disc[in]) brg.insert( make_pair( min( node[in][i], in ), max( node[in][i], in ) ) );
    }
    else if(par != node[in][i]) low[in] = min(low[in], disc[ node[in][i] ]);
  }
}
  int solve(){
  scanf("%d", &n);
  clear();
  for(int i = 0; i < n; i++){
    scanf("%d (%d)", &u, &m);
    while(m--){
      scanf("%d", &v);
      node[u].push_back(v);
      node[v].push_back(u);
    }
  }
  for(int i = 0; i < n; i++)if(!vis[i]) dfs(i, -1);
  printf("%d critical links\n", brg.size());
  for(it = brg.begin(); it != brg.end(); it++) printf("%d - %d\n", it->first, it->second);
  return 0;
}
  int main(){
  for(scanf("%d", &tc); tt < tc; printf("Case %d:\n", ++tt), solve());
}