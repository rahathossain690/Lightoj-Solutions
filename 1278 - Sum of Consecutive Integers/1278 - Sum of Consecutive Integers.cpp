#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 10000001;
#define pb push_back
ll n;
int t, tc;
bool _s[MAX];
vector<int> p;
  void sieve(){
  p.pb(2);
  for(int i = 3; i * i < MAX; i += 2){
    if(!_s[i])
      for(int j = i * i; j < MAX; j += i + i) _s[j] = 1;
  }
  for(int i = 3; i < MAX; i += 2) if(!_s[i])p.pb(i);
}
  ll getAns(ll N){
  while(N % 2 == 0) N /= 2;
  ll ans = 1, t;
  for(int i = 1; p[i] * p[i] <= N && i < p.size(); i++){
    t = 0;
    while(N % p[i] == 0)t++, N /= p[i];
    ans *= (t + 1);
  }
  if(N != 1) ans *= 2;
  return ans - 1;
}
  int main(){
  sieve();
  for(scanf("%d", &tc); t < tc; t++){
    scanf("%lld", &n);
    printf("Case %d: %lld\n", t + 1, getAns(n));
  }
}