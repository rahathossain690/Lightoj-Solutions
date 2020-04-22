#include<bits/stdc++.h>
using namespace std;
/* THANKS TO RAHEEB */
typedef long long       ll;
typedef pair<int, int>  Pair;
const int N = 20005;
  int t, tc, u, v, n, m, comp[N], cur;
vector<int> node[N], top, ulta[N];
set<int> ind[N], out[N];
bool vis[N];
  void dfs_top(int in){
  if(vis[in]) return;
  vis[in] = 1;
  for(int i = 0; i < node[in].size(); i++) dfs_top(node[in][i]);
  top.push_back(in);
}
  void dfs(int in, int curComp){
  if(comp[in] != -1) return;
  comp[in] = curComp;
  for(int i = 0; i < ulta[in].size(); i++) dfs(ulta[in][i], curComp);
}
  void clear(){
  for(int i = 1; i <= n; i++) node[i].clear(), ulta[i].clear();
  memset(vis, 0, sizeof vis);
  top.clear();
  memset(comp, -1, sizeof comp);
  for(int i = 1; i <= cur; i++) ind[i].clear(), out[i].clear();
  cur = 0;
}
  int solve(){
  scanf("%d %d", &n, &m);
  clear();
  while(m--){
    scanf("%d %d", &u, &v);
    node[u].push_back(v);
    ulta[v].push_back(u);
  }
  for(int i = 1; i <= n; i++) dfs_top(i);
  for(int i = top.size() - 1; i >= 0; i--){
    if( comp[ top[i] ] == -1 ){
      cur++;
      dfs(top[i], cur);
    }
  }
  for(u = 1; u <= n; u++){
    for(int j = 0; j < node[u].size(); j++){
      v = node[u][j];
      if(comp[u] != comp[v]){
        out[ comp[u] ].insert( comp[v] );
        ind[ comp[v] ].insert( comp[u] );
      }
    }
  }
  if(cur == 1) return 0;
  int ans1 = 0, ans2 = 0;
  for(int i = 1; i <= cur; i++) ans1 += (ind[i].size() == 0), ans2 += (out[i].size() == 0);
  return max(ans1, ans2);
}
  int main(){
  for(scanf("%d", &tc); t < tc; printf("Case %d: %d\n", ++t, solve()));
}