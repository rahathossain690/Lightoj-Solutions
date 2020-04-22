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
#define CASE        printf("Case %d: ",t)
#define OPEN        freopen("in.txt","r",stdin)
#define START       double cL = clock()
#define FINISH      printf("\n*****\nE = %lfs\n", (clock() - cL) / CLOCKS_PER_SEC);
  ull base = 7, mod = 10000000007;
ull gcd(ull a,ull b){return b==0?a:gcd(b,a%b);}
ull bigmod(ull num,ull n){if(n==0)return 1;ull x=bigmod(num,n/2);x=x*x%mod;if(n%2==1)x=x*num%mod;return x;}
ull modinverse(ull num){return bigmod(num,mod-2)%mod;}
  string a,b;
int ans;
ull has,has2,BB,bL,aL;
char aa[1000010],bb[1000010];
int f[1000010];
  void prefix(){
    memset(f,0,sizeof(f));
    f[0]=0;
    for(int i=0,j=1;j<bL;j++){
        if(b[i]!=b[j])f[j]=0;
        else{
            while(b[i]==b[j] && j<bL){
                f[j]=i+1;
                i++,j++;
            }
            if(j==bL)return;
            else j--,i=0;
        }
    }
}
  void KMP(){
    aL = (int)a.size(),bL=(int)b.size();
    prefix();
    for(int i=0,j=0;i<aL;i++){
        if(a[i]!=b[j]&&j==0)j=0;
        else if(a[i]!=b[j])j=f[j-1],i--;
        else{
            j++;
            if(j==bL)ans++,j=f[j-1];
        }
    }
}
int main(){ //START;
    //OPEN;
    LOJ{
        CASE;
        ts(aa),ts(bb);
        a=aa,b=bb,ans=0;
        KMP();
        printf("%d\n",ans);
    }
    //FINISH;
    return 0;
}