#include<bits/stdc++.h>
using namespace std;
  int main()
{
    int q,t;
    scanf("%d",&t);
    q=t;
    while(t--){
    double ox,oy,ax,ay,bx,by,r,c,s;
    scanf("%lf%lf%lf%lf%lf%lf",&ox,&oy,&ax,&ay,&bx,&by);
    r = sqrt((ox-ax)*(ox-ax)+(oy-ay)*(oy-ay));
    c = sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by));
    c = 1 - (c*c)/(2*r*r);
    c = acos(c);
    s = r*c;
    printf("Case %d: %lf\n",q-t,s);
    }
    return 0;
}