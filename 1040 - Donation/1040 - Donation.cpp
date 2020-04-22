#include<bits/stdc++.h>
using namespace std;
  typedef pair<int, int> Pair;
const int N = 52, inf = 1000000000;
  int t, tc, a, u, v, w, n;
vector<int> node[N];
int dis[N];
bool vis[N];
  int dFind(int u){
  if(dis[u] < 0) return u;
  return dFind(dis[u]);
}
  void dUnion(int f, int s){
  if(dis[f] <= dis[s]){ // f has more child than s
    dis[f] += dis[s];
    dis[s] = f;
  }
  else {
    dis[s] += dis[f];
    dis[f] = s;
  }
}
  void dfs(int in){
  if(vis[in]) return;
  vis[in] = 1;
  for(int i = 0; i < node[in].size(); i++) dfs(node[in][i]);
}
  int solve(){
  int ans = 0, tot = 0;
  for(int i = 0; i < n; i++) node[i].clear();
  scanf("%d", &n);
  memset(dis, -1, sizeof dis);
  priority_queue< pair<int, Pair>, vector< pair<int, Pair> >, greater< pair<int, Pair> > > q;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      scanf("%d", &w);
      tot += w;
      if(i == j) continue;
      else if(w) q.push( make_pair( w, make_pair(i, j) ) );
    }
  }
  while(!q.empty()){
    pair<int, Pair> temp = q.top();
    q.pop();
    u = temp.second.first;
    v = temp.second.second;
    w = temp.first;
    int f = dFind(u), s = dFind(v);
    if(f == s) continue;
    node[u].push_back(v);
    node[v].push_back(u);
    dUnion(f, s);
    ans += w;
  }
  memset(vis, 0, sizeof vis);
  dfs(0);
  for(int i = 0; i < n; i++) if(!vis[i]) return -1;
  return tot - ans;
}
  int main(){
  for(scanf("%d", &tc); t < tc; printf("Case %d: %d\n", ++t, solve()));
}