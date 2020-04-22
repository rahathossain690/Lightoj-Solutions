#include <bits/stdc++.h>
using namespace std;
  unsigned long long fives(unsigned long long n){
    unsigned long long b = 0,l = 5;
    for(;l<=n;){
        b += n / l;
        l*=5;
    }
    return b;
}
  unsigned long long binsr(unsigned long long n){
    unsigned long long lo = 1, hi = 1000000000000000000,mid,cach;
    while(lo<=hi){
        mid = (lo+hi)/2;
        cach = fives(mid);
        if(cach==n)return mid;
        else if(cach < n)lo = mid + 1;
        else if(cach > n)hi = mid - 1;
    }
    return 0;
}
  int main(){
    int tt,qq;
    scanf("%d",&tt);
    qq=tt;
    while(tt--){
        unsigned long long n;
        scanf("%llu",&n);
        n = binsr(n);
        printf("Case %d: ",qq-tt);
        if(n==0){
            printf("impossible\n");
        }
        else {
            n = (n/5)*5;
            printf("%llu\n",n);
        }
    }
    return 0;
}