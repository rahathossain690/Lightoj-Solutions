#include<bits/stdc++.h>
using namespace std;
int kill(int n, unsigned long long k){
    if(n==1) return 0;
    return (kill(n-1,k)+k)%n;
}
int main(){
    int t,q;
    scanf("%d",&t);
    q=t;
    while(t--){
        int a;
        scanf("%d",&a);
        unsigned long long b;
        scanf("%llu",&b);
        printf("Case %d: %d\n",q-t,kill(a,b)+1);
    }
    return 0;
}