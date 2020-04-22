#include<bits/stdc++.h>
using namespace std;
  typedef unsigned long long ll;
const int N = 51;
  int t, tc, n, m;
ll dp[N][N][2];
  ll go(int s, int b, bool w){
  if(s == 0 && b == 0) return 1;
  if(dp[s][b][w] != -1) return dp[s][b][w];
  ll ans = 0;
  if(w){
    for(int i = 1; i <= b; i++){
      ans += go(s + b - i, i - 1, 0);
    }
  }
  else {
    for(int i = 1; i <= s; i++){
      ans += go(i - 1, b + s - i, 1);
    }
  }
  return dp[s][b][w] = ans;
}
  ll solve(){
  scanf("%d %d", &n, &m);
  if(n < 3) return 1;
  return m == 1 ? go(1, n - 3, 0) : go(m - 1, n - m, 0);
}
  int main(){for(scanf("%d", &tc), memset(dp, -1, sizeof dp); t < tc; printf("Case %d: %llu\n", ++t, solve()));}