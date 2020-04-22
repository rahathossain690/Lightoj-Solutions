#include <bits/stdc++.h>
using namespace std;
  int t, tc, n, a, b, c, m[5][5], x[5][5], ans, mod = 10007;
  void mul(int a[][5], int b[][5]){
  int l[5][5];
  for(int i = 0; i < 4; i++)
  for(int j = 0; j < 4; j++){
    l[i][j] = 0;
    for(int k = 0; k < 4; k++)
      l[i][j] = (l[i][j] + a[i][k] * b[k][j]) % mod;
  }
  for(int i = 0; i < 4; i++)
  for(int j = 0; j < 4; j++)
  a[i][j] = l[i][j];
}
  void power(int a[][5], int p){
  if(p == 1) return;
  power(a, p / 2);
  mul(a, a);
  if(p % 2 == 1) mul(a, m);
}
  int main(){
  for(scanf("%d", &tc); t < tc; t++){
    scanf("%d %d %d %d", &n, &a, &b, &c);
    printf("Case %d: ", t + 1);
    if(n <= 2) {
      printf("0\n");
      continue;
    }
    memset(x, 0, sizeof x);
    m[0][0] = x[0][0] = a;
    m[0][2] = x[0][2] = b;
    m[0][3] = x[0][3] = c;
    m[1][0] = m[2][1] = m[3][3] = x[1][0] = x[2][1] = x[3][3] =  1;
    power(x, n - 2);
    ans = 0;
    printf("%d\n", x[0][3]);
  }
}