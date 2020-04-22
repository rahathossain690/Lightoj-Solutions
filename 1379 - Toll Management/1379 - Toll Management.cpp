#include<bits/stdc++.h>
using namespace std;
  typedef long long ll;
typedef pair<int, int> Pair;
  const int N = 10004;
ll inf = 10000000000000;
  vector<Pair> node[2][N];
vector< pair<Pair, int> > edge;
int n, m, u, v, w, p, s, t;
ll dist[2][N];
  void dijstra(int in, int src){
  priority_queue< Pair, vector<Pair>, greater<Pair> > q;
  q.push({0, src});
  dist[in][src] = 0;
  while(!q.empty()){
    u = q.top().second;
    q.pop();
    for(auto& v: node[in][u]){
      if(dist[in][v.first] > dist[in][u] + v.second){
        dist[in][v.first] = dist[in][u] + v.second;
        q.push({dist[in][v.first], v.first});
      }
    }
  }
}
  int solve(){
  scanf("%d %d %d %d %d", &n, &m, &s, &t, &p);
  for(int i = 1; i <= n; i++) node[0][i].clear(), node[1][i].clear(), dist[0][i] = dist[1][i] = inf;
  edge.clear();
  while(m--){
    scanf("%d %d %d", &u, &v, &w);
    node[0][u].push_back({v, w});
    node[1][v].push_back({u, w});
    edge.push_back({{u, v}, w});
  }
  dijstra(0, s);
  if(dist[0][t] == inf) return -1;
  dijstra(1, t);
  int ans = -1;
  for(auto& q : edge){
    u = q.first.first;
    v = q.first.second;
    w = q.second;
    if(dist[0][u] + w + dist[1][v] <= p + 0LL) ans = max(ans, w);
  }
  if(ans == -1 && s == t) ans = 0;
  return ans;
}
  int main(){ //freopen("in.txt", "w", stdout);
  int t = 1, tc;
  for(scanf("%d", &tc); t <= tc; printf("Case %d: %d\n", t++, solve()));
}