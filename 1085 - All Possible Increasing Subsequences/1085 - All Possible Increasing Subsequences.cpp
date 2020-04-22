#include <bits/stdc++.h>
using namespace std;
  // Thanks to Riyad vy :3
  typedef long long       ll;
typedef pair<int, int>  pii;
#define pb              push_back
#define endl            "\n"
#define BOOST           ios_base::sync_with_stdio(false)
#define mp              make_pair
const int sz = 100005;
  int n, t, tc, cur;
ll ans, mod = 1000000007, temp, tree[3 * sz], a[sz], b[sz];
map<ll, int> d;
  void clear(){
  cur = 1;
  d.clear();
  ans = 0;
  memset(tree, 0, sizeof tree);
}
  void update(int index, int left, int right, int pos, ll val){
  if(left == right && left == pos) {
    tree[index] += val;
    tree[index] %= mod;
    return;
  }
  if(left <= pos && pos <= right){
    tree[index] += val;
    tree[index] %= mod;
    update(index * 2, left, (left + right) / 2, pos, val);
    update(1 + index * 2, 1 + (left + right) / 2, right, pos, val);
  }
}
  ll query(int index, int lo, int hi, int left, int right){
  if(left <= lo && hi <= right) return tree[index];
  if(hi < left || right < lo) return 0;
  return (query(index * 2, lo, (lo + hi) / 2, left, right) + query(1 + index * 2, 1 + (lo + hi) / 2, hi, left, right)) % mod;
}
  int main(){
  for(scanf("%d", &tc); t < tc; t++){
    clear();
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%lld", &a[i]), b[i] = a[i];
    sort(b, b + n);
    for(int i = 0; i < n; i++) if( !d[ b[i] ] ) d[ b[i] ] = cur++;
    for(int i = 0; i < n; i++){
      temp = query(1, 0, cur, 0, d[ a[i] ] - 1);
      update(1, 0, cur, d[ a[i] ], 1 + temp);
      ans = (ans + 1 + temp) % mod;
    }
    printf("Case %d: %lld\n", t + 1, ans);
  }
}