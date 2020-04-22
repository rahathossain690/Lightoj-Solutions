#include "stdio.h"
#include <math.h>
int main(void) {
    int t;
    scanf("%d",&t);
    int q=t;
    while(t--){
    double a;
    scanf("%lf",&a);
    printf("Case %d: %.2lf\n",q-t,4*a*a-2*acos(0.0)*a*a);
    }
    return 0;
    }