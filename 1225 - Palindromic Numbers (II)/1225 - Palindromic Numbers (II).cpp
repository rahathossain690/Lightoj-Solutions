#include <bits/stdc++.h>
using namespace std;
  int main(){
    int t,q;
    scanf("%d",&t);
    q=t;
    while(t--){
        char a[20];
        scanf("%s",a);
        int mark = 1;
        printf("Case %d: ",q-t);
        for(int i=0;i<(strlen(a)/2);i++){
            if(a[i]!=a[strlen(a)-i-1]){
                mark = 0;
                break;
            }
        }
        printf(mark==1?"Yes\n":"No\n");
    }
        return 0;
}