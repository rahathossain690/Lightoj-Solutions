#include "bits/stdc++.h"
using namespace std;
  #define max(a, b)   (a>b?a:b)
#define min(a, b)   (a<b?a:b)
  const int sz = 1e5 + 5, inf = 1e9 + 1;
int mxtree[3 * sz], mntree[3 * sz], a[sz], n, q;
  int preMax(int node, int l, int r){
  if(l == r) return mxtree[node] = a[l];
  int ans1 = preMax(node * 2, l, (l + r)/ 2);
  int ans2 = preMax(1 + node * 2, 1 + (l + r)/ 2, r);
  return mxtree[node] = max(ans1 , ans2);
}
  int preMin(int node, int l, int r){
  if(l == r) return mntree[node] = a[l];
  int ans1 = preMin(node * 2, l, (l + r)/ 2);
  int ans2 = preMin(1 + node * 2, 1 + (l + r)/ 2, r);
  return mntree[node] = min(ans1 , ans2);
}
  int queryMax(int node, int left, int right, int l, int r){
  if(r < left || right < l) return -inf;
  if(l <= left && right <= r) return mxtree[node];
  if(left == right) return mxtree[node];
  int ans1 = queryMax(node * 2, left, (left + right) / 2, l , r);
  int ans2 = queryMax(1 + node * 2, 1 + (left + right) / 2, right, l , r);
  return max(ans1 , ans2);
}
  int queryMin(int node, int left, int right, int l, int r){
  if(r < left || right < l) return inf;
  if(l <= left && right <= r) return mntree[node];
  if(left == right) return mntree[node];
  int ans1 = queryMin(node * 2, left, (left + right) / 2, l , r);
  int ans2 = queryMin(1 + node * 2, 1 + (left + right) / 2, right, l , r);
  return min(ans1 , ans2);
}
  int main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  double _CL_ = clock();
  #endif
  int t = 1, tc;
  for(scanf("%d", &tc); t <= tc; t++){
    scanf("%d %d", &n, &q);
    for(int i = 0; i < n; i++) scanf("%d", a + i);
    preMax(1, 0, n-1);
    preMin(1, 0, n-1);
    int ans = -inf;
    for(int i = q - 1; i < n; i++){
      ans = max(queryMax(1, 0, n - 1, i - q + 1, i) - queryMin(1, 0, n - 1, i - q + 1, i), ans);
    }
    printf("Case %d: %d\n", t, ans);
  }
  #ifndef ONLINE_JUDGE
  printf("\n\nT = %lf\n", (clock()-_CL_)/CLOCKS_PER_SEC);
  #endif
  return 0;
}