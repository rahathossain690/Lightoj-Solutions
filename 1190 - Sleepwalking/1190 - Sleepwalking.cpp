#include<bits/stdc++.h>
using namespace std;
  typedef long long ll;
  const int N = 102;
  struct Point{
  ll x, y;
  void scan(){ scanf("%lld %lld", &x, &y); }
  pair<ll, ll> PR(){ return {x, y}; }
};
  int CCW(Point &a, Point &b, Point &c){
  ll ans = a.x * b.y + b.x * c.y + c.x * a.y - a.x * c.y - b.x * a.y - c.x * b.y;
  if(ans == 0) return 0;
  if(ans < 0) return -1;
  return 1;
}
  bool intersects(Point &a, Point &b, Point &p, Point &q){
  int ans1 = CCW(a, b, p); //cout << a.x << " " << a.y << " " << b.x << " " << b.y << " " << p.x << " " << p.y << " " << q.x << " " << q.y << endl;
  int ans2 = CCW(a, b, q); //cout << ans1 << " " << ans2 << endl;
  int ans3 = CCW(p, q, a);
  int ans4 = CCW(p, q, b);
  return ans1 != ans2 and ans3 != ans4;
}
  int t, tc, n, q;
Point a[N], me, op;
set< pair<ll, ll> > v;
  bool online(Point &a, Point &b, Point &c){
  int ans = CCW(a, b, c);
  if(ans != 0) return false;
  return min(a.x, b.x) <= c.x and c.x <= max(a.x, b.x) and min(a.y, b.y) <= c.y and c.y <= max(a.y, b.y);
}
  bool special(Point &me){
  if(v.find(me.PR()) != v.end()) return true;
  bool ans = online(a[n - 1], a[0], me);
  for(int i = 0; i < n - 1; i++) ans |= online(a[i], a[i + 1], me);
  return ans;
}
  int main(){ //freopen("in.txt", "w", stdout);
  op.y = 13001;
  for(scanf("%d", &tc); t < tc; t++){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) a[i].scan(), v.insert(a[i].PR());
    scanf("%d", &q);
    printf("Case %d:\n", t + 1);
    while(q--){
      me.scan();
      if(special(me)) {
        puts("Yes");
        continue;
      }
      op.x = me.x + 1; ;
      int cnt = intersects(a[n - 1], a[0], me, op);
      for(int i = 0; i < n - 1; i++) cnt += intersects(a[i], a[i + 1], me, op); //cout << cnt << " ";
      puts(cnt&1? "Yes" : "No");
    }
    v.clear();
  }
}