#include<bits/stdc++.h>
using namespace std;
  int lip(int d,char m[], int y){
    y--;
    int k = y/4 - y/100 + y/400;
    y++;
    if(y%4==0 && y%100!=0 || y%400==0){
        if(!strcmp(m,"January")){
                    }
        else if(!strcmp(m,"February")&&d<29){
                    }
        else k++;
    }
    return k;
}
  int main(){
    int t,q;
    scanf("%d",&t);
    q=t;
    while(t--){
        int y[2],d[2];
        char m[2][10];
        scanf("%s%d,%d\n%s %d,%d",m[0],&d[0],&y[0],m[1],&d[1],&y[1]);
        if(d[0]==29)d[0]=28;
        printf("Case %d: %d\n",q-t,lip(d[1],m[1],y[1])-lip(d[0],m[0],y[0]));
    }
    return 0;
}