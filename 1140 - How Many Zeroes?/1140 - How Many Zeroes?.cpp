#include "bits/stdc++.h"
    using namespace std;
          #define ll      long long
    #define pb      push_back
    #define endl    "\n"
    #define mp      make_pair
          ll p[15];
      ll zero(ll n){
        if(n < 0) return 0;
        if(n < 10) return 1;
        ll ans = 1, temp;
        for(ll i = 1;p[i] <= n; i++){
            temp = n / p[i];
            if((n/p[i-1])%10 == 0){
                ans += (temp - 1)*p[i - 1] + n % p[i - 1] + 1;
            }
            else ans += temp * p[i - 1];
        }
        return ans;
    }
          int main(){
        p[0] = 1;
        for(int i = 1; i < 15; i++) p[i] = 10 * p[i-1];
        ll m, n;
        int t = 1, tc;
        for(scanf("%d",&tc); t<=tc;t++){
            scanf("%lld%lld", &n, &m);
            printf("Case %d: %lld\n",t, zero(m) - zero(n - 1));
        }
        return 0;
    }