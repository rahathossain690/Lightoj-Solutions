#include "bits/stdc++.h"
using namespace std;
  #define pb push_back
#define ll long long
  const int sz = 1e6 + 20;
vector <int> p;
bool sv[sz];
  int main(){
  p.pb(2);
  for(int i = 3; i * i <= sz; i += 2){
    if(!sv[i]) for(int j = i*i; j<=sz; j+=i+i) sv[j] = 1;
  }
  for(int i = 3; i <= sz; i += 2) if(!sv[i]) p.pb(i);
  int n, a, t = 1, tc;
  for(scanf("%d", &tc); t <= tc; t++){
    ll ans = 0;
    scanf("%d", &n);
    while(n--){
      scanf("%d", &a);
      ans += p[(lower_bound(p.begin(), p.end(), a+1) - p.begin())];
    }
    printf("Case %d: %lld Xukha\n", t, ans);
  }
}