#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAX = 1000000000000;
  ll t, tc, n, f, s;
vector<ll> l, nv;
set<ll> vl;
set<ll> :: iterator it;
  void gen(ll k){
  if(k > MAX) return;
  l.push_back(k * 10 + 4);
  l.push_back(k * 10 + 7);
  gen(k * 10 + 4);
  gen(k * 10 + 7);
}
  void get(int cur, ll now){
  if(cur == l.size()) return;
  if(now != 1) vl.insert(now);
  if(now <= MAX / l[cur]) { // I DONT KNOW WHY DID IT SAVE TIME FOR THE SECOND CALL :/
    get(cur, now * l[cur]);
    get(cur + 1, now);
  }
}
  int main(){
  gen(0);
  sort(l.begin(), l.end());
  get(0, 1);
  for(it = vl.begin(); it != vl.end(); it++) nv.push_back(*it);
  for(scanf("%lld", &tc); t < tc; t++){
    scanf("%lld %lld", &f, &s);
    printf("Case %lld: %d\n", t + 1, upper_bound(nv.begin(), nv.end(), s) - lower_bound(nv.begin(), nv.end(), f));
  }
}