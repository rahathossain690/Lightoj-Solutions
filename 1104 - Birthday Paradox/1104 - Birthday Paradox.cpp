#include <bits/stdc++.h>
using namespace std;
  int main() {
    int t,q;
    scanf("%d",&t);
    q=t;
    while(t--){
        double d,dd;
        int b=1;
        scanf("%lf",&d);
        if(d==1){
            printf("Case %d: 1\n",q-t);
            continue;
        }
        dd=d-1;
        double k=1;
        while(k>0.5&&dd){
            k *= (dd/d);
            dd--;
            b++;
        }
        printf("Case %d: %d\n",q-t,b-1);
    }
    return 0;
}