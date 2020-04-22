#include<bits/stdc++.h>
using namespace std;
  using ll = long long;
using Pair = pair<int, ll>;
  #define endl '\n'
  const int N = 201;
const ll inf = 100000000000000000;
  vector< pair< pair<int, int>, ll> > edge;
bool vis[N];
int n, m, q, u, v, b[N], t, tc;
ll dist[N], w;
  void bellmenford(int s){
  memset(vis, 0, sizeof vis);
  memset(dist, 0, sizeof dist);
  vis[s] = 1;
  for(int i = 1; i < n; i++){
    for(auto& p : edge){
      u = p.first.first;
      v = p.first.second;
      w = p.second;
      if(vis[u] and !vis[v]){
        vis[v] = 1;
        dist[v] = dist[u] + w;
      }
      else if(vis[u] and vis[v] and dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
      }
    }
  }
  edge.clear();
}
  int main(){ //freopen("in.txt", "w", stdout);
  for(scanf("%d", &tc); t < tc; t++){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", b + i);
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
      scanf("%d %d", &u, &v);
      edge.push_back({{u, v}, (b[v] - b[u]) * 1LL * (b[v] - b[u]) * 1LL * (b[v] - b[u])});
    }
    bellmenford(1);
    printf("Case %d:\n", t + 1);
    scanf("%d", &q);
    while(q--){
      scanf("%d", &u);
      if(dist[u] < 3) vis[u] = false;
      if(vis[u]) printf("%lld\n", dist[u]);
      else puts("?");
    }
  }
}