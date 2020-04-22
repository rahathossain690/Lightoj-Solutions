#include <bits/stdc++.h>
using namespace std;
  int main() {
    int t,q;
    scanf("%d",&t);
    q=t;
    while(t--){
        long int n,c;
        scanf("%ld%ld",&n,&c);
        printf("Case %d: ",q-t);
        if(n*c==0)printf("0\n");
        else if(c%(2*n)==0)printf("%ld\n",c/(2*n));
        else{
            int k = c/(2*n),l=ceil(c/(2.0*n));
            if(k*c - k*k*n<l*c - l*l*n)printf("%ld\n",l);
            else printf("%ld\n",k);
        }
    }
    return 0;
}