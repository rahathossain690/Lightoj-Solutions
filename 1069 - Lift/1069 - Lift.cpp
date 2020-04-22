#include <stdio.h>
  int main()
{
    int t;
    scanf("%d",&t);
    int l=t;
    while(t--){
    int a,b;
    scanf("%d%d",&a,&b);
    int q = a - b;
    if(q<0){
        q=q*(-1);
    }
    int p = ((q+a)*4)+19;
    printf("Case %d: %d\n",l-t,p);
}
    return 0;
}