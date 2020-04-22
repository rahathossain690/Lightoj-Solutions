#include "bits/stdc++.h"
using namespace std;
  typedef long long ll;
typedef pair<int, int> pii;
#define pb          push_back
#define endl        "\n"
#define mp          make_pair
#define min(a,b)    (a<b?a:b)
#define max(a,b)    (a>b?a:b)
const int sz = 505, inf = 1<<29;
  vector<pii> node[sz];
priority_queue< pii > q;
int u, v, w, w1, m, n, t = 1, tc, s, minAns[sz];
  int main(){
  for(scanf("%d", &tc); t <= tc; t++){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
      minAns[i] = inf;
      node[i].clear();
    }
    for(int i = 0; i < m; i++) {
      scanf("%d %d %d", &u, &v, &w);
      node[u].pb( mp(v, w) );
      node[v].pb( mp(u, w) );
    }
    scanf("%d", &s);
    minAns[s] = 0;
    q.push( mp( 0, s ) );
    while( !q.empty() ){
      u = q.top().second;
      w = q.top().first;
      q.pop();
      for(int i = 0; i < node[u].size(); i++){
        v = node[u][i].first;
        w1 = node[u][i].second;
        if( minAns[v] > max( minAns[u], w1)){
          minAns[v] = max(minAns[u], w1);
          q.push( mp( minAns[v], v) );
        }
      }
    }
    printf("Case %d:\n", t);
    for(int i = 0; i < n; i++){
      if(minAns[i] != inf)printf("%d\n", minAns[i]);
      else puts("Impossible");
    }
  }
}