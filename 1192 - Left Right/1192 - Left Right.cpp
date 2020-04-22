#include<bits/stdc++.h>
using namespace std;
  const int N = 203;
  int t, tc, n, a[N];
  int main(){
    for(scanf("%d", &tc); t < tc; t++){
        scanf("%d", &n);
        for(int i = 0; i < n + n; i++) scanf("%d", a + i);
        int ans = 0;
        for(int i = 1; i < n + n; i += 2) ans ^= (a[i] - a[i - 1] - 1);
        printf("Case %d: %s\n", t + 1, ans ? "Alice" : "Bob");
    }
}