#include <bits/stdc++.h>
using namespace std;
bool pc(long long a){
    if(a==2)return true;
    if(a%2==0) return false;
    for(int i=3;i<=sqrt(a);i+=2)if(a%i==0)return false;
    return true;
}
int main(){
    int tt,qq;
    scanf("%d",&tt);
    qq=tt;
    while(tt--){
        long long n;
        scanf("%lld",&n);
        int h=1,p;
        if(n>=0){
            for(long long i=2;i<=sqrt(n);i++){
                    p = floor(log(n)/log(i));
                    if(pow(i,p)==n){
                        if(h<p)h = p;
                    }
            }
        }
        else{
            n = n*(-1);
            for(long long i=2;i<=sqrt(n);i++){
                    p = floor(log(n)/log(i));
                    if(pow(i,p)==n && p%2!=0){
                        if(h<p)h = p;
                    }
            }
        }
        printf("Case %d: %d\n",qq-tt,h);
    }
    return 0;
}