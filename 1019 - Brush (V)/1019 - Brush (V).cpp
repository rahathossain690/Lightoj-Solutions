#include<bits/stdc++.h>
using namespace std;
#define td(n) scanf("%d",&n)
const int inf = 99999999;
void solve(){
    int n,m;
    td(n),td(m);
    vector<pair<int,int> >node[n];
    vector<pair<int,int> >::iterator it;
    int ans[n];
    bool vis[n];
    for(int i=0;i<n;i++)ans[i]=inf,vis[i]=0;
    for(int i=0;i<m;i++){
        int u,v,w;
        td(u),td(v),td(w);
        node[u-1].push_back(make_pair(v-1,w));
        node[v-1].push_back(make_pair(u-1,w));
    }
    ans[0]=0;
    for(int i=0;i<n;i++){
        int m=inf,p=-1;
        for(int j=0;j<n;j++){
            if(m>ans[j]&&vis[j]==0)m=ans[j],p=j;
        }
        if(p==-1)break;
        vis[p]=1;
        for(it=node[p].begin();it!=node[p].end();it++){
            if(m + (*it).second < ans[(*it).first])ans[(*it).first]=m + (*it).second;
        }
    }
    //for(int i=0;i<n;i++)cout<<ans[i]<<" ";
    ans[n-1]==inf?printf("Impossible\n"):printf("%d\n",ans[n-1]);
}
int main(){ //freopen("in.txt","r",stdin);
    int t,q;
    for(scanf("%d",&q),t=1;t<=q;t++)printf("Case %d: ",t),solve();
    return 0;
}