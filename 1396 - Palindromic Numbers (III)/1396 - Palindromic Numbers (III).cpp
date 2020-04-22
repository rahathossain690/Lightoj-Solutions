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
#define LOJ         int t,q;for(td(q),t=1;t<=q;t++)
#define CASE        printf("Case %d: ",t)
#define OPEN        freopen("in.txt","r",stdin)
#define START       double cL = clock()
#define FINISH      printf("E = %lfs\n", (clock() - cL) / CLOCKS_PER_SEC);
    ull mod=10007;
ull gcd(ull a,ull b){return b==0?a:gcd(b,a%b);}
ull bigmod(ull num,ull n){if(n==0)return 1;ull x=bigmod(num,n/2);x=x*x%mod;if(n%2==1)x=x*num%mod;return x;}
ull modinverse(ull num){return bigmod(num,mod-2)%mod;}
    int main(){ //START;OPEN;
    char a[100010];
    LOJ{
        CASE;
        ts(a);
        int f = 0;
        int l = strlen(a);
        for(int i=(l-1)/ 2;i>=0;i--){
            if(a[i]>a[l-i-1]){
                f=-1;
                break;
            }
            else if(a[i]<a[l-i-1]){
                f=1;
                break;
            }
        }
        if(f==0||f==1){
            int c = 0;
            a[(l-1)/2]++;
            if(a[(l-1)/2]>'9')c=1,a[(l-1)/2]='0';
            for(int i = (l-1)/2 -1;i>=0&&c==1;i--){
                a[i] += c;
                if(a[i]>'9')c=1,a[i]='0';
                else c=0;
            }
            if(c==1){
                printf("1");
                for(int i=0;i<l-1;i++)printf("0");
                printf("1");
            }
            else{
                for(int i=0;i<=(l-1)/2;i++)printf("%c",a[i]);
                for(int i=l&1?-1+(l-1)/2:-1+l/2;i>=0;i--)printf("%c",a[i]);
            }
        }else {
            for(int i=(l-1)/2;i>=0;i--)a[l-i-1]=a[i];
            printf("%s",a);
        }
        puts("");
    } //FINISH;
    return 0;
}