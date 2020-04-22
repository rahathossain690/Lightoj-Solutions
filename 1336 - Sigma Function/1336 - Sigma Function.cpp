#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
  int main(){
  int t = 1, tc;
  for(scanf("%d" , &tc); t <= tc; t++){
    ll ans = 0, n, temp, sq;
    scanf("%lld", &n);
    temp = n;
    while(1){
      sq = sqrt(temp);
      if(temp < 1) break;
      ans += (1LL + sq) / 2LL;
      temp /= 2LL;
    }
    printf("Case %d: %lld\n", t, n - ans);
  }
  return 0;
}