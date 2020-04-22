#include <bits/stdc++.h>
using namespace std;
int t, tc;
double n, ans, i;
int main(){
  for(scanf("%d", &tc); t < tc; printf("Case %d: %.10lf\n", ++t, ans)){
    scanf("%lf", &n);
    for(i = 1, ans = 0; i <= n; ans += n / i, i++);
  }
}