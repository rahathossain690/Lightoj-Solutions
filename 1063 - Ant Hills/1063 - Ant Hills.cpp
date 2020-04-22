#include<bits/stdc++.h>
using namespace std;
  const int N = 10005;
  int n, m, u, v, disc[N], low[N], t, tt, tc;
vector<int> node[N];
bool vis[N], ap[N];
  void clear(){
  t = 0;
  memset(vis, 0, sizeof vis);
  memset(ap, 0, sizeof ap);
  for(int i = 1; i <= n; i++) node[i].clear();
}
  void dfs(int in, int par){
  disc[in] = low[in] = ++t;
  for(int i = 0; i < node[in].size(); i++){
    if(!vis[node[in][i]]){
      vis[ node[in][i] ] = 1;
      dfs(node[in][i], in);
      low[in] = min( low[in], low[ node[in][i] ] );
      if(par == 0 && i >= 1) ap[in] = 1;
      if(low[ node[in][i] ] >= disc[in] && par != 0) ap[in] = 1;
    }
    else if(par != node[in][i]) low[in] = min(low[in], disc[ node[in][i] ]);
  }
}
  int solve(){
  scanf("%d %d", &n, &m);
  clear();
  while(m--){
    scanf("%d %d", &u, &v);
    node[u].push_back(v);
    node[v].push_back(u);
  }
  vis[1] = 1;
  dfs(1, 0);
  int ans = 0;
  for(int i = 1; i <= n; i++) ans += ap[i];
  return ans;
}
  int main(){
  for(scanf("%d", &tc); tt < tc; printf("Case %d: %d\n", ++tt, solve()));
}