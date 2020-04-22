#include <bits/stdc++.h>
using namespace std;
  const int N = 1005;
  int BIT[N][N], t, tc, q, x[3], y[3], cmd;
bool f[N][N];
  void update(int x, int y){
  for(; x < N; x += x & -x){
    for(int y1 = y; y1 < N; y1 += y1 & -y1){
      BIT[x][y1] += 1;
    }
  }
}
  int query(int x, int y){
  int ans = 0;
  for(; x > 0; x -= x & -x){
    for(int y1 = y; y1 > 0; y1 -= y1 & -y1){
      ans += BIT[x][y1];
    }
  }
  return ans;
}
  int main(){
  for(scanf("%d", &tc); t < tc; t++){
    scanf("%d", &q);
    memset(BIT, 0, sizeof BIT);
    memset(f, 0, sizeof f);
    printf("Case %d:\n", t + 1);
    while(q--){
      scanf("%d", &cmd);
      if(!cmd){
        scanf("%d %d", &x[0], &y[0]);
        x[0]++, y[0]++;
        if(f[ x[0] ][ y[0] ]) continue;
        update(x[0], y[0]);
        f[ x[0] ][ y[0] ] = 1;
      }
      else{
        scanf("%d %d %d %d", x + 1, y + 1, x + 2, y + 2);
        x[1]++, x[2]++, y[1]++, y[2]++;
        printf("%d\n", query(x[2], y[2]) - query(x[1] - 1, y[2]) - query(x[2], y[1] - 1) + query(x[1] - 1, y[1] - 1));
      }
    }
  }
}