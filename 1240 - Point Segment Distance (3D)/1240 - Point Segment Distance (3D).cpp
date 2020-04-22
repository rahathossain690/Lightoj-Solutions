#include<bits/stdc++.h>
using namespace std;
  typedef long long ll;
typedef pair<int, int> Pair;
  const int N = 102;
  #define eps 0.0000000001
#define endl '\n'
  struct Point{
  double x, y, z;
    Point() : x(0), y(0), z(0) {}
    double disToSq(Point point){
    double ans = 0;
    ans += (x - point.x) * (x - point.x);
    ans += (y - point.y) * (y - point.y);
    ans += (z - point.z) * (z - point.z);
    return ans;
  }
    void scan(){
    cin >> x >> y >> z;
  }
    void assign(double a, double b, double c){
    x = a;
    y = b;
    z = c;
  }
    void print(){
    cout << x << " " << y << " " << z << endl;
  }
};
  int t, tc;
Point a, b, p;
  double ter(Point a, Point b, int cnt){ //a.print(), b.print(), cout << endl;
  Point mid1, mid2;
  mid1.assign( (2 * a.x + b.x) / 3.0, (2 * a.y + b.y) / 3.0, (2 * a.z + b.z) / 3.0 );
  mid2.assign( (a.x + 2 * b.x) / 3.0, (a.y + 2 * b.y) / 3.0, (a.z + 2 * b.z) / 3.0 );
  if( cnt == 50 ) return p.disToSq(mid1);
  if( p.disToSq(mid1) < p.disToSq(mid2) ) return ter(a, mid2, cnt + 1);
  else return ter(mid1, b, cnt + 1);
}
  int main(){
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(10);
    cin >> tc;
  for(; t < tc; t++){
    a.scan();
    b.scan();
    p.scan();
    cout << "Case " << t + 1 << ": " << sqrt( ter(a, b, 0) ) << endl;
  }
}