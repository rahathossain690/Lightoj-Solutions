#include<bits/stdc++.h>
using namespace std;
  typedef pair<int, int> Pair;
const int N = 150100;
  int t, tc, n, q, u, v, cur;
vector<int> point;
map<int, int> store;
map<int, int> :: iterator it;
vector<Pair> seg;
int f[N], occu[N];
  void clear(){
  memset(f, 0, sizeof f);
  memset(occu, 0, sizeof occu);
  store.clear();
  seg.clear();
  point.clear();
  store[0] = store[100000000] = 0;
  cur = 1;
}
  int solve(){
  clear();
  scanf("%d %d", &n, &q);
  for(int i = 0; i < n; i++) {
    scanf("%d %d", &u, &v);
    store[u] = store[v] = 0;
    seg.push_back( make_pair(u, v) );
  }
  for(int i = 0; i < q; i++){
    scanf("%d", &u);
    store[u] = 0;
    point.push_back(u);
  }
  for(it = store.begin(); it != store.end(); it++) {
    store[ it->first ] = cur++;
  }
  for(int i = 0; i < seg.size(); i++){
    f[ store[ seg[i].first] - 1]--;
    f[ store[seg[i].second] ]++;
  }
  cur = 0;
  for(int i = store[100000000]; i >= 0; i--){
    cur += f[i];
    occu[i] = cur;
  }
  for(int i = 0; i < point.size(); i++){
    printf("%d\n", occu[ store[ point[i] ] ]);
  }
  return 0;
}
  int main(){
  for(scanf("%d", &tc); t < tc; printf("Case %d:\n", ++t), solve());
}