#include "bits/stdc++.h"
using namespace std;
  #define ll          long long
#define pb          push_back
#define endl        "\n"
#define mp          make_pair
  int m, n;
int b[12], a[12];
  int dp[12][12];
  int go(int in, int plc){
    if(in > 0 && abs(a[in - 1] - b[plc]) > 2) return 0;
    if(in == n-1) return 1;
    if(dp[in][plc] != -1) return dp[in][plc];
    ll ans = 0;
    a[in] = b[plc];
    for(int i = 0; i < m; i++){
        ans += go(in + 1, i);
    }
    return dp[in][plc] = ans;
}
  int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);double _CL_ = clock();
    #endif
    int t = 1, tc;
    for(scanf("%d",&tc); t<=tc; t++){
        memset(dp,-1,sizeof(dp));
        scanf("%d%d",&m, &n);
        for(int i = 0; i<m; i++) scanf("%d",&b[i]);
        ll ans = 0;
        for(int i = 0; i < m; i++){
            ans += go(0, i);
        }
        printf("Case %d: %lld\n",t, ans);
    }
    #ifndef ONLINE_JUDGE
    printf("\n\nT = %lf\n",(clock()- _CL_ )/CLOCKS_PER_SEC);
    #endif
}