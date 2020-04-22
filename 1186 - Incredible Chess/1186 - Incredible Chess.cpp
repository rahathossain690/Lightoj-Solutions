#include<bits/stdc++.h>
using namespace std;
  const int N = 102;
  int t, tc, n, w[N], b[N];
  int main(){
    for(scanf("%d", &tc); t < tc; t++){
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%d", w + i);
        for(int i = 0; i < n; i++) scanf("%d", b + i);
        int ans = 0;
        for(int i = 0; i < n; i++) ans ^= (b[i] - w[i] - 1);
        printf("Case %d: %s\n", t + 1, ans? "white wins" : "black wins");
    }
}