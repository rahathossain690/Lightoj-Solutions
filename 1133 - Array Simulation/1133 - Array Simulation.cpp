#include <bits/stdc++.h>
using namespace std;
  int main() {
    int t,q;
    scanf("%d",&t);
    q=t;
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        long int a[n];
        for(int i=0;i<n;i++)scanf("%ld",&a[i]);
        char cmd[10];
        while(m--){
            scanf("%s",cmd);
            if(cmd[0]=='S'){
                long int k;
                scanf("%ld",&k);
                for(int i=0;i<n;i++)a[i]+=k;
            }
            else if(cmd[0]=='M'){
                long int k;
                scanf("%ld",&k);
                for(int i=0;i<n;i++)a[i]*=k;
            }
            else if(cmd[0]=='D'){
                long int k;
                scanf("%ld",&k);
                for(int i=0;i<n;i++)a[i]/=k;
            }
            else if(cmd[0]=='R'){
                reverse(a,a+n);
            }
            else if(cmd[0]=='P'){
                long int k,p,c;
                scanf("%ld %ld",&p,&c);
                k = a[p];
                a[p]=a[c];
                a[c]=k;
            }
        }
        printf("Case %d:\n",q-t);
        for(int i=0;i<n;i++){
            printf("%lld",a[i]);
            if(i==n-1)printf("\n");
            else printf(" ");
        }
    }
    return 0;
}