#include "bits/stdc++.h"
using namespace std;
  typedef long long ll;
typedef pair<int, int> pii;
#define pb          push_back
#define endl        "\n"
#define mp          make_pair
#define min(a,b)    (a<b?a:b)
#define max(a,b)    (a>b?a:b)
const int sz = 101;
  int n, dis[sz], t = 1, tc, u, v, w, fno, sno, taken;
ll minCost, maxCost;
  int FIND(int cur){
  if(dis[cur] < 0) return cur;
  return FIND(dis[cur]);
}
  int main(){
  for(scanf("%d", &tc); t <= tc; t++){
    priority_queue < pair<int, pii>, vector< pair<int, pii> >, greater< pair<int, pii> > > minQ;
    priority_queue < pair<int, pii> > maxQ;
    scanf("%d", &n);
    while(1){
      scanf("%d %d %d", &u, &v, &w);
      if(u == 0 && v == 0) break;
      minQ.push( mp( w, mp(u, v)) );
      maxQ.push( mp( w, mp(u, v)) );
    }
    memset(dis, -1, sizeof dis);
    minCost = 0, taken = 0;
    while(!minQ.empty()){
      pair<int, pii> temp = minQ.top();
      minQ.pop();
      w = temp.first;
      u = temp.second.first;
      v = temp.second.second;
      fno = FIND(u);
      sno = FIND(v);
      if(fno == sno) continue;
      minCost += w;
      taken++;
      if(dis[fno] <= dis[sno]){
        dis[fno] += dis[sno];
        dis[sno] = fno;
      }
      else {
        dis[sno] += dis[fno];
        dis[fno] = sno;
      }
      if(taken == n) break;
    }
    maxCost = 0, taken = 0;
    memset(dis, -1, sizeof dis);
    while(!maxQ.empty()){
      pair<int, pii> temp = maxQ.top();
      maxQ.pop();
      w = temp.first;
      u = temp.second.first;
      v = temp.second.second;
      fno = FIND(u);
      sno = FIND(v);
      if(fno == sno) continue;
      maxCost += w;
      taken++;
      if(dis[fno] <= dis[sno]){
        dis[fno] += dis[sno];
        dis[sno] = fno;
      }
      else {
        dis[sno] += dis[fno];
        dis[fno] = sno;
      }
      if(taken == n) break;
    }
    printf("Case %d: ", t);
    if( (minCost + maxCost) % 2 == 0 ){
      printf("%lld\n", (minCost + maxCost) / 2);
    }
    else printf("%lld/2\n", minCost + maxCost);
  }
    return 0;
}