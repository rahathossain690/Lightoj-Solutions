#include <bits/stdc++.h>
using namespace std;
  typedef pair<int, pair<int, int> > Pair;
const int N = 505;
  int n, t, tc, a[N];
unsigned int BIT[N][N], ans, temp;
vector< Pair > w;
  void update(int x, int y, unsigned int val){
  for(; x <= n; x += x & -x){
    for(int y1 = y; y1 <= n; y1 += y1 & -y1) BIT[x][y1] += val;
  }
}
  int query(int x, int y){
  int sum = 0;
  for(; x > 0; x -= x & -x){
    for(int y1 = y; y1 > 0; y1 -= y1 & -y1) sum += BIT[x][y1];
  }
  return sum;
}
  bool comp(Pair &a, Pair &b){
  if(a.first == b.first){
    return a.second.second - a.second.first > b.second.second - b.second.first;
  }
  return a.first < b.first;
}
  unsigned int gofor(int l, int r){
  if(l + 1 == r) return 0;
  l++, r--;
  return query(r, r) - query(r, l - 1) - query(l - 1, r) + query(l - 1, l - 1);
}
  int main(){
  for(scanf("%d", &tc); t < tc; t++){
    scanf("%d", &n);
    w.clear();
    ans = 0;
    memset(BIT, 0, sizeof BIT);
    for(int i = 1; i <= n; i++) scanf("%d", a + i);
    for(int i = 1; i <= n; i++){
      for(int j = i + 1; j <= n; j++){
        w.push_back( make_pair( a[i] + a[j], make_pair(i, j) ) );
      }
    }
    sort(w.begin(), w.end(), comp);
    for(int i = 0; i < w.size(); i++){
      temp = gofor(w[i].second.first, w[i].second.second) + 1;
      ans += temp;
      update(w[i].second.first, w[i].second.second, temp);
    }
    printf("Case %d: %u\n", t + 1, ans);
  }
}