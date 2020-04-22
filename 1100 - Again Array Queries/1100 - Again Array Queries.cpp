#include<bits/stdc++.h>
using namespace std;
  typedef pair<int, int> Pair;
const int N = 10002, inf = 1000000000;
  int t, tc, n, a, q, f, s;
vector<int> node[N];
  int COUNT(int in, int f, int s){
  return upper_bound(node[in].begin(), node[in].end(), s) - lower_bound(node[in].begin(), node[in].end(), f);
}
  int solve(){
  scanf("%d %d", &n, &q);
  for(int i = 0; i < N; i++) node[i].clear();
  for(int i = 0; i < n; i++){
    scanf("%d", &a);
    node[a].push_back(i);
  }
  while(q--){
    int pre = -1, ans = inf;
    scanf("%d %d", &f, &s);
    for(int i = 0; i < N; i++){
      int k = COUNT(i, f, s);
      if(k > 1){
        ans = 0;
        break;
      }
      if(k){
        if(pre == -1){
          pre = i;
          continue;
        }
        ans = min(ans, i - pre);
        pre = i;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
  int main(){
  for(scanf("%d", &tc); t < tc; printf("Case %d:\n", ++t), solve());
}