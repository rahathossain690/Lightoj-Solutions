#include <bits/stdc++.h>
using namespace std;
#define td(n) scanf("%d",&n)
#define tld(n) scanf("%ld",&n)
#define tlld(n) scanf("%lld",&n)
#define tllu(n) scanf("%llu",&n)
#define tLine(n) scanf("%[\n]%*c",n)
#define ts(n) scanf("%s",n)
#define tlf(n) scanf("%lf",&n)
#define ll long long
#define ull unsigned long long
#define For(i,n) for(int i=0;i<n;i++)
#define Fre(i,a,b) for(int i = a; i < b; i++)
#define Frev(i,a,b) for(int i = a; i > b; i--)
#define CASE(n) printf("Case %d: ",n)
ull mod=10007;
ull gcd(ull a,ull b){return b==0?a:gcd(b,a%b);}
ull bigmod(ull num,ull n){if(n==0)return 1;ull x=bigmod(num,n/2);x=x*x%mod;if(n%2==1)x=x*num%mod;return x;}
ull modinverse(ull num){return bigmod(num,mod-2)%mod;}
  int n,k,q,t;
ull a,b;
int main(){//freopen("in.txt","r",stdin);
    for(t=1,td(q);t<=q;t++){
        CASE(t);
        td(n),td(k);
        if(n<k)printf("0\n");
        else {
            a=1;
            for(int i=1;i<=k;i++,n--){
                a*=n*n;
                a/=i;
            }
            printf("%llu\n",a);
        }
    }
    return 0;
}