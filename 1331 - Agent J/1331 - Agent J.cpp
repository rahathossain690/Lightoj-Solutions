#include<bits/stdc++.h>
using namespace std;
  int main()
{
    int q,t;
    scanf("%d",&t);
    q=t;
    while(t--){
        double r1,r2,r3,area;
        scanf("%lf%lf%lf",&r1,&r2,&r3);
        double a = r1+r2,b=r2+r3,c=r3+r1,s;
        s = (a+b+c)/2;
        area = sqrt(s*(s-a)*(s-b)*(s-c));
        double an1,an3,an2,pi;
        pi =2*acos(0.0);
        an1 = acos((a*a-b*b+c*c)/(2*a*c));
        //an1 = 2*pi*r1 / an1;
        an2 = acos((a*a+b*b-c*c)/(2*a*b));
        //an2 = 2*pi*r2 / an2;
        an3 = acos((c*c-a*a+b*b)/(2*c*b));
        //an3 = 2*pi*r3 / an3;
        area = area - 0.5*(r1*r1*an1+r2*r2*an2+r3*r3*an3);
        printf("Case %d: %.8lf\n",q-t,area);
    }
    return 0;
}