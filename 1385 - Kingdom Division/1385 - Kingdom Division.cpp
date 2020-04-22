#include <bits/stdc++.h>
using namespace std;
  int main() {
    int t,qq;
    scanf("%d",&t);
    qq=t;
    while(t--){
        double a,b,c,p,q;
        scanf("%lf%lf%lf",&a,&b,&c);
        p = (a*c)/b;
        if(b>p)q = (p*a + p*p + c*a + p*c)/(b-p);
        else p=-1,q=0;
        printf("Case %d: %.7lf\n",qq-t,p+q);
    }
    return 0;
}