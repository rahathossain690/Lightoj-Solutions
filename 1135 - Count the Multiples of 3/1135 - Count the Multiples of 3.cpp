#include<bits/stdc++.h>
using namespace std;
  typedef long long ll;
const int N = 100002;
  int t, tc, n, l, r, q;
int lazy[3 * N], tree[3 * N][3];
  void build(int node, int left, int right){
  if(left == right){
    tree[node][0] = 1;
    tree[node][1] = tree[node][2] = 0;
    return;
  }
  build(node * 2, left, (left + right) / 2);
  build(1 + node * 2, 1 + (left + right) / 2, right);
  for(int i = 0; i < 3; i++) tree[node][i] = tree[ node * 2] [i] + tree[1 + node * 2][i];
}
  void lazyShift(int lz, int node){
  if(lz == 1) {
    int temp = tree[node][2];
    tree[node][2] = tree[node][1];
    tree[node][1] = tree[node][0];
    tree[node][0] = temp;
    return;
  }
  if(lz == 2) lazyShift(1, node), lazyShift(1, node);
}
  void update(int node, int left, int right, int l, int r){
  if(l <= left && right <= r){
    lazyShift(1, node);
    lazy[node] = (1 + lazy[node]) % 3;
    return;
  }
  if(r < left || right < l) return;
  update(node * 2, left, (left + right) / 2, l, r);
  update(1 + node * 2, 1 + (left + right) / 2, right, l, r);
  for(int i = 0; i < 3; i++) tree[node][i] = tree[ node * 2] [i] + tree[1 + node * 2][i];
  lazyShift(lazy[node], node); // why da faq i need this shitttttt i donno.. hate you shafayats planet! shitty explanation!
}
  int query(int node, int left, int right, int l, int r, int carry){
  if(l <= left && right <= r){
    if(carry == 0) return tree[node][0];
    if(carry == 1) return tree[node][2];
    if(carry == 2) return tree[node][1];
  }
  if(r < left || right < l) return 0;
  return query(node * 2, left, (left + right) / 2, l, r, (carry + lazy[node]) % 3) + query(1 + node * 2, 1 + (left + right) / 2, right, l, r, (carry + lazy[node]) % 3);
}
  int solve(){
  scanf("%d %d", &n, &q);
  memset(tree, 0, sizeof tree);
  memset(lazy, 0, sizeof lazy);
  build(1, 0, n - 1);
  while(q--){
    int cmd = 0;
    scanf("%d %d %d", &cmd, &l, &r);
    if(cmd) printf("%d\n", query(1, 0, n - 1, l, r, 0));
    else update(1, 0, n - 1, l, r);
  }
  return 0;
}
  int main(){
  for(scanf("%d", &tc); t < tc; printf("Case %d:\n", ++t), solve());
}