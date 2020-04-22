#include<bits/stdc++.h>
using namespace std;
#define td(n)   scanf("%d",&n)
  int n,ans,i;
char a[150];
int main(){   //freopen("in.txt","r",stdin);
    int t,q;
    td(t);
    q=t;
    while(t--){
        printf("Case %d: ",q-t);
        td(n);
        scanf("%s",a);
        ans=0;
        for(i=0;i<n;i++){
            if(a[i]=='.')ans++,i+=2;
        }
        printf("%d\n",ans);
    }
    return 0;
}