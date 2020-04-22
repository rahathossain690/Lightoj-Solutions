#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define pb push_back
  bool a[10000001];
vector<int>p;
  void sieve(){
  p.pb(2);
  for(int i=3;i*i<=10000000;i+=2){
    if(!a[i]){
      for(int j=i*i;j<=10000000;j+=i+i)a[j]=1;
    }
  }
  for(int i=3;i<=10000000;i+=2)if(!a[i])p.pb(i);
}
  vector<int>x;
  void solve(){
  x.clear();
  ll n;
  int t;
  scanf("%lld",&n);
  for( int i = 0; p[i] * 1LL * p[i] <= n && i < p.size() ; i++ ){
    if( n%p[i] == 0 ){
      t = 0;
      while(n%p[i] == 0) n/= p[i], t++;
      x.pb(t);
    }
  }
  if(n!=1)x.pb(1);
  ll ans = 1;
  for(int i = 0; i < x.size(); i++)
    ans *= ( 2 * x[i] + 1);
  printf("%lld",(ans+1)/2);
}
  int main(){ //freopen("in.txt","r",stdin);
  sieve();
  int t=1,tc;
  for(scanf("%d",&tc);t<=tc;t++){
    printf("Case %d: ",t);
    solve();
    puts("");
  }
}