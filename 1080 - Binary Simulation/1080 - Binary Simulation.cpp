#include "bits/stdc++.h"
using namespace std;
  #define riv(a) (a=='0'?'1':'0')
#define chk(a) (a == '1')
  const int sz = 1e5 + 10;
int n, q, f, s;
char a[ sz ], cmd[5];
bool tree[3 * sz];
  void update(int node, int left, int right, int l, int r){
  if(r < left || right < l) return;
  if(l <= left && right <= r){
    tree[node] = !tree[node];
    return;
  }
  if(left == right) {
    tree[node] = !tree[node];
    return;
  }
  update(node * 2, left, (left + right) / 2, l , r);
  update(1 + node * 2, 1 + (left + right) / 2, right, l , r);
}
  char query(int node, int left, int right, int in, char car){
  car = tree[node]? riv(car): car;
  if(left == right) return chk(car)? riv(a[in]): a[in];
  if(in <= (left + right) / 2) return query(node * 2, left, (left + right) / 2, in, car);
  else return query(1 + node * 2, 1 + (left + right) / 2, right, in, car);
}
  int main(){
  int t = 1, tc;
  for(scanf("%d", &tc); t <= tc; t++){
    scanf("%s", a);
    n = strlen(a);
    memset(tree, 0, sizeof tree);
    printf("Case %d:\n", t);
    scanf("%d", &q);
    while(q--){
      scanf("%s", cmd);
      if(cmd[0] == 'I'){
          scanf("%d %d", &f, &s);
          update(1, 0, n - 1, f - 1, s - 1);
      }else{
        scanf("%d", &f);
        printf("%c\n", query(1, 0, n - 1, f - 1, '0'));
      }
    }
  }
  return 0;
}