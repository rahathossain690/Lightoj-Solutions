#include <bits/stdc++.h>
using namespace std;
  int main() {
    int t,q;
    scanf("%d",&t);
    q=t;
    while(t--){
        long double a,b,c,d,s,A,h;
        scanf("%Lf%Lf%Lf%Lf",&a,&b,&c,&d);
                    if(a<c){
                long double temp = a;
                a=c;
                c=temp;
            }
            s = (b+a+d-c)/2;
            A = sqrt(s*(s-b)*(s-d)*(s-a+c));
            h= (2*A)/(a-c);
            A+=(h*c);
                printf("Case %d: %0.7Lf\n",q-t,A);
    }
    return 0;
}