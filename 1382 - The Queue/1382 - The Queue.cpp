#include<bits/stdc++.h>
using namespace std;
  typedef long long ll;
const int N = 1002;
const ll mod = 1000000007;
#define modinv(k)   (bigmod(k, mod - 2))
  vector<int> node[N];
int t, tc, n, u, v, under[N], head;
ll f[N];
bool ch[N];
  void clear(){
  memset(ch, 0, sizeof ch);
  memset(under, 0, sizeof under);
  head = 0;
  for(int i = 1; i <= n; i++) node[i].clear();
}
  ll bigmod(ll a, ll b){
  if(b == 0) return 1;
  ll ans = bigmod(a, b / 2);
  ans = (ans * ans) % mod;
  if(b&1) ans = (ans * a) % mod;
  return ans;
}
  ll dfs(int u){
  ll ans1 = 1, ans2 = 1;
  for(int i = 0; i < node[u].size(); i++){
    ans1 = (ans1 * dfs(node[u][i])) % mod;
    ans2 = (ans2 * f[ under[ node[u][i] ] ]) % mod;
  }
  ans1 = (modinv(ans2) * ans1) % mod;
  return (f[ under[u] - 1 ] * ans1) % mod;
}
  int discover(int u){
  int ans = 1;
  for(int i = 0; i < node[u].size(); i++) ans += discover(node[u][i]);
  return under[u] = ans;
}
  long long solve(){
  scanf("%d", &n);
  clear();
  for(int i = 1; i < n; i++){
    scanf("%d %d", &u, &v);
    node[u].push_back(v);
    ch[v] = 1;
  }
  for(int i = 1; i <= n && !head; i++) if(!ch[i]) head = i;
  discover(head);
  return dfs(head);
}
  int main(){
  f[0] = 1; for(int i = 1; i < N; i++) f[i] = (i * f[i - 1]) % mod;
  for(scanf("%d", &tc); t < tc; printf("Case %d: %lld\n", ++t, solve()));
}