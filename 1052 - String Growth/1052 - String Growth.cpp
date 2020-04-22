#include<bits/stdc++.h>
using namespace std;
  typedef long long ll;
typedef pair< pair<ll, ll>, pair<ll, ll> > MAT;
#define createMat(a,b,c,d)    make_pair(make_pair(a,b),make_pair(c,d))
#define printMat(AA)          cerr << AA.first.first << " " << AA.first.second << endl << AA.second.first << " " << AA.second.second << endl;
const ll mod = 1000000007;
  MAT st = createMat(0, 1, 1, 1), I = createMat(1, 0, 0, 1), f_N, f_M, f_K;
int N, M, X, Y, K;
ll p, q, ans;
int t, tc;
  MAT mul(MAT a, MAT b){
  MAT ans;
  ans.first.first = (a.first.first * b.first.first + a.first.second * b.second.first) % mod;
  ans.first.second = (a.first.first * b.first.second + a.first.second * b.second.second) % mod;
  ans.second.first = (a.second.first * b.first.first + a.second.second * b.second.first) % mod;
  ans.second.second = (a.second.first * b.first.second + a.second.second * b.second.second) % mod;
  return ans;
}
  MAT exp(MAT mat, ll p){
  if(p == 0) return I;
  MAT ans = exp(mat, p / 2);
  ans = mul(ans, ans);
  if(p % 2 == 1) ans = mul(ans, mat);
  return ans;
}
  int solve(){
  scanf("%d%d%d%d%d", &N, &X, &M, &Y, &K);
  f_N = exp(st, N - 1LL);
  f_M = exp(st, M - 1LL);
  ll A = f_N.first.first + f_N.second.first, B = f_N.first.second + f_N.second.second;
  ll C = f_M.first.first + f_M.second.first, D = f_M.first.second + f_M.second.second;
    //printMat(f_N);
  //cout << endl;
  //printMat(f_M);
  //cout << endl;
    //cout << A << " " << B << endl << C << " " << D << endl;
    if(A * D == B * C) puts("Impossible");
  else if((D * X - B * Y) % (A * D - B * C) != 0 || (A * Y - C * X) % (A * D - B * C) != 0) puts("Impossible");
  else{
    p = (D * X - B * Y) / (A * D - B * C);
    q = (A * Y - C * X) / (A * D - B * C);
      //cout << (D * X - B * Y) << " " << (A * D - B * C) << " " << (A * Y - C * X) << " " << (A * D - B * C) << endl;
      if(p < 0 || q < 0) {
        puts("Impossible");
        return 0;
    }
      f_K = exp(st, K - 1);
    ans = (p * (f_K.first.first + f_K.second.first)) + (q * (f_K.first.second + f_K.second.second));
    ans %= mod;
    if(ans < 0) ans += mod;
    printf("%lld\n", ans);
  }
  return 0;
}
  int main(){
  for(scanf("%d", &tc); t < tc; printf("Case %d: ", ++t), solve());
}