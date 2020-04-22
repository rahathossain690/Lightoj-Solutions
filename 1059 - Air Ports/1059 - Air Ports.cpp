#include<bits/stdc++.h>
using namespace std;
  typedef pair<int, pair<int, int> > Pair;
const int N = 10002;
  int t, tc, n, m, u, v, w, a, dis[N];
  int dFind(int u){
  return dis[u] < 0 ? u : dFind(dis[u]);
}
  void dUnion(int f, int s){
  if(dis[f] <= dis[s]){
    dis[f] += dis[s];
    dis[s] = f;
  }
  else {
    dis[s] += dis[f];
    dis[f] = s;
  }
}
  int solve(){
  scanf("%d %d %d", &n, &m, &a);
  priority_queue <Pair, vector <Pair>, greater <Pair> > q;
  while(m--){
    scanf("%d %d %d", &u, &v, &w);
    q.push( make_pair( w, make_pair( u, v ) ) );
  }
  int mon = a * n, port = n, cur = 0, root = n;
  memset(dis, -1, sizeof dis);
  while(!q.empty()){
    u = q.top().second.first;
    v = q.top().second.second;
    w = q.top().first;
    q.pop();
    int f = dFind(u), s = dFind(v);
    if(f == s) continue;
    dUnion(f, s);
    root--;
    cur += w;
    if(cur + root * a < mon){
      mon = cur + root * a;
      port = root;
    }
  }
  printf("%d %d\n", mon, port);
  return 0;
}
  int main(){
  for(scanf("%d", &tc); t < tc; printf("Case %d: ", ++t), solve());
}