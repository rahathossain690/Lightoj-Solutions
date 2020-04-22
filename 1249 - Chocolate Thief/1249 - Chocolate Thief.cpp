#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,q;
    scanf("%d",&t);
    q=t;
    while(t--){
        int n;
        scanf("%d",&n);
        char name[n+2][50];
        int h[n+2],w[n+2],l[n+2],ans,max=0,min,markmax,markmin;
        for(int i=0;i<n;i++){
            scanf("%s %d%d%d",name[i],&h[i],&w[i],&l[i]);
            ans = h[i]*w[i]*l[i];
            if(i==0){
                min=ans;
                max=ans;
                markmax=0;
                markmin=0;
            }
            if(ans>max){
                max=ans;
                markmax=i;
            }
            else if(ans<min){
                min=ans;
                markmin=i;
            }
        }
        printf("Case %d: ",q-t);
        if(min==max)printf("no thief\n");
        else printf("%s took chocolate from %s\n",name[markmax],name[markmin]);
    }
    return 0;
}