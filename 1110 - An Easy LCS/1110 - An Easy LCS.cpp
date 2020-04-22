#include <bits/stdc++.h>
using namespace std;
  typedef long long ll;
typedef pair<int, int> pii;
#define pb          push_back
#define endl        "\n"
#define mp          make_pair
#define min(a,b)    (a<b?a:b)
#define max(a,b)    (a>b?a:b)
const int sz = 101;
  string a, b, c;
char aa[sz], bb[sz];
map<pii, string> dp;
int t = 1, tc;
  bool larger(string p, string q){
  for(int i = 0; i < p.size(); i++){
    if(p[i] > q[i]) return 0;
    if(p[i] < q[i]) return 1;
  }
  return 1;
}
  string get(int m, int n){
  if(m == a.size() || n == b.size()) return "";
  if(dp.find( mp(m, n) ) != dp.end()) return dp[ mp(m, n) ];
  string ans = "";
  if(a[m] == b[n]) ans = a[m] + get(m + 1, n + 1);
  else {
    string ans1 = get(m + 1, n);
    string ans2 = get(m, n + 1);
    if(ans1.size() > ans2.size()) ans = ans1;
    else if(ans1.size() < ans2.size()) ans = ans2;
    else ans = larger(ans1, ans2)? ans1 : ans2;
  }
  return dp[ mp(m, n) ] = ans;
}
  int main(){
  for(scanf("%d", &tc); t <= tc; t++){
    scanf("%s%s", aa, bb);
    a = aa, b = bb;
    dp.clear();
    get(0, 0);
    printf("Case %d: ", t);
    if(dp[ mp(0, 0) ] == "") puts(":(");
    else printf("%s\n", dp[ mp(0, 0) ].c_str());
  }
    return 0;
}