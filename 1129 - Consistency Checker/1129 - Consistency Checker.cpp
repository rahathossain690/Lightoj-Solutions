#include <bits/stdc++.h>
using namespace std;
  vector<string> s(10005);
string q;
char temp[15];
int t, tc, n, hobe;
  bool match(string a, string b){
  for(int i = 0; i < a.size() && i < b.size(); i++) if(a[i] != b[i]) return false;
  return true;
}
  int main(){
  for(scanf("%d", &tc); t < tc; t++){
    s.clear();
    hobe = 1;
    scanf("%d", &n);
    while(n--)scanf("%s", temp), q = temp, s.push_back(q);
    sort(s.begin(), s.end());
    for(int i = 0; i < s.size() - 1 && hobe; i++) if(match(s[i], s[i + 1])) hobe = false;
    printf("Case %d: %s\n", t + 1, hobe ? "YES" : "NO");
  }
}