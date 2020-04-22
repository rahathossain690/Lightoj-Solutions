#include<bits/stdc++.h>
using namespace std;
  typedef long long ll;
const int N = 50001;
  struct Point{
  ll x, y;
  void scan(){ scanf("%lld %lld", &x, &y); }
  void operator =(const Point &a){ x = a.x, y = a.y; }
  bool operator ==(const Point &a){ return x == a.x and y == a.y; }
  double disToSq(Point &a){ return (a.x - x) * (a.x - x) + (a.y - y) * (a.y - y); }
};
  Point a[N], hull[N];
int hullIndex, t, tc, n;
double d, PI = acos(-1.0);
  int CCW(Point &a, Point &b, Point &c){
  ll ans = a.x * b.y + b.x * c.y + c.x * a.y - a.x * c.y - b.x * a.y - c.x * b.y;
  if(ans == 0) return 0;
  if(ans < 0) return -1;
  return 1;
}
  bool comp(Point &p, Point &q){
  int ans = CCW(a[0], p, q);
  if(ans == 0) return a[0].disToSq(p) < a[0].disToSq(q);
  return ans == 1;
}
  bool grahamScanP1(){
  hullIndex = 0;
  for(int i = 1; i < n; i++) if((a[hullIndex].y > a[i].y) or (a[hullIndex].y == a[i].y and a[hullIndex].x > a[i].x) ) hullIndex = i;
  swap(a[hullIndex], a[0]);
  sort(a + 1, a + n, comp);
  hullIndex = n - 1;
  if(n <= 2) return false;
  while(true){
    if(hullIndex == 0) return false;
    else if( CCW(a[0], a[n - 1], a[hullIndex]) ) hullIndex--;
    else break;
  }
  hullIndex++;
  reverse(a + hullIndex, a + n);
  return true;
}
  void grahamScanP2(){
  hull[0] = a[0];
  hull[1] = a[1];
  hull[2] = a[2];
  hullIndex = 3;
  for(int i = 3; i < n; i++){
    while(hullIndex >= 2 and CCW( hull[ hullIndex - 2 ], hull[ hullIndex - 1 ], a[i] ) != 1 ){
      hullIndex--;
    }
    hull[ hullIndex++ ] = a[i];
  }
}
  double angle(Point &a, Point &b, Point &c){
  return acos( ((a.x - b.x) * (c.x - b.x) + (a.y - b.y) * (c.y - b.y)) / sqrt( b.disToSq(a) * b.disToSq(c) ) );
}
  int main(){
  for(scanf("%d", &tc); t < tc; t++){
    scanf("%d %lf", &n, &d);
    for(int i = 0; i < n; i++) a[i].scan();
    int f = grahamScanP1();
    double ans = 0;
    if(!f){
      double dis = 0;
      for(int i = 1; i < n; i++) dis = max(dis, a[0].disToSq(a[i]));
      ans = 2 * PI * d + 2 * sqrt(dis);
      goto SHESH;
    }
    grahamScanP2();
    ans += d * (PI - angle( hull[hullIndex - 2], hull[hullIndex - 1], hull[0] ));
    ans += d * (PI - angle( hull[hullIndex - 1], hull[0], hull[1] ));
    for(int i = 1; i < hullIndex - 1; i++) ans += d * (PI - angle(hull[i - 1], hull[i], hull[i + 1]));
    ans += sqrt( hull[0].disToSq(hull[hullIndex - 1]) );
    for(int i = 0; i < hullIndex - 1; i++) ans += sqrt(hull[i].disToSq(hull[i + 1]));
    SHESH:
    printf("Case %d: %.9f\n", t + 1, ans);
  }
}