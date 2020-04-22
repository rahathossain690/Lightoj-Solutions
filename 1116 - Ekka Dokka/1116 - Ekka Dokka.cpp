#include <bits/stdc++.h>
using namespace std;
  int main(){
    int tt,qq;
    scanf("%d",&tt);
    qq=tt;
    while(tt--){
        unsigned long long w;
        scanf("%llu",&w);
        printf("Case %d: ",qq-tt);
        if(w%2==1)printf("Impossible");
        else
        {
            int i = ceil(log(w)/log(2));
            for(;i>0;i--){
                unsigned long long k = pow(2,i);
                if(w == (w/k)*k){
                    printf("%llu %llu",w/k,k);
                    break;
                }
            }
        }
        printf("\n");
    }
    return 0;
}