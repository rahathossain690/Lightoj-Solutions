#include<bits/stdc++.h>
using namespace std;
  typedef long long ll;
const int N = 100002;
  int t, tc, n, l, r, v, q;
ll lazy[3 * N], tree[3 * N];
  void update(int node, int left, int right, int l, int r, int v){
  if(l <= left && right <= r) {
    lazy[node] += v;
    tree[node] += (right - left + 1) * v;
    return;
  }
  if(r < left || right < l) return;
  update(node * 2, left, (left + right) / 2, l, r, v);
  update(1 + node * 2, 1 + (left + right) / 2, right, l, r, v);
  tree[node] = tree[node * 2] + tree[1 + node * 2] + (right - left + 1) * lazy[node];
}
  ll query(int node, int left, int right, int l, int r, ll carry){
  if(l <= left && right <= r) return tree[node] + (right - left + 1) * carry;
  if(r < left || right < l) return 0;
  return query(node * 2, left, (left + right) / 2, l, r, carry + lazy[node]) +  query(1 + node * 2, 1 + (left + right) / 2, right, l, r, carry + lazy[node]);
}
  int solve(){
  scanf("%d %d", &n, &q);
  int cmd;
  memset(lazy, 0, sizeof lazy);
  memset(tree, 0, sizeof tree);
  while(q--){
    scanf("%d", &cmd);
    if(!cmd){
      scanf("%d %d %d", &l, &r, &v);
      update(1, 0, n - 1, l, r, v);
    }
    else {
      scanf("%d %d", &l, &r);
      printf("%lld\n", query(1, 0, n - 1, l, r, 0));
    }
  }
  return 0;
}
  int main(){
  for(scanf("%d", &tc); t < tc; printf("Case %d:\n", ++t), solve());
}