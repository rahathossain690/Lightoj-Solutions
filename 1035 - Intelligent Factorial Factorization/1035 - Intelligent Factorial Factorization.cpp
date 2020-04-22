#include <bits/stdc++.h>
using namespace std;
  int p[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
  int val(int n,int p){
    int l=0;
    while(n>0){
        l+=n/p;
        n/=p;
    }
    return l;
}
  int main(){
    int t,q;
    scanf("%d",&t);
    q=t;
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=0;p[i]<=n;i++){
            if(i==0)printf("Case %d: %d = %d (%d)",q-t,n,p[i],val(n,p[i]));
            else printf(" * %d (%d)" ,p[i],val(n,p[i]));
        }
        printf("\n");
    }
    return 0;
}