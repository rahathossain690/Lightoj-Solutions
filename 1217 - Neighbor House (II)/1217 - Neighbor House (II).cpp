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
  int t = 1, tc, n, a[sz], dp[sz], ans;
bool bal;
  int go(int pos){
  if(pos >= n) return 0;
  if(pos == n - 1 && bal) return a[pos];
  if(pos == n - 1) return 0;
  if( dp[pos] != -1) return dp[pos];
  return dp[pos] = max(a[pos] + go( pos + 2 ), go(pos + 1));
}
  int main(){
  for(scanf("%d", &tc); t <= tc; t++){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", a + i);
    bal = 0;
    memset(dp, -1, sizeof dp);
    ans = a[0] + go(2);
    bal = 1;
    memset(dp, -1, sizeof dp);
    ans = max(ans, go(1));
    printf("Case %d: %d\n", t, ans);
  }
    return 0;
}