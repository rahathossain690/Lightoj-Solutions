#include "bits/stdc++.h"
using namespace std;
  typedef long long ll;
typedef pair<int, int> pii;
#define pb          push_back
#define endl        "\n"
#define mp          make_pair
#define min(a,b)    (a<b?a:b)
#define max(a,b)    (a>b?a:b)
const int sz =10010;
  struct P{
  int in, out, i;
};
  vector<int> node[sz];
bool vis[sz];
int n, m, t = 1, tc, u, v, ans;
stack <int> top;
  void dfs(int in, bool k){
  if(vis[in]) return;
  vis[in] = 1;
  for(int i = 0; i < node[in].size(); i++)
    if(!vis[ node[in][i] ]) dfs( node[in][i] , k );
  if(k) top.push(in);
}
    int main(){ //freopen("out.txt", "w", stdout);
  for(scanf("%d", &tc); t <= tc; t++){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) {
      scanf("%d %d", &u, &v);
      node[u].pb(v);
    }
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= n; i++) dfs(i, 1);
    ans = 0;
    memset(vis, 0, sizeof(vis));
    while(!top.empty()){
      if(!vis[ top.top() ]) ans++, dfs(top.top(), 0);
      top.pop();
    }
    for(int i = 1; i <= n; i++) node[i].clear();
    printf("Case %d: %d\n", t, ans);
  }
    return 0;
}