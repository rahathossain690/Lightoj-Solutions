#include "bits/stdc++.h"
using namespace std;
    #define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define ll long long
  int n, k, a[1005];
bool c[1005];
  bool solvable(int mid){
  vector<int> p;
  int cont = 0;
  for(int i = 0; i < n; i++){
    if(cont + a[i] <= mid && i != n-1) cont += a[i];
    else if (cont + a[i] <= mid && i == n-1) p.push_back(cont+a[i]);
    else {
      p.push_back(cont);
      if(i == n-1) p.push_back(a[i]);
      cont = a[i];
    }
  }
  return p.size() <= k;
}
  void final(int mid){
  vector<int>p;
  int cont = 0, s = 0, pack = n-k+1;
  if(pack == 0){
    printf("%d\n",mid);
    for(int i = 0; i<n; i++)printf("%d\n",a[i]);
    return;
  }
  //cout << s << " " << pack << "*()*" << endl;
  for(int i = 0; i < n; i++){
    if(s == pack) {
      p.push_back(cont);
      for(;i < n; i++) p.push_back(a[i]);
      break;
    } //cout << i << s << " " << pack << endl;
    if(cont + a[i] <= mid && i != n-1) cont += a[i], s++;
    else if (cont + a[i] <= mid && i == n-1) p.push_back(cont+a[i]),s++;
    else {
      p.push_back(cont);
      if(i == n-1) p.push_back(a[i]);
      cont = a[i];
    }
  }
  printf("%d\n",mid);
  for(int i = 0; i < p.size(); i++) printf("%d\n",p[i]);
}
  void solve(){
  scanf("%d%d",&n,&k);
  n++,k++;
  int hi = 0,lo = -1,mid;
  for(int i = 0; i < n; i++) scanf("%d",&a[i]),lo = max(lo,a[i]), hi += a[i];
  while(lo<hi){
    mid = (lo+hi) / 2;
    if(solvable(mid)) hi = mid;
    else lo = mid + 1;
  }
  final(lo);
}
  int main(){
  int t = 1, tc;
  for(scanf("%d",&tc); t <= tc; t++){
    printf("Case %d: ",t);
    solve();
  }
}