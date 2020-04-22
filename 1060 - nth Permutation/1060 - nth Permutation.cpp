#include<bits/stdc++.h>
using namespace std;
  typedef long long ll;
  const int N = 22;
  ll n, f[N];
char ss[N];
string s, ans;
int hz[200], t, tc;
  ll count(){
  ll ans = 0;
  for(int i = (int)'a'; i <= (int)'z'; i++) ans += hz[i];
  ans = f[ans];
  for(int i = (int)'a'; i <= (int)'z'; i++) ans /= f[ hz[i] ];
  return ans;
}
  int main(){
  f[0] = 1;
  for(int i = 1; i < N; i++) f[i] = i * f[i - 1];
  for(scanf("%d", &tc); t < tc; t++){
    scanf("%s %lld", ss, &n);
    s = ss;
    sort(s.begin(), s.end());
    s = '$' + s;
    memset(hz, 0, sizeof hz);
    ans = "";
    for(int i = 1; i < s.size(); i++) hz[ s[i] ]++;
    if(count() < n){
      ans = "Impossible";
      goto SHESH;
    }
    for(int cnt = 1; cnt < s.size(); cnt++){
      for(int i = 1; i < s.size(); i++){
        if(s[i] == s[i - 1] || s[i] == '$') continue;
        hz[ s[i] ]--;
        ll temp = count();
        if(n > temp) n -= temp, hz[s[i]]++;
        else {
          ans += s[i];
          s[i] = '$';
          break;
        }
      }
    }
    SHESH: printf("Case %d: %s\n", t + 1, ans.c_str());
  }
}