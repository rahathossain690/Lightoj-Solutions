#include<bits/stdc++.h>
using namespace std;
  int main(){
    int t,q;
    scanf("%d",&t);
    q=t;
    while(t--){
        int n,w,c=1;
        scanf("%d%d",&n,&w);
        long int a[n];
        long int p;
        for(int i=0;i<n;i++){
            scanf("%ld%ld",&p,&a[i]);
        }
        sort(a,a+n);
        p=a[0]+w;
        for(int i=1;i<n;i++){
            if(a[i]>p){
                c++;
                p = a[i]+w;
            }
        }
    printf("Case %d: %d\n",q-t,c);
    }
    return 0;
}