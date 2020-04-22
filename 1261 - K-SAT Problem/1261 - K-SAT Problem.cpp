#include<bits/stdc++.h>
using namespace std;
  int main(){
    int t,q;
    scanf("%d",&t);
    q=t;
    while(t--){
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        int sob[n][k];
        for(int i=0;i<n;i++)for(int j=0;j<k;j++)scanf("%d",&sob[i][j]);
        int p;
        bool balamar=false;
        scanf("%d",&p);
        if(p==0)p=1,balamar=true;
        int slu[p];
        if(!balamar){
        for(int i=0;i<p;i++)scanf("%d",&slu[i]);
            sort(slu,slu+p);
        }
        else slu[0]=10000;
        bool yes = true;
        for(int i=0;i<n;i++){
                int hudai= 0;
            for(int j=0;j<k;j++){
                if(sob[i][j]>0){
                    hudai += (binary_search(slu,slu+p,sob[i][j]));
                }
                else{
                    hudai += !(binary_search(slu,slu+p,abs(sob[i][j])));
                }
                if(hudai>0)break;
            }
            if(hudai==0){
                yes = false;
                break;
            }
        }
        printf("Case %d: ",q-t);
        if(yes)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}