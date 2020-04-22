#include<bits/stdc++.h>
using namespace std;
  int main(){
    int t,q;
    scanf("%d",&t);
    q=t;
    while(t--){
        long double r1,r2,h,p,H,a,r,pi=(2*acos(0.0))/3.0;
        scanf("%Lf%Lf%Lf%Lf",&r1,&r2,&h,&p);
        H = h/(1-(r2/r1));
        r = r1*(H-h+p)/H;
        a = pi*r*r*(H-h+p) - pi*r2*r2*(H-h);
        printf("Case %d: %.9Lf\n",q-t,a);
    }
    return 0;
}