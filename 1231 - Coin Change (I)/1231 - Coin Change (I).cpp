#include<bits/stdc++.h>
using namespace std;
  int n,k,a[51],c[51];
long long dp[51][1010];
    long long make(int i ,int amount){
    if(amount == 0) return 1;
    if(i==n)return 0;
    if(dp[i][amount]!=-1)return dp[i][amount];
    long long ans1=0,ans2=0,p = 0;
    for(int j  = 0;j<c[i];j++){
        p += a[i];
        if(amount >= p)ans1 = (ans1 + make(i+1,amount-p))%100000007;
    }
    ans2 = make(i+1,amount);
    return dp[i][amount] = (ans2+ans1)%100000007;
}
    int main(){ //freopen("in.txt","r",stdin);
    int t = 0,q = 0;
    scanf("%d",&t);
    q=t;
    while(t--){
        scanf("%d%d",&n,&k);
        for(int i = 0;i<n;i++)scanf("%d",&a[i]);
        for(int i = 0;i<n;i++)scanf("%d",&c[i]);
        memset(dp,-1,sizeof(dp));
        printf("Case %d: %lld\n",q-t,make(0,k));
    }
}