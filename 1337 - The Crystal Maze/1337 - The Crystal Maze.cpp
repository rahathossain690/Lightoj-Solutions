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
#define LOJ         int qq,t;for(td(qq),t=1;t<=qq;t++)
#define CASE        printf("Case %d:",t)
#define OPEN        freopen("in.txt","r",stdin)
#define START       double cL = clock()
#define FINISH      printf("\n*****\nE = %lfs\n", (clock() - cL) / CLOCKS_PER_SEC);
    ull mod=10007;
ull gcd(ull a,ull b){return b==0?a:gcd(b,a%b);}
ull bigmod(ull num,ull n){if(n==0)return 1;ull x=bigmod(num,n/2);x=x*x%mod;if(n%2==1)x=x*num%mod;return x;}
ull modinverse(ull num){return bigmod(num,mod-2)%mod;}
  char a[510][510];
int m,n,q,x,y,c,rig[510][510],area;
void dfs(int i,int j){
    if(0<=i&&i<m&&0<=j&&j<n){
        if(a[i][j]=='#')return;
        if(a[i][j]=='C')c++;
        a[i][j]='#';
        rig[i][j]=area;
        dfs(i+1,j);
        dfs(i-1,j);
        dfs(i,j+1);
        dfs(i,j-1);
    }
}
int main(){ //START;OPEN;
    LOJ{
        CASE;
        puts("");
        td(m),td(n),td(q);
        area=0;
        for(int i=0;i<m;i++)for(int j=0;j<n;j++)rig[i][j]=0;
        map<int,int>ans;
        for(int i=0;i<m;i++)ts(a[i]);
        for(int i=0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(a[i][j]!='#'){
                    c=0;
                    dfs(i,j);
                    ans[area] = c;
                    area++;
                }
            }
        }
                for(int i=0;i<q;i++){
            td(x),td(y);
            printf("%d\n",ans[rig[x-1][y-1]]);
        }
    }
    //FINISH;
    return 0;
}