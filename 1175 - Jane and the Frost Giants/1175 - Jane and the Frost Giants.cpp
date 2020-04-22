#include "bits/stdc++.h"
using namespace std;
  typedef long long ll;
typedef pair<int, int> pii;
#define pb          push_back
#define endl        "\n"
#define mp          make_pair
#define val(II,JJ)  (0<=II&&II<n&&0<=JJ&&JJ<m)
#define min(a,b)    (a<b?a:b)
#define max(a,b)    (a>b?a:b)
const int sz = 205, inf = 1<<10;
  int n, m, cost[sz][sz], fire[sz][sz], J[2], F[2], t = 1, tc, ans, inX, inY;
char a[sz][sz];
queue<pii> q;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
  void bfs(int x, int y, int in){
  if(in){
    q.push( mp(x, y) );
    cost[x][y] = 0;
    while(!q.empty()){
      inX = q.front().first;
      inY = q.front().second;
      q.pop();
      for(int i = 0; i < 4; i++){
        if(val( inX+dx[i], inY+dy[i] ) && a[inX+dx[i]][ inY+dy[i] ] != '#'){
          if( cost[inX+dx[i]][ inY+dy[i] ] > 1 + cost[inX][inY] ){
            cost[inX+dx[i]][ inY+dy[i] ] = 1 + cost[inX][inY];
            q.push( mp( inX+dx[i], inY+dy[i] ) );
          }
        }
      }
    }
  }
  else{
    q.push( mp(x, y) );
    fire[x][y] = 0;
    while(!q.empty()){
      inX = q.front().first;
      inY = q.front().second;
      q.pop();
      for(int i = 0; i < 4; i++){
        if(val( inX+dx[i], inY+dy[i] ) && a[inX+dx[i]][ inY+dy[i] ] != '#'){
          if( fire[inX+dx[i]][ inY+dy[i] ] > 1 + fire[inX][inY] ){
            fire[inX+dx[i]][ inY+dy[i] ] = 1 + fire[inX][inY];
            q.push( mp( inX+dx[i], inY+dy[i] ) );
          }
        }
      }
    }
  }
}
  int main(){
  for(scanf("%d", &tc); t <= tc; t++){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++) cost[i][j] = fire[i][j] = inf;
    }
    for(int i = 0; i < n; i++) scanf("%s", a[i]);
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        if(a[i][j] == 'J') bfs(i, j, 1);
        else if(a[i][j] == 'F') bfs(i, j, 0);
      }
    }
    ans = inf;
    for(int i = 0; i < n; i++){
      if(cost[i][0] < fire[i][0]){
        ans = min(ans, cost[i][0]);
      }
    }
    for(int j = 0; j < m; j++){
      if(cost[0][j] < fire[0][j]){
        ans = min(ans, cost[0][j]);
      }
    }
    for(int i = 0; i < n; i++){
      if(cost[i][m-1] < fire[i][m-1]){
        ans = min(ans, cost[i][m-1]);
      }
    }
    for(int j = 0; j < m; j++){
      if(cost[n-1][j] < fire[n-1][j]){
        ans = min(ans, cost[n-1][j]);
      }
    }
    printf("Case %d: ", t);
    if(ans == inf) puts("IMPOSSIBLE");
    else printf("%d\n", ans + 1);
  }
}