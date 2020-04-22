#include <bits/stdc++.h>
using namespace std;
  unsigned long long a[5000010];
void sieve(){
    for(int i=2;i<5000010;i++)a[i]=i;
    for(int i=2;i<5000010;i++){
        if(a[i]==i){
            for(int j=i;j<5000010;j+=i){
                a[j]-=a[j]/i;
            }
        }
    }
    for(int i=2;i<5000005;i++){
        a[i]*=a[i];
        a[i]+=a[i-1];
    }
    return;
}
  int main(){
    sieve();
    int t,q;
    scanf("%d",&t);
    q=t;
    //for(int i=100;i<=5000000;i++)printf("%llu\n",l[i]);
    while(t--){
        unsigned long long f,s;
        scanf("%llu%llu",&f,&s);
        printf("Case %d: %llu\n",q-t,a[s]-a[f-1]);
    }
    return 0;
}