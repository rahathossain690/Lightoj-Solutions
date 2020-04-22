#include <stdio.h>
#include<math.h>
int a, b, c, d, e, f,kk[10010];
int fn( int n ) {
    if( n == 0 ) return a;
    if( n == 1 ) return b;
    if( n == 2 ) return c;
    if( n == 3 ) return d;
    if( n == 4 ) return e;
    if( n == 5 ) return f;
    if(kk[n]!=0) return kk[n];
    else
    {
    kk[n]=( fn(n-1) % 10000007 + fn(n-2) % 10000007 + fn(n-3) % 10000007 + fn(n-4) % 10000007 + fn(n-5) % 10000007 + fn(n-6) % 10000007 ) % 10000007;
    //printf("%d\n",kk[n]);
    return kk[n];
    }
}
int main() {
    int n, caseno = 0, cases;
    scanf("%d", &cases);
    while( cases-- ) {
        for(int i=0;i<10010;i++)kk[i]=0;
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);
        printf("Case %d: %d\n", ++caseno, fn(n) % 10000007);
    }
    return 0;
}