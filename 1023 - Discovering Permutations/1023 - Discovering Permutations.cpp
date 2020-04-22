#include<bits/stdc++.h>
using namespace std;
#define td(n) scanf("%d",&n)
  int main(){
//  freopen("in.txt","r",stdin);
    int t,q;
    td(t);
    q=t;
    while(t--){
        printf("Case %d:\n",q-t);
        int n,k;
        td(n),td(k);
        char a[n];
        for(int i=0;i<n;i++)a[i]=i+'A';
        for(int j=1;;j++){
            for(int i=0;i<n;i++)printf("%c",a[i]);
            puts("");
            if(j==k)break;
            if(!next_permutation(a,a+n))break;
        }
    }
    return 0;
}