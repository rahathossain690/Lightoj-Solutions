#include "bits/stdc++.h"
using namespace std;
  vector <int> bosta[2];
int n, k, a[18];
  void create(int add, int in, int lim, int rex){
  if(in == lim){
    bosta[rex].push_back(add);
    return;
  }
  create(add, in + 1, lim, rex);
  create(add + a[in], in + 1, lim, rex);
  create(add + 2 * a[in], in + 1, lim, rex);
}
  int main(){
  #ifndef ONLINE_JUDGE
    double _CL_ = clock();
  #endif
  int t = 1, tc = 0;
  for(scanf("%d", &tc); t <= tc; t++){
    scanf("%d %d", &n, &k);
    bosta[0].clear();
    bosta[1].clear();
    for(int i = 0; i < n; i++) scanf("%d", a + i);
    printf("Case %d: ", t);
    create(0, 0, n / 2, 0);
    create(0, n / 2, n, 1);
    bosta[0].push_back(0), bosta[1].push_back(0);
    sort(bosta[1].begin(), bosta[1].end());
    bool hobe = false;
    for(int i = 0; i < bosta[0].size(); i++){
      if(binary_search(bosta[1].begin(), bosta[1].end(), k - bosta[0][i])){
        hobe = true;
        break;
      }
    }
    printf(hobe?"Yes\n":"No\n");
  }
  #ifndef ONLINE_JUDGE
    printf("\n\nE = %lf\n", (clock() - _CL_)/1000);
  #endif
  return 0;
}