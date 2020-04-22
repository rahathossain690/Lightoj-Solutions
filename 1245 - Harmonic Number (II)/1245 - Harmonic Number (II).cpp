#include <bits/stdc++.h>
using namespace std;
  #define ll long long
  ll solve(ll n){
    ll ans = 0,i;
    for(i = 1; i*i <= n ; i++) ans += n/i;
    --i;
    if(n/i==i)i--;
    for(;i>0;i--)ans += i*((n/i)- n/(i+1));
    return ans;
}
  int main(){ //freopen("in.txt","r",stdin);
    int t=1,tc;
    for(scanf("%d",&tc);t<=tc;t++){
        ll n;
        scanf("%lld",&n);
        printf("Case %d: %lld\n",t,solve(n));
    }
}