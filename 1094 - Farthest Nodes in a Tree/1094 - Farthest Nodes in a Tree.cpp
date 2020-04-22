#include "bits/stdc++.h"
using namespace std;
  #define td(n) scanf("%d",&n)
  vector<pair<int,int> >node[30001];
int n,a,b,w;
int ans[30001];
bool vis[30001];
  void dfs(int i){
  vector<pair<int,int> >::iterator it;
  vis[i] = 1;
  for(it = node[i].begin(); it != node[i].end(); it++){
    int aa = it->first,bb = it->second;
    if(!vis[aa]) ans[aa] = ans[i] + bb,dfs(aa);
  }
}
  int main(){
  int t=1,tc;
  for(td(tc);t<=tc;t++){
    td(n);
    for(int i = 0; i < n-1; i++){
      td(a),td(b),td(w);
      node[a].push_back(make_pair(b,w));
      node[b].push_back(make_pair(a,w));
    }
    vis[0] = 1;
    dfs(0);
    int h = -1, index = -1;
    for(int i = 0; i < n; i++){
      if(h < ans[i]) h = ans[i],index = i;
      ans[i] = 0;
      vis[i] = 0;
    }
    vis[index] = 1;
    dfs(index);
    h = -1;
    for(int i = 0; i < n; i++){
      if(h < ans[i]) h = ans[i];
      node[i].clear();
      ans[i] = 0;
      vis[i] = 0;
    }
    printf("Case %d: %d\n",t,h);
  }
}