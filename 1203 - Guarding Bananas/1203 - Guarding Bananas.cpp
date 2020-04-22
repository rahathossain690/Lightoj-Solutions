#include<bits/stdc++.h>
using namespace std;
  using ll = long long;
  const int N = 100005;
const ll INF = 100000000000000;
  // Allah chaile ei code AC
  struct Point{
  ll x, y;
    double disToSq(Point a){
    return (x - a.x) * (x - a.x) + (y - a.y) * (y - a.y);
  }
    bool operator == (const Point &a){
    return a.x == x and a.y == y;
  }
};
  int t, tc, n, hullInd, tInd;
Point hull[N], a[N];
double PI = acos(-1.0);
  int CCW(Point p1, Point p2, Point p3){
  ll area = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y - p1.x * p3.y - p2.x * p1.y - p3.x * p2.y;
  if(area < 0) return -1;
  if(area > 0) return 1;
  return 0;
}
  bool comp(Point &pp, Point &qq){
  int lal = CCW(a[0], pp, qq);
  if(lal == 0) return a[0].disToSq(pp) < a[0].disToSq(qq);
  return lal != -1;
}
  void grahamScan(){
  hullInd = tInd = 0;
  for(int i = 1; i < n; i++){
    if(a[tInd].y > a[i].y) tInd = i;
    else if(a[tInd].y == a[i].y and a[tInd].x > a[i].x) tInd = i;
  }
  swap(a[0], a[tInd]);
  sort(a + 1, a + n, comp);
  hull[0] = a[0];
  hull[1] = a[1];
  hull[2] = a[2];
  hullInd = 3;
  for(int i = 3; i < n; i++){
    while(hullInd >= 2 and CCW( hull[ hullInd - 2 ], hull[ hullInd - 1 ], a[i] ) != 1 ){
      hullInd--;
    }
    hull[ hullInd++ ] = a[i];
  }
}
  double angle(Point a, Point b, Point c){
  if(CCW(a, b, c) == 0) return 180.0;
  return acos( ( (a.x - b.x) * (c.x - b.x) + (a.y - b.y) * (c.y - b.y) ) / sqrt( b.disToSq(a) * b.disToSq(c) ) );
}
  double solve(){
  double ans = 2 * PI;
  ans = min( ans, angle( hull[ hullInd - 2 ], hull[ hullInd - 1 ], hull[ 0 ] ) );
  ans = min( ans, angle( hull[ hullInd - 1 ], hull[ 0 ], hull[ 1 ] ) );
  for(int i = 1; i < hullInd - 1; i++) ans = min(ans, angle(hull[i - 1], hull[i], hull[i + 1]));
  return (ans * 180) / PI;
}
  bool zero(){
  if(n <= 2) return true;
  for(int i = 1; i < n - 1; i++) if(CCW(a[0], a[i], a[i + 1]) != 0) return false;
  return true;
}
  int main(){
  for(scanf("%d", &tc); t < tc; t++){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%lld %lld", &a[i].x, &a[i].y);
    n = unique(a, a + n) - a;
    printf("Case %d: ", t + 1);
    if(zero()) puts("0");
    else grahamScan(), printf("%.9f\n", solve());
  }
}