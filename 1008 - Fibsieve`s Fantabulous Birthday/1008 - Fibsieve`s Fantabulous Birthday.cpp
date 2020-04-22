#include <stdio.h>
#include<math.h>
  int main() {
    int t,q;
    scanf("%d",&t);
    q=t;
    while(t--){
    unsigned long long a;
    scanf("%llu",&a);
    unsigned long long r=1,c=1,num=1;
    if((unsigned long long)sqrt(a-1)%2==0){
        r=(unsigned long long)sqrt(a-1)+1;
        unsigned long long mid = (unsigned long long)sqrt(a-1)*(unsigned long long)sqrt(a-1)+(unsigned long long)sqrt(a-1)+1;
        num = (unsigned long long)sqrt(a-1)*(unsigned long long)sqrt(a-1)+1;
        if(a<=mid){
            c += a-num;
            printf("Case %d: %llu %llu\n",q-t,r,c);
        }
        else{
            c=r;
            r -= a-mid;
                        printf("Case %d: %llu %llu\n",q-t,r,c);
        }
    }
    else{
        r=(unsigned long long)sqrt(a-1)+1;
        unsigned long long mid = (unsigned long long)sqrt(a-1)*(unsigned long long)sqrt(a-1)+(unsigned long long)sqrt(a-1)+1;
        num = (unsigned long long)sqrt(a-1)*(unsigned long long)sqrt(a-1)+1;
        if(a<=mid){
            c += a-num;
            printf("Case %d: %llu %llu\n",q-t,c,r);
        }
        else{
            c=r;
            r -= a-mid;
                        printf("Case %d: %llu %llu\n",q-t,c,r);
        }
            }
    }
    return 0;}