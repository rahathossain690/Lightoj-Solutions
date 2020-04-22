#include "bits/stdc++.h"
using namespace std;
#define ll long long
  int main(){
    int t=1,tc;
    for(scanf("%d",&tc);t<=tc;t++){
        unsigned long long n;
        scanf("%llu",&n);
        printf("Case %d: ",t);
        int f = 0;
        for(int i = 9; i>=0 ;i--){
            if((10*n - i)%9 == 0){
                if(f)printf(" %llu",(10*n - i)/9);
                else printf("%llu",(10*n - i)/9),f=1;
            }
        }
        puts("");
    }
    return 0;
}