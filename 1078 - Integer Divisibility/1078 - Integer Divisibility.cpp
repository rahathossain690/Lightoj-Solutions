#include<bits/stdc++.h>
using namespace std;
    int main(){
    int t,q;
    scanf("%d",&t);
    q=t;
    while(t--){
        int a,b;
        scanf("%d%d",&a,&b);
        int p=b,i=1;
        while(p%a!=0){
            p = ((p%a)*(10%a) + (b%a))%a;
            i++;
        }
        printf("Case %d: %d\n",q-t,i);
    }
    return 0;
}