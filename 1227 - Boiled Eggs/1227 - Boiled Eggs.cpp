#include <bits/stdc++.h>
using namespace std;
  int main(){
    int t,jhsgk;
    scanf("%d",&t);
    jhsgk=t;
    while(t--){
        int n,p,q;
        scanf("%d%d%d",&n,&p,&q);
        int w[n],cw[n];
        for(int i=0;i<n;i++){
            scanf("%d",&w[i]);
            if(i==0)cw[0]=w[0];
            else cw[i]=w[i]+cw[i-1];
        }
                int total = n-1;
        for(;total>=0;total--)if(cw[total]<=q)break;
        if(total+1<=p) printf("Case %d: %d\n",jhsgk-t,total+1);
        else  printf("Case %d: %d\n",jhsgk-t,p);
    }
        return 0;
}