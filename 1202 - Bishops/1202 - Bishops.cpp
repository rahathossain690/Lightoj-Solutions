#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,q;
    scanf("%d",&t);
    q=t;
    while(t--){
        long long a,b,c,d;
        scanf("%ld%ld%ld%ld",&a,&b,&c,&d);
        printf("Case %d: ",q-t);
        if((a+b)%2==(c+d)%2){
            if(a-c==b-d || a-c==d-b)printf("1\n");
            else printf("2\n");
        }
        else printf("impossible\n");
    }
    return 0;
}