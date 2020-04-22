#include <bits/stdc++.h>
using namespace std;
  typedef long long       ll;
typedef pair<int, int>  pii;
#define pb              push_back
#define endl            "\n"
#define mp              make_pair
const int sz = 705;
  int x[sz], y[sz], n, g, t, tc, ans;
map<pii, int> s;
map<pii, int> :: iterator it;
  int main(){
  for(scanf("%d", &tc); t < tc; t++){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d %d", x + i, y + i);
    ans = 0;
    for(int i = 0; i < n; i++){
      s.clear();
      for(int j = i + 1; j < n; j++){
        if(y[j] == y[i] && x[j] == x[i]) s[mp(-10000001, -1)]++, s[mp(-10000001, 1)]++; // for same point
        else if(y[j] == y[i]) s[mp(-10000001, -1)]++; // for horizontal line
        else if(x[j] == x[i]) s[mp(-10000001, 1)]++; // for vertical line
        else {
          g = __gcd( abs(x[j] - x[i]) , abs(y[j] - y[i]) );
          s[mp( (y[j] - y[i]) / g, (x[j] - x[i]) / g) ]++;
        }
      }
      for(it = s.begin(); it != s.end(); it++) ans = max(ans, it->second);
    }
    printf("Case %d: %d\n", t + 1, ans + 1);
  }
    return 0;
}