#include<bits/stdc++.h>
using namespace std;
  typedef long long ll;
const int MAX = 100000000, N = 1000005;
  long long buck[N], mod = 10000;
int t, tc, k;
  long long getAns(int k){
  if(k == MAX) return 1;
  ll cur = buck[k / 100];
  int rest = k % 100;
  for(int in = 1 + (k / 100) * 100; in <= k; in++) cur = (1 + in * cur) % mod;
  return cur;
}
  int main(){
  buck[0] = 1;
  ll cur = 1;
  for(int i = 1; i < MAX; i++){
    cur = (1 + i * cur) % mod;
    if(i % 100 == 0) buck[i / 100] = cur;
  }
  for(scanf("%d", &tc); t < tc;){
    scanf("%d", &k);
    if(k >= 6) printf("Case %d: %04lld\n", ++t, getAns(k));
    else printf("Case %d: %lld\n", ++t, getAns(k));
  }
}