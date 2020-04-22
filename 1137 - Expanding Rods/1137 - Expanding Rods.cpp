#include "bits/stdc++.h"
using namespace std;
  double pi = acos(-1.0);
  int main(){
  int t = 1, tc;
  double lo, hi, mid, r, l, ln, n, c;
  for(scanf("%d", &tc); t <= tc; t++){
    scanf("%lf %lf %lf", &l, &n, &c);
    ln = (1 + n*c)*l;
    lo = 0, hi = pi;
    while(hi - lo > 0.000000000001){
      mid = (hi + lo) / 2;
      if( l * mid < 2 * ln * sin(mid / 2) ) lo = mid;
      else hi = mid;
    }
    r = ln / mid;
    printf("Case %d: %.10lf\n", t, r - r*cos(mid / 2));
  }
  return 0;
}