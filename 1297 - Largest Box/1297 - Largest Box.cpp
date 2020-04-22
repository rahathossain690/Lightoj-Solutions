#include <bits/stdc++.h>
using namespace std;
  int main() {
    ios_base::sync_with_stdio(false);
    int t,q;
    scanf("%d",&t);
    q=t;
    while(t--){
        long double l,w,x;
        scanf("%Lf%Lf",&l,&w);
        x=(4*(l+w)-sqrt(16*(l+w)*(l+w)-48*l*w))/24;
        printf("Case %d: %.9Lf\n",q-t,x*(l-2*x)*(w-2*x));
    }
    return 0;
}