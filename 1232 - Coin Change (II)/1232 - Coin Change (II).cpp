#include<bits/stdc++.h>
using namespace std;
    #define START       double cL = clock()
#define FINISH      printf("E = %lfs\n", (clock() - cL) / CLOCKS_PER_SEC);
  int n,k,a[110];
long long dp[110][10010];
    int main(){ //freopen("in.txt","r",stdin);
    //START;
    int t = 0,q = 0;
    scanf("%d",&t);
    q=t;
    while(t--){
        scanf("%d%d",&n,&k);
        for(int i = 1;i<=n;i++)scanf("%d",&a[i]);
        memset(dp,0,sizeof(dp));
        dp[0][0] = 1;
        for(int i = 1;i<=n;i++){
            for(int j = 0;j<=k;j++){
                dp[i][j] = dp[i-1][j];
                if(j>=a[i]) dp[i][j] =  (dp[i][j] + dp[i][j-a[i]])%100000007;
            }
        }
                printf("Case %d: %lld\n",q-t,dp[n][k]);
    }
    //FINISH;
}