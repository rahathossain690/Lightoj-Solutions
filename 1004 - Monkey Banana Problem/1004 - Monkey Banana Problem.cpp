#include<bits/stdc++.h>
#define td(n) scanf("%d",&n)
#define CASE(N) printf("Case %d: ",N)
#define ull unsigned long long
#define max(a,b) ((a)>(b)?(a):(b))
int a[250][250];
ull dp[250][250];
int main(){
    //freopen("in.txt","r",stdin);
    int t,q;
    td(t);
    q=t;
    while(t--){
        CASE(q-t);
        int n;
        td(n);
        for(int i=0;i<n;i++)for(int j = 0;j<=i;j++)td(a[i][j]);
        for(int i=n;i<2*n-1;i++)for(int j=0;j<2*n-i-1;j++)td(a[i][j]);
        dp[0][0]=a[0][0];
        for(int i = 1;i<n;i++){
            dp[i][0] =  a[i][0];dp[i][0]+=dp[i-1][0];
            for(int j=1;j<i;j++){
                dp[i][j] = a[i][j];
                dp[i][j]+=max(dp[i-1][j-1],dp[i-1][j]);
            }
            dp[i][i] =  a[i][i];dp[i][i]+=dp[i-1][i-1];
        }
        for(int i = n;i<2*n-1;i++){
            for(int j = 0;j<2*n-i-1;j++){
                dp[i][j] = a[i][j];
                dp[i][j] += max(dp[i-1][j],dp[i-1][j+1]);
            }
        }
        printf("%llu\n",dp[2*n-2][0]);
    }
    return 0;
}