#include <bits/stdc++.h>
using namespace std;
  int main() {
    ios_base::sync_with_stdio(false);
    int t,q;
    cin>>t;
    q=t;
    while(t--){
        long double ab,bc,cd,k;
        cin>>ab>>bc>>cd>>k;
        printf("Case %d: %.10Lf\n",q-t,ab*(1/sqrt(1+(1/k))));
    }
    return 0;
}