#include<bits/stdc++.h>
  int main(){
    int t,q;
    scanf("%d",&t);
    q=t;
    while(t--){
    int x1,y1,x2,y2,x3,y3;
    scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
    printf("Case %d: %d %d ",q-t,x1+x3-x2,y1+y3-y2);
    printf("%d\n",abs(x1*(y2-y3)-x2*(y1-y3)+x3*(y1-y2)));
    }
    return 0;
}