#include<bits/stdc++.h>
using namespace std;
  const int N = 5002, inf = 1 << 29;
  typedef pair<int, int> Pair;
  int dist[2][N], n, m, u, v, t, tc, w;
vector<Pair> node[N];
  int dijstra(int s, int t){
  for(int i = 1; i <= n; i++) dist[0][i] = dist[1][i] = inf;
  dist[0][s] = 0;
  priority_queue < Pair, vector<Pair>, greater<Pair> > q;
  q.push({0, s});
  while(!q.empty()){
    Pair tmp = q.top();
    q.pop();
    u = tmp.second; //cout << tmp.first << " " << tmp.second << endl;
    for(int i = 0; i < node[u].size(); i++){
      v = node[u][i].first;
      w = node[u][i].second;
      if(dist[1][v] > tmp.first + w){
        if(dist[0][v] == tmp.first + w) continue;
        q.push({tmp.first + w, v});
        if(dist[0][v] > tmp.first + w){
          dist[1][v] = dist[0][v];
          dist[0][v] = tmp.first + w;
        }
        else dist[1][v] = tmp.first + w;
      }
    }
  }
  return dist[1][t];
}
  int main(){
  for(scanf("%d", &tc); t < tc; t++){
    scanf("%d %d", &n, &m);
    while(m--){
      scanf("%d %d %d", &u, &v, &w);
      node[u].push_back({v, w});
      node[v].push_back({u, w});
    }
    printf("Case %d: %d\n", t + 1, dijstra(1, n));
    for(int i = 1; i <= n; i++) node[i].clear();
  }
}