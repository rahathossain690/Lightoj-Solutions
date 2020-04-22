#include <bits/stdc++.h>
using namespace std;
  typedef long long       ll;
typedef pair<int, int>  pii;
#define pb              push_back
#define endl            "\n"
#define mp              make_pair
const ll mod = (ll) 1e9;
  vector<pii> bc;
set<int> s;
int t, tc, x, y, m, n, k, b;
ll ans;
  ll bigmod(int a, int b){
  if(b == 0) return 1;
  ll ans = bigmod(a, b / 2);
  ans = (ans * ans) % mod;
  if(b % 2 == 1) ans = (a * ans) % mod;
  return ans;
}
  ll getAns(int p){
  if(p == 0) return 1;
  return (k * bigmod(k - 1, p - 1)) % mod;
}
  ll go(){
  if(bc.size() == 0) return 1;
  ll ans = 1;
  vector<int> q;
  int cur = -1;
  bc.pb({0, 0});
  for(int i = 0; i < bc.size(); i++){
    if(q.empty()) cur = bc[i].second;
    if(cur == bc[i].second) q.pb(bc[i].first);
    else {
      --i;
      q.pb(m + 1);
      int last = 0;
      for(int j = 0; j < q.size(); j++){
        ans = ans * getAns(q[j] - last - 1);
        ans %= mod;
        last = q[j];
      }
      q.clear();
    }
  }
  bc.clear();
  return ans;
}
  bool comp(pii a, pii b){
  if(a.second == b.second) return a.first < b.first;
  return a.second < b.second;
}
  int main(){
  for(scanf("%d", &tc); t < tc; t++){
    scanf("%d %d %d %d", &m, &n, &k, &b);
    while(b--){
      scanf("%d %d", &x, &y);
      bc.pb({x, y});
      s.insert(y);
    }
    ans = bigmod(getAns(m), n - s.size());
    s.clear();
    sort(bc.begin(), bc.end(), comp);
    ans = (ans * go()) % mod;
    printf("Case %d: %lld\n", t + 1, ans);
  }
}