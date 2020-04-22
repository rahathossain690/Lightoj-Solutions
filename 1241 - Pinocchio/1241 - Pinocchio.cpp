#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,q;
    scanf("%d",&t);
    q=t;
    while(t--){
        int n;
        scanf("%d",&n);
        int k,a,mark=0;
        a=2;
        while(n--){
        scanf("%d",&k);
        if(k>a)mark+=ceil((k-a)/5.0);
        a=k;
        }
        printf("Case %d: %d\n",q-t,mark);
    }
    return 0;
}