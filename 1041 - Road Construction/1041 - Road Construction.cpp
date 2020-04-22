#include <bits/stdc++.h>
using namespace std;
  typedef long long ll;
typedef pair<int, int> pii;
#define pb          push_back
#define endl        "\n"
#define mp          make_pair
#define min(a,b)    (a<b?a:b)
#define max(a,b)    (a>b?a:b)
const int sz = 102;
  int t = 1, tc, u, v, w, c, n, cost, cn;
vector<pii> node[sz];
pii temp;
string nem;
char neme[52];
bool hobe;
map<string, int> dict;
  int tek(){
  scanf("%s", neme);
  nem = neme;
  return dict[nem] = dict[nem] == 0? ++c : dict[nem];
}
  int main(){
  for(scanf("%d", &tc); t <= tc; t++){
    scanf("%d", &n);
    hobe = cost = c = 0;
    dict.clear();
    for(int i = 1; i <= cn; i++) node[i].clear();
    for(int i = 0; i < n; i++){
      u = tek();
      v = tek();
      scanf("%d", &w);
      node[u].pb( mp(v, w) );
      node[v].pb( mp(u, w) );
    }
    cn = c;
    set <int> ans;
    priority_queue<pii, vector<pii>, greater<pii> > q;
    q.push( mp(0, 1) );
    while(!q.empty()){
      temp = q.top();
      q.pop();
      if(ans.find( temp.second ) == ans.end()){
        ans.insert(temp.second);
        cost += temp.first;
        v = temp.second;
        --c;
        if(c == 0){
          hobe = true;
          break;
        }
        for(int i = 0; i < node[v].size(); i++)
          q.push( mp( node[v][i].second , node[v][i].first) );
      }
    }
    printf("Case %d: ", t);
    if(hobe) printf("%d\n", cost);
    else puts("Impossible");
  }
    return 0;
}