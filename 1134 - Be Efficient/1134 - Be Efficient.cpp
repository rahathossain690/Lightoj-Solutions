#include <bits/stdc++.h>
using namespace std;
  typedef long long       ll;
typedef pair<int, int>  pii;
#define pb              push_back
#define endl            "\n"
#define mp              make_pair
const int sz = (int)5e5 + 10;
  int t, tc, n, a, sum, m, mod[sz];
ll ans;
  int main(){
  for(scanf("%d", &tc); t < tc; t++){
    scanf("%d %d", &n, &m);
    memset(mod, 0, sizeof mod);
    sum = 0;
    for(int i = 1; i <= n; i++) scanf("%d", &a), sum = (a + sum) % m, mod[ sum ]++;
    ans = mod[0];
    for(int i = 0; i < m; i++) ans += (mod[i] * 1LL * (mod[i] - 1)) / 2;
    printf("Case %d: %lld\n", t + 1, ans);
  }
}