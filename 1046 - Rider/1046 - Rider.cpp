#include "bits/stdc++.h"
using namespace std;
  typedef long long ll;
typedef pair<int, int> pii;
#define pb          push_back
#define endl        "\n"
#define mp          make_pair
#define val(I,J)  (0<=I&&I<n&&0<=J&&J<m)
#define min(a,b)    (a<b?a:b)
#define max(a,b)    (a>b?a:b)
const int sz = 11, inf = 1<<29;
  queue <pii> q;
char a[sz][sz];
int ans[105][sz][sz], m, n, inX, inY, k, t = 1, tc, cnt, fin, cur;
int dx[] = {+1, +2, -1, -2, -1, -2, +1, +2};
int dy[] = {+2, +1, -2, -1, +2, +1, -2, -1};
  void bfs(int x, int y, int in){
  q.push( mp(x, y) );
  k = a[x][y] - '0';
  ans[in][x][y] = 0;
  while(!q.empty()){
    inX = q.front().first;
    inY = q.front().second;
    q.pop();
    for(int i = 0; i < 8; i++){
      if(val( inX + dx[i] , inY + dy[i]) && ans[in][ inX+dx[i] ][ inY+dy[i] ] == -1){
        ans[in][ inX+dx[i] ][ inY+dy[i] ] = ans[in][inX][inY] + 1;
        q.push( mp( inX+dx[i],inY+dy[i] ) );
      }
    }
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(ans[in][i][j] == -1) ans[in][i][j] = inf;
      else ans[in][i][j] = (ans[in][i][j] + k - 1) / k;
    }
  }
}
  int main(){
  for(scanf("%d", &tc); t <= tc; t++){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) scanf("%s", a[i]);
    cnt = 0;
    memset(ans, -1, sizeof(ans));
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        if(a[i][j] != '.') bfs(i, j, cnt), ++cnt;
      }
    }
    fin = inf;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        cur = 0;
        for(int p = 0; p < cnt; p++){
          if(ans[p][i][j] == inf){
            cur = inf;
            break;
          }
          cur += ans[p][i][j];
        }
        fin = min(fin, cur);
      }
    }
    printf("Case %d: %d\n", t, fin >= inf ? -1 : fin );
  }
    return 0;
}