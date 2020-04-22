#include <bits/stdc++.h>
using namespace std;
  typedef long long ll;
typedef pair<int, int> pii;
#define pb          push_back
#define endl        "\n"
#define mp          make_pair
#define min(a,b)    (a<b?a:b)
#define max(a,b)    (a>b?a:b)
const int sz = 51;
  int l1, l2, l3, t = 1, tc;
char a[sz], b[sz], c[sz], dp[sz][sz][sz];
  int go(int p, int q, int r){
  if(p == l1 || q == l2 || r == l3) return 0;
  if(dp[p][q][r] != -1) return dp[p][q][r];
  if(a[p] == b[q] && b[q] == c[r]) return dp[p][q][r] = 1 + go(p + 1, q + 1, r + 1);
  int ans = 0;
  ans = max(ans, go(p + 1, q, r));
  ans = max(ans, go(p, q + 1, r));
  ans = max(ans, go(p, q, r + 1));
  return dp[p][q][r] = ans;
}
  int main(){
  for(scanf("%d", &tc); t <= tc; t++){
    scanf("%s %s %s", a, b, c);
    l1 = strlen(a), l2 = strlen(b), l3 = strlen(c);
    memset(dp, -1, sizeof dp);
    printf("Case %d: %d\n", t, go(0, 0, 0));
  }
}