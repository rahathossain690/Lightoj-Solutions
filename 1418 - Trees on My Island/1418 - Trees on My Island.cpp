#include<bits/stdc++.h>
using namespace std;
  using ll = long long;
using Pair = pair<int, int>;
#define endl '\n'
  const int N = 10005;
  int n, tc, t, x[N], y[N], b;
  ll area(){
  x[n] = x[0], y[n] = y[0];
  ll a = 0;
  b = 0;
  for(int i = 0; i < n; i++) {
    a += x[i] * 1LL * y[i + 1] - x[i + 1] * 1LL * y[i];
    b += __gcd(abs(x[i] - x[i + 1]), abs(y[i] - y[i + 1]));
  }
  return abs(a);
}
  int main(){
  for(scanf("%d", &tc); t < tc; t++){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d %d", x + i, y + i);
    printf("Case %d: %lld\n", t + 1, (area() / 2 - b / 2 + 1));
  }
}