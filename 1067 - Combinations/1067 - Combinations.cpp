#include <bits/stdc++.h>
using namespace std;
#define mod %1000003
  long long c[1000001];
void pre(){
    c[0]=1;
    for(int i=1;i<1000001;i++)c[i]=(c[i-1]mod * i mod)mod;
}
  unsigned long long rinv(unsigned long long b, unsigned long long r){
    if(b==0)return 1;
    if(b==1) return r mod;
    unsigned long long p = rinv(b/2,r) mod;
    return b&1?(p*(p*(r mod) mod))mod:(p*p)mod;
}
  int main() {
    pre();
    int t,q;
    scanf("%d",&t);
    q=t;
    while(t--){
        int n,r;
        scanf("%d%d",&n,&r);
        unsigned long long rr = c[r]*c[n-r],nn = c[n],ans;
        ans = (nn * rinv(1000001,rr))mod;
        printf("Case %d: %llu\n",q-t,ans);
    }
    return 0;
}