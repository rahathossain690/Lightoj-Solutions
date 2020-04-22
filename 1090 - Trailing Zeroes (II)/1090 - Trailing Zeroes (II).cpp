#include "bits/stdc++.h"
using namespace std;
  #define ll long long
#define pb push_back
#define endl "\n"
  ll C(int n, int p){
    ll ans = 0, k = n;
    while(k){
        ans += k/p;
        k/=p;
    }
    return ans;
}
  ll NO(int n, int p){
    ll ans = 0;
    while(n%p==0){
        ans++;
        n/=p;
    }
    return ans;
}
  int main(){ //freopen("in.txt","r",stdin);
    int tc,t=1;
    for(scanf("%d",&tc);t<=tc;t++){
        ll n ,r,p,q;
        scanf("%lld%lld%lld%lld",&n,&r,&p,&q);
        ll no2 = C(n,2)-C(r,2)-C(n-r,2) + q*NO(p,2);
        ll no5 = C(n,5)-C(r,5)-C(n-r,5) + q*NO(p,5);
        ll mex10 = min(no2,no5);
        printf("Case %d: %lld\n",t,mex10);
    }
}