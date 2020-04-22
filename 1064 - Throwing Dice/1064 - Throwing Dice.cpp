#include <bits/stdc++.h>
using namespace std;
  typedef long long ll;
typedef pair<ll, ll> pii;
#define pb          push_back
#define endl        "\n"
#define mp          make_pair
#define min(a,b)    (a<b?a:b)
#define max(a,b)    (a>b?a:b)
const int sz = 1001;
  int t, tc, n, x;
ll gcd;
pii dp[26][151], last;
  pii go(int N, int X){
  if(N == 0){
    pii ans;
    if(X <= 0) ans.first = ans.second = 1;
    else ans.first = 0, ans.second = 1;
    return ans;
  }
  if(dp[N][X].first != -1 && dp[N][X].second != -1) return dp[N][X];
  pii ans, temp;
  ans.first = ans.second = 0;
  for(int i = 1; i <= 6; i++){
    temp = go(N - 1, X - i);
    ans.first += temp.first;
    ans.second += temp.second;
  }
  return dp[N][X] = ans;
}
  int main(){
  for(scanf("%d", &tc); t < tc; t++){
    scanf("%d %d", &n, &x);
    for(int i = 0; i < 26; i++)
      for(int j = 0; j < 151; j++)
        dp[i][j].first = dp[i][j].second = -1;
    last = go(n, x);
    gcd = __gcd(last.first, last.second);
    printf("Case %d: ", t + 1);
    if(last.first == last.second) printf("1\n");
    else if(last.first == 0) printf("0\n");
    else printf("%lld/%lld\n", last.first / gcd, last.second / gcd);
  }
    return 0;
}