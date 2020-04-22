#include<bits/stdc++.h>
using namespace std;
#define td(n)   scanf("%d",&n)
#define tllu(n) scanf("%llu",&n)
#define ull     long long
#define mod     %1000007
#define pos(a) ((a)>0?(a):(a)*(-1))
  ull c,k,jog,biyog;
int t,q,n,a[100010];
bool comp(int a,int b){
    return a>b;
}
int main(){//freopen("in.txt","r",stdin);
    td(t);
    q=t;
    while(t--){
        tllu(k),tllu(c),td(n),td(a[0]);
        jog=0,biyog=0;
        for(int i=1;i<n;i++){
            a[i] = (((k mod)*(a[i-1] mod)) mod + c mod ) mod;
        }
        sort(a,a+n,comp);
        for(int i=0;i<n;i++){
            jog += ((ull)a[i])*(n-i-1);
            biyog += ((ull)a[i])*i;
        }
        printf("Case %d: %lld\n",q-t,jog-biyog);
    }
    return 0;
}