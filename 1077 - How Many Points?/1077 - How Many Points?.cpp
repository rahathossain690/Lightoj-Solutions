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
#define LOJ         int qqq,ttt;for(td(qqq),ttt=1;ttt<=qqq;ttt++)
#define CASE        printf("Case %d: ",ttt)
#define OPEN        freopen("in.txt","r",stdin)
#define START       double cL = clock()
#define FINISH      printf("E = %lfs\n", (clock() - cL) / CLOCKS_PER_SEC);
    ull mod=10007;
ull gcd(ull a,ull b){return b==0?a:gcd(b,a%b);}
ull bigmod(ull num,ull n){if(n==0)return 1;ull x=bigmod(num,n/2);x=x*x%mod;if(n%2==1)x=x*num%mod;return x;}
ull modinverse(ull num){return bigmod(num,mod-2)%mod;}
ll abs(ll a,ll b){return a>b?a-b:b-a;}
  int main(){       //START;OPEN;
    LOJ{
        CASE;
        ll x[2],y[2];
        tlld(x[0]),tlld(y[0]),tlld(x[1]),tlld(y[1]);
        if(x[0]==x[1]&&y[0]==y[1]){
            puts("1");
            continue;
        }
        if(x[0]==x[1]){
            printf("%lld\n",abs(y[0]-y[1])+1);
            continue;
        }
        if(y[0]==y[1]){
            printf("%lld\n",abs(x[0]-x[1])+1);
            continue;
        }
        ll dev = gcd(abs(x[0]-x[1]),abs(y[0],y[1]));
        ll dx = abs(x[0]-x[1])/dev;
        printf("%lld\n",1+abs(x[0]-x[1])/dx);
    }
                  //FINISH;
    return 0;
}