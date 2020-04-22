#include<bits/stdc++.h>
using namespace std;
  #define pb push_back
#define endl "\n"
#define ll long long
#define td(n) scanf("%d",&n)
  vector<int>node[1001];
int k,m,n,a,b,p[101],cnt[1001];
bool vis[1001];
  void dfs(int i, int l){
    vis[i] = 1;
    cnt[i] += 1;
    for(int j = 0;j < node[i].size(); j++)
        if(!vis[node[i][j]])dfs(node[i][j],l);
}
  int main(){
    int t=1,tc;
    for(td(tc);t<=tc;t++){
        int ans = 0;
        td(k),td(n),td(m);
        for(int i = 0;i < k; i++) td(p[i]);
        while(m--){
            td(a),td(b);
            node[a].pb(b);
        }
        for(int i=0;i<k;i++){
            memset(vis,0,sizeof(vis)),dfs(p[i],i);
        }
        for(int i = 1; i <= n; i++){
            if ( cnt[i] == k ) ans ++;
            cnt[i] = 0;
            node[i].clear();
        }
        printf("Case %d: %d\n",t,ans);
    }
}