#include <bits/stdc++.h>
using namespace std;
  typedef long long ll;
typedef pair<int, int> pii;
#define pb            push_back
#define endl          "\n"
#define mp          make_pair
const int sz = 1001;
  int ans, t, tc, n, x[sz], y[sz], cur = 0;
vector<pii> r;
pii temp;
  int main(){
  for(scanf("%d", &tc); t < tc; t++){
    r.clear();
    ans = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d %d", x + i, y + i);
    for(int i = 0; i < n; i++)
      for(int j = i + 1; j < n; j++)
        temp.first = x[i] + x[j], temp.second = y[i] + y[j], r.pb(temp);
    sort(r.begin(), r.end());
    ans = cur = 0;
    for(int i = 1; i < r.size(); i++){
      if(r[i] == r[i-1]) cur++;
      else ans += (cur * (cur + 1)) / 2, cur = 0;
    }
    ans += (cur * (cur + 1)) / 2;
    printf("Case %d: %d\n", t + 1, ans);
  }
    return 0;
}