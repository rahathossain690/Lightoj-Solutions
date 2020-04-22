#include <bits/stdc++.h>
using namespace std;
  int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
  int main() {
    int t,q;
    scanf("%d",&t);
    q=t;
    while(t--){
        int n;
        scanf("%d",&n);
        int a[n],add=0,p=0;
        bool hbe=false;
        printf("Case %d: ",q-t);
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            if(a[i]>0){
                hbe=true;
                p++;
            }
            add += a[i]>0?a[i]:(a[i]*-1);
        }
        if(hbe){
            int g=gcd(add,p);
            printf("%d/%d\n",add/g,p/g);
        }
        else printf("inf\n");
    }
    return 0;
}