#include<bits/stdc++.h>
using namespace std;
  struct Point{
  double x, y;
    double disToSq(Point point){
    double ans = 0;
    ans += (x - point.x) * (x - point.x);
    ans += (y - point.y) * (y - point.y);
    return ans;
  }
    void scan(){
    scanf("%lf %lf", &x, &y);
  }
    void assign(double a, double b){
    x = a;
    y = b;
  }
};
  int t, tc;
Point a, b, c, d;
  double ter(){
  Point f1, f2, s1, s2;
  int iter = 50;
    while(iter--){
    f1.assign( (2 * a.x + b.x) / 3.0, (2 * a.y + b.y) / 3.0 );
    f2.assign( (a.x + 2 * b.x) / 3.0, (a.y + 2 * b.y) / 3.0 );
    s1.assign( (2 * c.x + d.x) / 3.0, (2 * c.y + d.y) / 3.0 );
    s2.assign( (c.x + 2 * d.x) / 3.0, (c.y + 2 * d.y) / 3.0 );
      if( f1.disToSq(s1) < f2.disToSq(s2) ){
      b.assign( f2.x, f2.y );
      d.assign( s2.x, s2.y );
    }
    else{
      a.assign( f1.x, f1.y );
      c.assign( s1.x, s1.y );
    }
  }
    return f1.disToSq(s1);
}
  int main(){
  for(scanf("%d", &tc); t < tc; t++){
    a.scan();
    b.scan();
    c.scan();
    d.scan();
    printf("Case %d: %.10f\n", t + 1, sqrt(ter()));
  }
}