#include "bits/stdc++.h"
    using namespace std;
          #define ll          long long
    #define pb          push_back
    #define endl        "\n"
    #define mp          make_pair
    #define chk(n,i)    ((n&(1<<i))!=0)
          int sign(int n){return n&1?1:-1;}
    ll a[16], b[16];
    ll n, m;
                      ll gcd(ll p,ll q){ return q == 0? p : gcd(q, p% q);}
    ll lcm(ll p, ll q){return p * (q / gcd(p, q));}
            int main(){
              #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);double _CL_ = clock();
        #endif
        //ios_base::sync_with_stdio(false);
        int t = 1, tc = 0;
        for(scanf("%d", &tc); t <= tc; t++){
            ll ans = 0;
            scanf("%lld%lld",&n,&m);
            for(int i = 0; i < m; i++) scanf("%lld",&b[i]);
            sort(b, b + m);
            int sz = 0;
            //for(int i = 0; i < m; i++) cout << a[i] << endl;
            for(unsigned int i = 1; i < (1<<m); i++){
                ll temp = 1, tot = 0;
                for(unsigned int j = 0; (1<<j) <= i; j++){
                    if(chk(i,j))temp = lcm(temp, b[j]), tot++;
                }
                ans += (n * 1LL * sign(tot))/ temp;
            }
            printf("Case %d: %lld\n", t, n - ans);
        }
        #ifndef ONLINE_JUDGE
        printf("\n\nT = %lf\n",(clock()- _CL_ )/CLOCKS_PER_SEC);
        #endif
    }