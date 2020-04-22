#include<bits/stdc++.h>
using namespace std;
  typedef long long       ll;
typedef pair<int, int>  Pair;
const int N = 30005;
  int t, tc, u, v, n, w, d_f[N], d_s[N];
vector<Pair> node[N];
  void dfs(int in, int sv[], int tot){
  if(sv[in] != -1) return;
  sv[in] = tot;
  for(int i = 0; i < node[in].size(); i++) {
    dfs(node[in][i].first, sv, tot + node[in][i].second);
  }
}
  int solve(){
  scanf("%d", &n);
  for(int i = 0; i < n; i++) node[i].clear();
  for(int i = 0; i < n - 1; i++){
    scanf("%d %d %d", &u, &v, &w);
    node[u].push_back(make_pair(v, w));
    node[v].push_back(make_pair(u, w));
  }
  memset(d_f, -1, sizeof d_f);
  dfs(0, d_f, 0);
  int maxVal = -1, maxInd = -1;
  for(int i = 0; i < n; i++){
    if(maxVal < d_f[i]) {
      maxVal = d_f[i];
      maxInd = i;
    }
  }
  memset(d_s, -1, sizeof d_s);
  dfs(maxInd, d_s, 0);
  maxVal =  maxInd = -1;
  for(int i = 0; i < n; i++){
    if(maxVal < d_s[i]){
      maxVal = d_s[i];
      maxInd = i;
    }
  }
  memset(d_f, -1, sizeof d_f);
  dfs(maxInd, d_f, 0);
  for(int i = 0; i < n; i++){
    printf("%d\n", max(d_s[i], d_f[i]));
  }
  return 0;
}
  int main(){
  for(scanf("%d", &tc); t < tc; printf("Case %d:\n", ++t), solve());
}