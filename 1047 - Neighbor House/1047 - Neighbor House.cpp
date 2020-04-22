#include<bits/stdc++.h>
using namespace std;
#define td(n) scanf("%d",&n)
int a[25][4],dp[25][4],n;
int main(){
    //freopen("in.txt","r",stdin);
    int t,q;
    td(t);
    q=t;
    while(t--){
        printf("Case %d: ",q-t);
        td(n);
        for(int i=0;i<n;i++)td(a[i][1]),td(a[i][2]),td(a[i][3]);
        dp[0][1]=a[0][1],dp[0][2]=a[0][2],dp[0][3]=a[0][3];
        //printf("\n%d %d %d\n",dp[0][1],dp[0][2],dp[0][3]);
        for(int i=1;i<n;i++){
            dp[i][1]=a[i][1],dp[i][2]=a[i][2],dp[i][3]=a[i][3];
            dp[i][1] += min(dp[i-1][2],dp[i-1][3]);
            dp[i][2] += min(dp[i-1][3],dp[i-1][1]);
            dp[i][3] += min(dp[i-1][2],dp[i-1][1]);
            //printf("%d %d %d\n",dp[i][1],dp[i][2],dp[i][3]);
        }
        printf("%d\n",min(dp[n-1][3],min(dp[n-1][2],dp[n-1][1])));
    }
    return 0;
}