#include<bits/stdc++.h>
using namespace std;
  #define ll long long
#define endl "\n"
#define pb push_back
  int f[2000002], mod = 7+1e9;
  ll bigmod(int a, int b){
  if(b==0) return 1;
  ll ans = bigmod(a,b>>1);
  ans = (ans*ans)%mod;
  return ( ans * (b&1?a%mod:1) )%mod;
}
  ll modinv( int a){
  return bigmod(a,mod-2);
}
  // return (n+k-1)!/((k-1)!*n!)
  int main(){
  f[0]=1;
  for(ll i = 1;i<=2000001;i++) f[i] = (f[i-1] * i%mod)%mod;
  int t=1,tc;
  for(scanf("%d",&tc);t<=tc;t++){
    ll ans = 1;
    int n,k;
    scanf("%d%d",&n,&k);
    ans = f[n+k-1];
    ans *= modinv(f[k-1]);
    ans %= mod;
    ans *= modinv(f[n]);
    ans %= mod;
    printf("Case %d: %lld\n",t,ans);
  }
  return 0;
}