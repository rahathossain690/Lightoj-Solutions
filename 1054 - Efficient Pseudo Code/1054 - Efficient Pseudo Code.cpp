#include<bits/stdc++.h>
using namespace std;
  #define pb push_back
#define endl "\n"
#define ll long long
  int mod = 7+1e9;
  ll bigmod(ll a, ll b){
    if(b == 0) return 1;
    ll ans = bigmod(a,b/2);
    ans = (ans*ans)%mod;
    return (ans*(b&1?a%mod:1))%mod;
}
  ll modinverse(ll a){
    return bigmod(a,mod-2);
}
  int main(){ //freopen("in.txt","r",stdin);
    int tc,tt=1;
    for(scanf("%d",&tc);tt<=tc;tt++){
        ll n,m;
        scanf("%lld %lld",&n,&m);
        vector<ll>p,x;
        /*pf*/{
            ll k = n,t = 0;
            while(k%2==0)k/=2,t++;
            if(t)p.pb(2),x.pb(m*t);
            for(ll i = 3;i*i <= k;i+=2){
                if(k%i == 0){
                    t = 0;
                    while(k%i==0)k/=i,t++;
                    p.pb(i),x.pb(m*t);
                }
            }
            if(k!=1)p.pb(k),x.pb(m);
        }
        ll ans = 1;
        for(int i = 0;i < p.size();i++){
            ans *= ((bigmod(p[i],x[i]+1) - 1) * modinverse(p[i]-1))% mod;
            ans %= mod;
            if(ans<0)ans += mod;
        }
        printf("Case %d: %lld\n",tt,ans);
    }
}