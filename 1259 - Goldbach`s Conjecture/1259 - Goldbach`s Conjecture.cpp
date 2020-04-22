#include<bits/stdc++.h>
using namespace std;
  bool a[10000001];
vector<int>p;
void sieve(){
    a[1]=true;
    for(long long i=4;i<=10000000;i+=2)a[i]=true;
    int x = sqrt(10000000);
    for(long long i=3;i<=x;i+=2){
        if(!a[i]){
         for(long long j=i*i;j<=10000000;j+=i){
            a[j]=true;
            }
        }
    }
    for(int i=2;i<=10000000;i++)if(!a[i])p.push_back(i);
    return;
}
  int main(){
    sieve();
    int t,q;
    scanf("%d",&t);
    q=t;
    while(t--){
        int n,c=0;
        scanf("%d",&n);
        for(int i=0;p[i]<=n/2;i++){
            if(!a[n-p[i]])c++;
        }
        printf("Case %d: %d\n",q-t,c);
    }
    return 0;
}