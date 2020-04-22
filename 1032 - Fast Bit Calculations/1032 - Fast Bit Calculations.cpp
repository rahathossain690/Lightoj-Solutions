#include <bits/stdc++.h>
using namespace std;
  typedef long long       ll;
typedef pair<int, int>  pii;
#define pb              push_back
#define endl            "\n"
#define mp              make_pair
const int sz = 1e5 + 5;
  int t, tc, l;
ll n, dp[35][2][2][35];
bool a[50];
  void bin(ll n){
  l = 0;
  while(n > 0){
    a[l++] = n % 2;
    n /= 2;
  }
}
  ll go(int in, bool prev, bool tgt, int fin){
  if(in == -1) return fin;
  if(dp[in][prev][tgt][fin] != -1) return dp[in][prev][tgt][fin];
  ll ans = 0;
  if(tgt){
    if(a[in]){
      ans += go(in - 1, 1, 1, fin + (prev == 1));
      ans += go(in - 1, 0, 0, fin);
    }
    else ans += go(in - 1, 0, 1, fin);
  }
  else{
    ans += go(in - 1, 1, 0, fin + (prev == 1));
    ans += go(in - 1, 0, 0, fin);
  }
  return dp[in][prev][tgt][fin] = ans;
}
  int main(){
  for(scanf("%d", &tc); t < tc; t++){
    scanf("%lld", &n);
    printf("Case %d: ", t + 1);
    if(n == 0) {
      puts("0");
      continue;
    }
    memset(a, 0, sizeof a);
    memset(dp, -1, sizeof dp);
    bin(n);
    printf("%lld\n", go(l - 1, 0,  1, 0));
  }
    return 0;
}