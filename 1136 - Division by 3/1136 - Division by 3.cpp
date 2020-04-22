#include <stdio.h>
int main()
{
    int a,b,c,d,e,f,g,h,i,j,k,l,m,n;
    scanf("%d", &a);
    for(b=1; b<=a; b++)
    {
        scanf("%d%d", &c, &d);
        e=(c/3)*2;
        f=c%3;
        if(f==2)
            e+=1;
        i=(d/3)*2;
        j=d%3;
        if(j==2)
            i+=1;
        m=i-e;
        m+=1;
        if(f==1)
            m-=1;
        printf("Case %d: %d\n",b,m);
    }
    return 0;
}