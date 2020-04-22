#include <bits/stdc++.h>
using namespace std;
// define use kora jabe na :)
const int sz = 30005, inf = 1<<29;
  int tree[sz * 3], t, tc, a[sz], n;
  int init(int node, int lo, int hi){
  if(lo == hi) return tree[node] = lo;
  int ans1 = init(node * 2, lo, (lo + hi)/2);
  int ans2 = init(node * 2 + 1, 1 + (lo + hi)/2, hi);
  if(a[ans1] < a[ans2]) return tree[node] = ans1;
  return tree[node] = ans2;
}
  int query(int node, int left, int right, int l, int r){
  if(l <= left && right <= r) return tree[node];
  if(r < left || right < l) return sz - 1;
  if(left == right) return tree[node];
  int ans1 = query(node * 2, left, (left + right)/2, l, r);
  int ans2 = query(node * 2 + 1, 1 + (left + right)/2, right, l, r);
  if(a[ans1] < a[ans2]) return ans1;
  return ans2;
}
  int large(int lo, int hi){
  if(lo > hi) return 0;
  if(lo == hi) return a[lo];
  int point = query(1, 0, n - 1, lo, hi);
  return max(a[point] * (hi - lo + 1), max(large(lo, point - 1), large(point + 1, hi)));
}
  int main(){
  a[sz - 1] = inf;
  for(scanf("%d", &tc); t < tc; t++){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", a + i);
    init(1, 0, n - 1);
    printf("Case %d: %d\n", t + 1, large(0, n - 1));
  }
    return 0;
}