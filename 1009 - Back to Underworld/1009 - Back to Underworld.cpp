#include <bits/stdc++.h>
using namespace std;
    #define td(n)       scanf("%d",&n)
#define tld(n)      scanf("%ld",&n)
#define tlld(n)     scanf("%lld",&n)
#define tllu(n)     scanf("%llu",&n)
#define tLine(n)    ("%[\n]%*c",n)
#define ts(n)       scanf("%s",n)
#define tlf(n)      scanf("%lf",&n)
#define ll          long long
#define ull         unsigned long long
#define LOJ         for(td(q),t=1;t<=q;t++)
#define CASE(n)     printf("Case %d: ",n)
#define OPEN        freopen("in.txt","r",stdin)
#define START       double cL = clock()
#define FINISH      printf("\n*****\nE = %lfs\n", (clock() - cL) / CLOCKS_PER_SEC);
    ull mod=10007;
ull gcd(ull a,ull b){return b==0?a:gcd(b,a%b);}
ull bigmod(ull num,ull n){if(n==0)return 1;ull x=bigmod(num,n/2);x=x*x%mod;if(n%2==1)x=x*num%mod;return x;}
ull modinverse(ull num){return bigmod(num,mod-2)%mod;}
    int solve(){
    int n,u,v,ans=0;
    set<int>s;
    queue<int>q;
    map<int,int>vis;
    set<int>::iterator it;
    vector<int> node[20010];
    td(n);
    for(int i=0;i<n;i++){
        td(u),td(v);
        s.insert(u),s.insert(v);
        node[u].push_back(v),node[v].push_back(u);
    }
    for(it=s.begin();it!=s.end();it++){
        if(vis[*it]==0){
            vis[*it]=1;
            u = *it;
            int a[2]={0,0};
            q.push(u);
            while(!q.empty()){
                v=q.front();
                q.pop();
                a[vis[v]-1]++;
                for(int i=0;i<node[v].size();i++){
                    if(vis[node[v][i]]==0)
                        vis[node[v][i]]=vis[v]==1?2:1,q.push(node[v][i]);
                }
            }
            ans+=max(a[0],a[1]);
        }
    }
    printf("%d\n",ans);
    return 0;
}
int main(){
    //START;
    //OPEN;
    int t,q;
    LOJ{
        CASE(t);
        solve();
    }
    //FINISH;
}