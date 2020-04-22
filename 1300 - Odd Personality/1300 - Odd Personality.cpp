#include<bits/stdc++.h>
using namespace std;
  // A M A R   A L L A H   N O B I J I R   N A A M   : )
  #define edge(pp, qq)  make_pair( min(pp, qq), max(pp, qq) )
const int N = 10002;
  int n, m, t, tc, u, v, disc[N], low[N], tim, col[N], ans;
vector<int> node[N];
bool vis[N];
set< pair<int, int> > brg;
  void clear(){
  memset(vis, 0, sizeof vis);
  for(int i = 0; i < n; i++) node[i].clear();
  tim = 0;
  memset(col, -1, sizeof col);
  ans = 0;
  brg.clear();
}
  void dfs(int in, int par){
  disc[in] = low[in] = ++tim;
  for(int i = 0; i < node[in].size(); i++){
    int u = node[in][i];
    if (!vis[u]){
      vis[u] = 1;
      dfs(u, in);
      low[in] = min(low[u], low[in]);
      if(low[u] > disc[in]) brg.insert( edge(u, in) );
    }
    else if(u != par) low[in] = min(low[in], disc[u]);
  }
}
  int dfs_comp(int in){
  if(vis[in]) return 0;
  vis[in] = 1;
  int ans = 1;
  for(int i = 0; i < node[in].size(); i++){
    int u = node[in][i];
    if( brg.find( edge(in, u) ) != brg.end() ) continue;
    ans += dfs_comp(u);
  }
  return ans;
}
  int bfs(int in){
  queue<int> q;
  col[in] = 1;
  q.push(in);
  bool hobe = true;
  while(!q.empty()){
    int u = q.front();
    q.pop();
    for(int i = 0; i < node[u].size(); i++){
      int v = node[u][i];
      if( brg.find( edge(u, v) ) != brg.end() ) continue;
      if(col[v] == -1) col[v] = 1 - col[u], q.push(v);
      else if(col[v] == col[u]) hobe = false;
    }
  }
  return hobe ? 0 : dfs_comp(in);
}
  int solve(){
  clear();
  scanf("%d %d", &n, &m);
  while(m--){
    scanf("%d %d", &u, &v);
    node[u].push_back(v);
    node[v].push_back(u);
  }
  for(int i = 0; i < n; i++) if(!vis[i]) vis[i] = 1, dfs(i, -1);
  memset(vis, 0, sizeof vis);
  for(int i = 0; i < n; i++) if(col[i] == -1) ans += bfs(i);
  return ans;
}
  int main(){
  for(scanf("%d", &tc); t < tc; printf("Case %d: %d\n", ++t, solve()));
}