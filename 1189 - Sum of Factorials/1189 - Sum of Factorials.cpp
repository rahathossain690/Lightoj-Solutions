#include<bits/stdc++.h>
using namespace std;
  int main(){
    unsigned long long f[20],n;
    f[0]=1;
    for(int i=1;i<20;i++)f[i]=i*f[i-1];
    int t,q;
    scanf("%d",&t);
    q=t;
    while(t--){
        scanf("%llu",&n);
        vector<int>p;
        for(int i=19;i>=0;i--){
            if(n/f[i] > 0){
                n-=f[i];
                p.push_back(i);
            }
            if(n==0)break;
        }
        printf("Case %d: ",q-t);
        if(n==0){
            for(int i=p.size()-1;i>=0;i--){
                if(i==p.size()-1)printf("%d!",p[i]);
                else printf("+%d!",p[i]);
            }
        }
        else printf("impossible");
        printf("\n");
    }
    return 0;
}