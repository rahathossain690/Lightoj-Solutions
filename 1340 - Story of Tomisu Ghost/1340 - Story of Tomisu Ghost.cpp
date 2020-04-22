#include "bits/stdc++.h"
using namespace std;
  #define mod 10000019
  bool z[100001];
vector<int>p;
void siv(){
  p.push_back(2);
  for(int i = 3; i*i < 100001; i+=2){
    if(!z[i])for(int j = i*i; j < 100001; j+=i+i) z[j] = 1;
  }
  for(int j = 3; j<100001; j+=2)if(!z[j])p.push_back(j);
}
  int cnt(int n, int p){
  int ans = 0;
  while(n != 0) ans += n/p, n/=p;
  return ans;
}
  long long bigmod(long long a, long long b){
  if(b == 0) return 1;
  if(b == 1) return a;
  long long ans = bigmod(a,b / 2);
  ans = (ans * 1LL * ans) % mod;
  if(b & 1) ans = (ans * 1LL * a) % mod;
  return ans;
}
  int solve(){
  int n, t, tot;
  scanf("%d%d",&n,&t);
  long long ans = 1;
  for(int i = 0; p[i] <= n && i < p.size(); i++){
    ans = (ans * bigmod( p[i] , cnt(n, p[i]) / t )) % mod;
  }
  if(ans == 1) ans = -1;
  printf("%lld\n" , ans);
}
  int main(){
  siv();
  int t = 1, tc;
  for(scanf("%d", &tc); t <= tc; t++){
    printf("Case %d: ", t);
    solve();
  }
}