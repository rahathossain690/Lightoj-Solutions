#include <bits/stdc++.h>
using namespace std;
  typedef unsigned long long ull;
typedef unsigned long ul;
  #define MAX 1000000
bool sieveData[MAX+10];
vector<int>prime;
void sieve(){
    int limit = sqrt(MAX+10);
    for(int i=3;i<=limit;i+=2){
        if(!sieveData[i]){
            for(int j=i*i;j<MAX+10;j+=2*i)sieveData[j]=1;
        }
    }
    prime.push_back(2);
    for(int i=3;i<MAX+10;i+=2)if(!sieveData[i])prime.push_back(i);
    return;
}
  ull d = 1;
void make(ul n){
    int times;
    for(int i=0;prime[i]<=sqrt(n);i++){
        times=0;
        while(n%prime[i]==0){
            n/=prime[i];
            times++;
        }
        d *= (times+1);
    }
    if(n>1)d *= 2;
    return;
}
  int main(){
    sieve();
    int t,q;
    scanf("%d",&t);
    q=t;
    while(t--){
        ul n;
        d=1;
        scanf("%ld",&n);
        make(n);
        printf("Case %d: %ld\n",q-t,d-1);
    }
    return 0;
}