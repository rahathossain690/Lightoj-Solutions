#include<bits/stdc++.h>
using namespace std;
  using ll    = long long;
  const int N = 2002;
  struct Point{
  int x, y;
  int in;
    void scan(int i){
    scanf("%d %d", &x, &y);
    in = i;
  }
    ll disToSq(Point a){
    return (x - a.x) * (x - a.x) + (y - a.y) * (y - a.y);
  }
};
  int t, tc, n;
Point a[N];
  int CCW(Point &a, Point &b, Point &c){
  ll area = a.x * b.y + b.x * c.y + c.x * a.y - a.x * c.y - b.x * a.y - c.x * b.y;
  if(area < 0) return -1;
  if(area > 0) return 1;
  return 0;
}
  bool comp(Point &p, Point &q){
  int ans = CCW(a[0], p, q);
  if(ans == 0) return a[0].disToSq(p) < a[0].disToSq(q);
  return ans != -1;
}
  bool allcoli(){
  for(int i = 1; i < n - 1; i++) if(CCW(a[0], a[i], a[i + 1]) != 0) return false;
  return true;
}
  bool badboi(){
  int tind = 0;
  for(int i = 1; i < n; i++){
    if(a[tind].y > a[i].y) tind = i;
    if(a[tind].y == a[i].y and a[tind].x > a[i].x) tind = i;
  }
  swap(a[0], a[tind]);
  sort(a + 1, a + n, comp);
  if(allcoli()) return false;
  tind = n - 1;
  while(true){
    if( CCW(a[0], a[n - 1], a[tind]) != 0) break;
    else tind--;
  }
  tind++;
  reverse(a + tind, a + n);
  return true;
}
  int main(){
  for(scanf("%d", &tc); t < tc; t++){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) a[i].scan(i);
    printf("Case %d:\n", t + 1);
    if(!badboi()) puts("Impossible");
    else{
      printf("%d", a[0].in);
      for(int i = 1; i < n; i++) printf(" %d", a[i].in);
      printf("\n");
    }
  }
}