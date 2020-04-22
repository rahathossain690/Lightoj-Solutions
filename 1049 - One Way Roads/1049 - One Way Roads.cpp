#include<bits/stdc++.h>
using namespace std                                                                 ;
  typedef pair<int, int> Pair                                                         ;
const int N = 105, inf = 100000000                                                  ;
  int t, tc, n, u, v, w                                                               ;
vector<Pair> node[N]                                                                ;
  int dfs(int in, int par)                                                            {
  if(in == 1)
    return 0                                                                        ;
  int ans = 0                                                                       ;
  for(int i = 0; i < node[in].size(); i++)                                          {
    if(node[in][i].first == par)
      continue                                                                      ;
    ans = node[in][i].second + dfs(node[in][i].first, in)                           ;}
  return ans                                                                        ;
                                                                                    }
  int solve()                                                                         {
  for(int i = 1; i <= n; i++) node[i].clear()                                       ;
  scanf("%d", &n)                                                                   ;
  for(int i = 0; i < n; i++)                                                        {
    scanf("%d %d %d", &u, &v, &w)                                                   ;
    node[u].push_back( make_pair(v, 0) )                                            ;
    node[v].push_back( make_pair(u, w) )                                            ;}
  int ans = inf                                                                     ;
  for(int i = 0; i < node[1].size(); i++)                                           {
    ans = min( node[1][i].second + dfs( node[1][i].first, 1 ), ans )                ;}
  return ans                                                                        ;
                                                                                    }
  int main()                                                                          {
  for(scanf("%d", &tc); t < tc; printf("Case %d: %d\n", ++t, solve()))              ;
                                                                                    }