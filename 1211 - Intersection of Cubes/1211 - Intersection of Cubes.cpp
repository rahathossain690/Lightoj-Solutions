#include <bits/stdc++.h>
using namespace std;
int main() {
    int t,q;
    scanf("%d",&t);
    q=t;
    while(t--){
        int n;
        scanf("%d",&n);
        int x[2],y[2],z[2];
        int rx[2]={0,1001},ry[2]={0,1001},rz[2]={0,1001};
        bool hbe=true;
        while(n--){
            scanf("%d%d%d%d%d%d",&x[0],&y[0],&z[0],&x[1],&y[1],&z[1]);
            rx[0] = max(rx[0],min(x[0],x[1])),rx[1]=min(rx[1],max(x[0],x[1]));
            ry[0] = max(ry[0],min(y[0],y[1])),ry[1]=min(ry[1],max(y[0],y[1]));
            rz[0] = max(rz[0],min(z[0],z[1])),rz[1]=min(rz[1],max(z[0],z[1]));
            if(rx[0]>rx[1]||ry[0]>ry[1]||rz[0]>rz[1])hbe = false;
        }
        //printf("%d %d %d %d %d %d\n",rx[0],rx[1],ry[0],ry[1],rz[0],rz[1]);
        printf("Case %d: ",q-t);
        if(hbe){
            int area = (rx[1]-rx[0])*(ry[1]-ry[0])*(rz[1]-rz[0]);
            printf("%d\n",area);
        }
        else printf("0\n");
    }
    return 0;
}