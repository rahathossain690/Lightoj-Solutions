#include <bits/stdc++.h>
using namespace std;
  typedef long long       ll;
typedef pair<int, int>  pii;
#define pb              push_back
#define endl            "\n"
#define mp              make_pair
const int sz = 17;
  #define CHECK(n, p)     (n&(1<<p))
#define SET(n, p)       (n|(1<<p))
  int t, tc, b, k;
char a[sz];
ll dp[1<<sz][21];
  int val(int in){
  if('0' <= a[in] && a[in] <= '9') return a[in]-'0';
  return a[in] - 'A' + 10;
}
  ll go(unsigned int mask, int pos, int rem){
  if(dp[mask][rem] != -1) return dp[mask][rem];
  if(pos == 0) return dp[mask][rem] = (rem == 0);
  ll ans = 0;
  for(int i = 0; a[i]; i++){
    if(!CHECK(mask, i))
     ans += go(SET(mask, i), pos - 1, (rem * b + val(i)) % k);
  }
  return dp[mask][rem] = ans;
}
  int main(){
  for(scanf("%d", &tc); t < tc; t++){
    scanf("%d %d %s", &b, &k, a);
    memset(dp, -1, sizeof dp);
    printf("Case %d: %lld\n", t + 1, go(0, strlen(a), 0));
  }
}