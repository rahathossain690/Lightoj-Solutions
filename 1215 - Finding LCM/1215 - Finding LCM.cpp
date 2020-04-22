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
ull power(ull a,ull b){ull ans=1;while(b--)ans*=a;return ans;}
int main(){
    //freopen("in.txt","r",stdin);
    int t,q;
    td(t);
    q=t;
    while(t--){
        CASE(q-t);
        ull a,b,l;
        tllu(a),tllu(b),tllu(l);
        if(l%a!=0||l%b!=0){
            puts("impossible");
            continue;
        }
        map<ull,ull>nl,nk;
        map<ull,ull>::iterator it;
        ull k = a*b / gcd(a,b);
        {
            ull temp = k;
            if(temp%2==0){
                ull tot=0;
                while(temp%2==0)temp/=2,tot++;
                nk[2]=tot;
            }
            for(ull gun = 3;gun*gun<=temp;gun+=2){
                if(temp%gun==0){
                    ull tot=0;
                    while(temp%gun==0)temp/=gun,tot++;
                    nk[gun]=tot;
                }
            }
            if(temp!=1)nk[temp] = 1;
        }
        {
            ull temp = l;
            if(temp%2==0){
                ull tot=0;
                while(temp%2==0)temp/=2,tot++;
                nl[2]=tot;
            }
            for(ull gun = 3;gun*gun<=temp;gun+=2){
                if(temp%gun==0){
                    ull tot=0;
                    while(temp%gun==0)temp/=gun,tot++;
                    nl[gun]=tot;
                }
            }
            if(temp!=1)nl[temp] = 1;
        }
        ull ans = 1;
        for(it=nl.begin();it!=nl.end();it++){
            ull f = it->first,s = it->second;
            //printf("%llu %llu %llu\n",f,s,nk[f]);
            if(nk[f]!=s)ans *= power(f,s);
        }
        printf("%llu",ans);
        puts("");
    }
    return 0;
}
                                                                                                                  /*#include<bits/stdc++.h>
using namespace std;
map<int,int>nK,nL;
map<int,int>::iterator it;
void PF(int ,bool);
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
int power()
int main(){
    int a,b,l;
    cin>>a>>b>>l;
    int k = a*b / gcd(a,b);
    PF(k,1),PF(l,0);
            return 0;
}
    void PF(int n,bool konta){
    if(konta){
        int k = 2;
        if(n%2==0){
            int t=0;
            while(n%2==0)t++,n/=k;
            nK[k]=t;
        }
        for(k=3;k*k<=n;k+=2){
            if(n%k==0){
                int t=0;
                while(n%k==0)t++,n/=k;
                nK[k]=t;
            }
        }
        if(n!=1)nK[n]=1;
    }else{
        int k = 2;
        if(n%2==0){
            int t=0;
            while(n%2==0)t++,n/=k;
            nL[k]=t;
        }
        for(k=3;k*k<=n;k+=2){
            if(n%k==0){
                int t=0;
                while(n%k==0)t++,n/=k;
                nL[k]=t;
            }
        }
        if(n!=1)nL[n]=1;
    }
    return;
}
*/