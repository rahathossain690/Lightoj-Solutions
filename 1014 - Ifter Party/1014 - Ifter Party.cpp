#include<bits/stdc++.h>
using namespace std;
    int main(){
    int t,q;
    scanf("%d",&t);
    q=t;
    while(t--){
        int a,b;
        scanf("%d%d",&a,&b);
        a-=b;
        printf("Case %d: ",q-t);
        if(a<=b)printf("impossible");
        else {
            vector<int>p;
            for(int i=1;i<=sqrt(a);i++){
                if(a%i==0 && i*i != a){
                    if(i>b)p.push_back(i);
                    if(a/i>b)p.push_back(a/i);
                }
                if(a%i==0 && i*i == a){
                    if(i>b)p.push_back(i);
                }
            }
            sort(p.begin(),p.end());
            if(p.empty())printf("impossible");
                else{
                    printf("%d",p[0]);
                for(int i=1;i<p.size();i++){
                    printf(" %d",p[i]);
                }
            }
        }
        printf("\n");
    }
    return 0;
}