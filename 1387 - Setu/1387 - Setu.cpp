#include <bits/stdc++.h>
using namespace std;
  int main(){
    int t,q;
    scanf("%d",&t);
    q=t;
    while(t--){
        int num;
        scanf("%d",&num);
        printf("Case %d:\n",q-t);
        int amount=0;
        while(num--){
            char a[1000];
            scanf("%s",a);
            if(strcmp(a,"donate")==0){
                int taka;
                scanf("%d",&taka);
                amount+=taka;
            }
            if(strcmp(a,"report")==0) printf("%d\n",amount);
        }
            }
        return 0;
}