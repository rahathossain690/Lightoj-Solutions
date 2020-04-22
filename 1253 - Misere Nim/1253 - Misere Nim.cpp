#include<bits/stdc++.h>
using namespace std;
  typedef long long ll;
  const int N = 101;
  int t, tc, n, c[N];
  int main(){
    for(scanf("%d", &tc); t < tc; t++){
        scanf("%d", &n);
        int one = 0;
        for(int i = 0; i < n; i++) scanf("%d", c + i), one += c[i] == 1;
        int ans = 0;
        for(int i = 0; i < n; i++) ans ^= c[i];
        if(one == n) ans = 1 - n % 2;
        printf("Case %d: %s\n", t + 1, ans ? "Alice" : "Bob");
    }
}