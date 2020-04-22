#include "bits/stdc++.h"
    using namespace std;
          typedef long long ll;
    const int sz = 50010;
          ll row[sz], col[sz];
    int m, n, q, r, c, w, ansr, ansc;
          int main(){
      int t = 1, tc;
      for(scanf("%d", &tc); t <= tc; t++){
        scanf("%d %d %d", &m, &n, &q);
        for(int i = 0; i < q; i++){
          scanf("%d %d %d", &r, &c, &w);
          row[r] += w;
          col[c] += w;
        }
        for(int i = 1; i <= m; i++) row[i] += row[i-1];
        for(int i = 1; i <= n; i++) col[i] += col[i-1];
        if(row[m] % 2 == 1){
          ansr = lower_bound(row, row + m, (row[m]+1)/2 ) - row;
        }
        else{
          ansr = ( (lower_bound(row, row + m, row[m] / 2) - row) + (lower_bound(row, row + m, 1 + row[m]/2) - row) )/ 2;
        }
        if(col[n] % 2 == 1){
          ansc = (lower_bound(col, col + n, (col[n]+1)/2 ) - col);
        }
        else{
          ansc = ((lower_bound(col, col + n, col[n] / 2) - col) + (lower_bound(col, col + n, 1 + col[n]/2) - col) )/ 2;
        }
        printf("Case %d: %d %d\n", t, ansr, ansc);
        for(int i = 1; i <= m; i++) row[i] = 0;
        for(int i = 1; i <= n; i++) col[i] = 0;
      }
      return 0;
    }