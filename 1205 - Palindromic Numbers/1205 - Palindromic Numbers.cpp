#include <bits/stdc++.h>
using namespace std;
  typedef long long ll;
typedef pair<int, int> pii;
#define pb          push_back
#define endl        "\n"
#define mp          make_pair
#define min(a,b)    (a<b?a:b)
#define max(a,b)    (a>b?a:b)
const int sz = 1001;
  ll f, s;
int t = 1, tc;
  ll desired(ll a, bool even){
  ll ans = a;
  if(even){
    while(a > 0){
      ans = ans * 10 + a % 10;
      a /= 10;
    }
  }
  else {
    ans /= 10;
    while(a > 0){
      ans = ans * 10 + a % 10;
      a /= 10;
    }
  }
  return ans;
}
  ll even(ll a){
  if(a < 0) return 0;
  ll lo = 0, hi = 99999999, mid, num;
  while(lo < hi){
    mid = (lo + hi) / 2;
    num = desired(mid, 1);
    if(num == a) return mid;
    else if(num < a) lo = mid + 1;
    else hi = mid - 1;
  }
  return desired(lo, 1) > a? lo - 1 : lo;
}
  ll odd(ll a){
  if(a < 0) return -1;
  ll lo = 0, hi = 999999999, mid, num;
  while(lo < hi){
    mid = (lo + hi) / 2;
    num = desired(mid, 0);
    if(num == a)return  mid;
    else if(num < a) lo = mid + 1;
    else hi = mid - 1;
  }
  return desired(lo, 0) > a? lo - 1 : lo;
}
  int main(){
  for(scanf("%d", &tc); t <= tc; t++){
    scanf("%lld %lld", &f, &s);
    if(f > s) swap(f, s);
    printf("Case %d: %lld\n", t, odd(s) + even(s) - odd(f - 1) - even(f - 1));
  }
}