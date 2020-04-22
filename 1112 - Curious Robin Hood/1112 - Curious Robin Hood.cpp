#include "bits/stdc++.h"
using namespace std;
  const int sz = 1e5 + 10, inf = 9999999;
int tree[3 * sz], a[sz], n, q, f, s, cmd;
  int pre(int node, int l, int r){
  if(l == r) return tree[node] = a[l];
  int ans1 = pre(node * 2, l, (l + r)/ 2);
  int ans2 = pre(1 + node * 2, 1 + (l + r)/ 2, r);
  return tree[node] = (ans1 + ans2);
}
  void update(int node, int l, int r, int in, int val){
  if(in < l || r < in) return;
  if(l == r && r == in) {
    tree[node] += val;
    a[in] = tree[node];
    return ;
  }
  update(node * 2, l, (l + r)/ 2, in, val);
  update(1 + node * 2,1 + (l + r)/ 2, r, in, val);
  tree[node] += val;
}
  int query(int node, int left, int right, int l, int r){
  if(r < left || right < l) return 0;
  if(l <= left && right <= r) return tree[node];
  if(left == right) return tree[node];
  int ans1 = query(node * 2, left, (left + right) / 2, l , r);
  int ans2 = query(1 + node * 2, 1 + (left + right) / 2, right, l , r);
  return (ans1 + ans2);
}
  int main(){
  int t = 1, tc;
  for(scanf("%d", &tc); t <= tc; t++){
    scanf("%d %d", &n, &q);
    for(int i = 0; i < n; i++) scanf("%d", a + i);
    pre(1, 0, n-1);
    printf("Case %d:\n", t);
    while(q--){
      scanf("%d", &cmd);
      if(cmd == 1){
        scanf("%d", &f);
        printf("%d\n", a[f]);
        update(1, 0, n-1, f, -1 * a[f]);
      }else if(cmd == 2){
        scanf("%d %d", &f, &s);
        update(1, 0, n-1, f, s);
      } else {
        scanf("%d %d", &f, &s);
        printf("%d\n", query(1, 0, n-1, f, s));
      }
    }
  }
  return 0;
}