#include <bits/stdc++.h>
using namespace std;
  char a[21][21];
int n,m;
int tot;
  void fuck(int i, int j){
    if(i>=0&&i<n&&j>=0&&j<m){
        if(a[i][j]=='@'||a[i][j]=='.'){
            tot++;
            a[i][j]='+';
            fuck(i+1,j);
            fuck(i-1,j);
            fuck(i,j+1);
            fuck(i,j-1);
        }
        else return;
    }
    else return;
}
  int main() {
    int t,q;
    scanf("%d",&t);
    q=t;
    while(t--){
        tot=0;
        m=0,n=0;
        scanf("%d%d",&m,&n);
        for(int i=0;i<n;i++){
            scanf("%s",a[i]);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]=='@'){
                    fuck(i,j);
                }
            }
        }
        printf("Case %d: %d\n",q-t,tot);
    }
    return 0;
}