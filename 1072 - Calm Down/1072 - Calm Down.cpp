#include<bits/stdc++.h>
using namespace std;
  int main(){
    int t,q;
    scanf("%d",&t);
    q=t;
    while(t--){
        double a,pi=2*acos(0.0);
        int b;
        scanf("%lf%d",&a,&b);
        double sino=sin(pi/b);
        double r = (a*sino)/(1+sino);
        printf("Case %d: ",q-t);
        if((int)r!=r)printf("%.10lf",r);
        else printf("%.0lf",r);
        printf("\n");
    }
    return 0;
}