#include "bits/stdc++.h"
using namespace std;
  #define max(a,b) (a>b?a:b)
  int n, a[1001], m;
  bool solvable(long long tot){
  vector<int> p;
  int cont  = 0;
  for(int i = 0; i < n;  i++){
    if(cont + a[i] <= tot && i != n-1) cont += a[i];
    else if(cont + a[i] <= tot && i == n-1) p.push_back(cont+a[i]);
    else {
      p.push_back(cont);
      if(i == n-1) p.push_back(a[i]);
      else cont = a[i];
    }
  }
  //cout << tot << " " << p.size() << endl;
  return p.size() <= m;
}
  int solve(){
  scanf("%d%d",&n,&m);
  long long hi = 1000000000000, mid, lo = 0;
  for(int i = 0; i<n; i++) scanf("%d",&a[i]), lo = max(a[i],lo);
  while(lo < hi){
    mid = (lo + hi)/ 2;
    if(solvable(mid))hi = mid;
    else lo = mid + 1;
  }
  printf("%d\n",lo);
}
  int main(){     //freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
  int t = 1,tc;
  for(scanf("%d",&tc); t <=tc; t++){
    printf("Case %d: ",t);
    solve();
  }
}