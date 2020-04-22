#include "bits/stdc++.h"
using namespace std;
  typedef long long ll;
typedef pair<int, int> pii;
#define pb          push_back
#define endl        "\n"
#define mp          make_pair
#define val(I,J)  (0<=I&&I<n&&0<=J&&J<n)
#define min(a,b)    (a<b?a:b)
#define max(a,b)    (a>b?a:b)
const int sz = 11, inf = 1<<29;
  int n, m, t = 1, tc, ans, tin[105][3], cnt, cost[sz][sz], inX, inY;
char a[sz][sz];
int dx[] = {0, 0, +1, -1};
int dy[] = {+1, -1, 0, 0};
  int bfs(int x, int y, int tX, int tY){
  queue<pii> q;
  memset(cost, -1, sizeof (cost));
  cost[x][y] = 0;
  q.push( mp(x,y) );
  while(!q.empty()){
    inX = q.front().first;
    inY = q.front().second;
    if(inX == tX && inY == tY) return cost[tX][tY];
    q.pop();
    for(int i = 0; i < 4; i++){
      if(val( inX + dx[i], inY + dy[i] ) && cost[ inX+dx[i] ][ inY+dy[i] ] == -1){
        if( a[ inX+dx[i] ][ inY+dy[i] ] == '#') continue;
        if(( inX+dx[i] == tX && inY+dy[i] == tY) ) return 1+cost[inX][inY];
        if( a[ inX+dx[i] ][ inY+dy[i] ] == '.'){
          cost[ inX+dx[i] ][ inY+dy[i] ] = cost[inX][inY] + 1;
          q.push( mp( inX+dx[i] , inY+dy[i] ) );
        }
      }
    }
  }
  return -1;
}
  int main(){
  for(scanf("%d", &tc); t <= tc; t++){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%s", a[i]);
    cnt = 0;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        if('A' <= a[i][j] && a[i][j] <= 'Z') tin[ a[i][j] - 'A' ][0] = i, tin[ a[i][j] - 'A' ][1] = j, cnt++;
      }
    }
    ans = 0;
    a[ tin[0][0] ] [ tin[0][1] ] = '.';
    for(int i = 1; i < cnt; i++){
      m = bfs(tin[i-1][0], tin[i-1][1], tin[i][0], tin[i][1]);
      a[ tin[i][0] ] [ tin[i][1] ] = '.';
      if(m == -1) {
        ans = -1;
        break;
      }
      ans += m;
    }
    printf("Case %d: ", t);
    if(ans == -1) puts("Impossible");
    else printf("%d\n", ans);
  }
}