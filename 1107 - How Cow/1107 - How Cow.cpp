#include<bits/stdc++.h>
using namespace std;
  int main(){
    int t,q;
    scanf("%d",&t);
    q=t;
    while(t--){
        int x1,x2,y1,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        int n;
        scanf("%d",&n);
        printf("Case %d:\n",q-t);
        int x,y;
        for(int i=0;i<n;i++){
            scanf("%d%d",&x,&y);
            if(x>x1 && x<x2 &&y>y1 && y<y2)printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}