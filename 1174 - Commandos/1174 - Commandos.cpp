#include<bits/stdc++.h>
using namespace std;
#define td(n) scanf("%d",&n)
    int solve(){
    int n,r,u,v,s,d;
    td(n),td(r);
    vector<int>node[n];
    queue<int>q;
    int ans1[n],ans2[n],store = -1;
    for(int i=0;i<n;i++)ans1[i]=-1,ans2[i]=-1;
    for(int i=0;i<r;i++){
        td(u),td(v);
        if(u==v)continue;
        node[u].push_back(v);
        node[v].push_back(u);
    }
    td(s),td(d);
    q.push(s);
    ans1[s]=0;
    while(!q.empty()){
        u = q.front();
        q.pop();
        v = ans1[u];
        for(int i=0;i<node[u].size();i++){
            if(ans1[node[u][i]]==-1){
                ans1[node[u][i]]=1+v;
                q.push(node[u][i]);
            }
        }
    }
    ans2[d]=0;
    q.push(d);
    while(!q.empty()){
        u = q.front();
        q.pop();
        v = ans2[u];
        for(int i=0;i<node[u].size();i++){
            if(ans2[node[u][i]]==-1){
                ans2[node[u][i]]=1+v;
                q.push(node[u][i]);
            }
        }
    }
    for(int i=0;i<n;i++)store<ans1[i]+ans2[i]?store=ans1[i]+ans2[i]:0;
    printf("%d\n",store);
    return 0;
}
  int main(){
    int t,q;
    for(td(q),t=1;t<=q;t++){
        printf("Case %d: ",t);
        solve();
    }
}