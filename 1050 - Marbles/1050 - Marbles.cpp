#include "bits/stdc++.h"
using namespace std;
  typedef long long ll;
typedef pair<int, int> pii;
#define pb          push_back
#define endl        "\n"
#define mp           make_pair
#define min(a,b)    (a<b?a:b)
#define max(a,b)    (a>b?a:b)
const int sz = 501;
  int t = 1, tc;
double dp[sz][sz];
bool chk[sz][sz];
  double p(int g, int b){
  if(chk[g][b]) return dp[g][b];
  double ans = 0;
  if(g > 0 && b > 1)ans += g * p(g - 1, b - 1);
  if(b > 0 && b > 2)ans += b * p(g, b - 2);
  chk[g][b] = 1;
  return dp[g][b] = ans / (g + b);
}
  int main(){
  int g, b;
  dp[0][1] = 1;
  dp[1][0] = 0;
  chk[0][1] = chk[1][0] = 1;
  for(scanf("%d", &tc); t <= tc; t++){
    scanf("%d%d", &g, &b);
    printf("Case %d: %.10lf\n", t, p(g, b));
  }
}