#include <bits/stdc++.h>
using namespace std;
// Ayman vai <3
typedef long long ll;
typedef pair<int, int> pii;
#define pb            push_back
#define endl          "\n"
#define mp          make_pair
const int sz = 17;
  bool CHECK(int N,int pos) { return (bool)(N&(1<<pos)); }
unsigned int SET(int N,int pos) { return (N|(1<<pos)); }
  int x[sz], y[sz], n, t, tc, dp[1 << sz];
unsigned int sem[sz][sz];
  bool semLine(int p1, int p2, int p3){
  return x[p1] * y[p2] + x[p2] * y[p3] + x[p3] * y[p1] == x[p2] * y[p1] + x[p3] * y[p2] + x[p1] * y[p3];
}
    int go(unsigned int mask){
  if(dp[mask] != -1) return dp[mask];
  if(mask == (1<<n) - 1) return dp[mask] = 0;
  int ans = 8;
  int cnt = __builtin_popcount(mask);
  if(cnt == n - 1 || cnt == n - 2) return dp[mask] = 1;
  for(int i = 0; i < n; i++){
    if(CHECK(mask, i)) continue;
    for(int j = i + 1; j < n; j++){
      if(CHECK(mask, j)) continue;
      ans = min(ans, 1 + go(mask | sem[ i ][ j ]));
    }
    break;
  }
  return dp[mask] = ans;
}
  int main(){
  for(scanf("%d", &tc); t < tc; t++){
    memset(dp, -1, sizeof dp);
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d %d", x + i, y + i);
    for(int i = 0; i < n; i++){
      for(int j = i + 1; j < n; j++){
        unsigned int temp = 0;
        temp = SET(temp, i);
        temp = SET(temp, j);
        for(int k = 0; k < n; k++){
          if(semLine(i, j, k)) temp = SET(temp, k);
        }
        sem[i][j] = temp;
      }
    }
    printf("Case %d: %d\n", t + 1, go(0));
  }
    return 0;
}