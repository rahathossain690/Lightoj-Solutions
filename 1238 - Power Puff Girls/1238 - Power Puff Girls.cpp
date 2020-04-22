#include <bits/stdc++.h>
using namespace std;
  #define td(n)   scanf("%d",&n)
#define ll      long long
#define ull     unsigned long long
#define CASE(n) printf("Case %d: ",n)
#define valid(i,j) 0<=(i)&&(i)<(m)&&0<=(j)&&(j)<(n)&&ans[(i)][(j)]==5000&&a[(i)][(j)]!='m'&&a[(i)][(j)]!='#'
int n,m,ans[21][21],pos[4][2],ii,jj;
char a[21][21];
int main(){//freopen("in.txt","r",stdin);
        int t,q;
        for(td(q),t=1;t<=q;t++){CASE(t);
        td(m),td(n);
        for(int i=0;i<m;i++){
            scanf("%s",a[i]);
            for(int j=0;j<n;j++){
                ans[i][j] = 5000;
                if(a[i][j]=='h')pos[0][0]=i,pos[0][1]=j;
                else if(a[i][j]=='a')pos[1][0]=i,pos[1][1]=j;
                else if(a[i][j]=='b')pos[2][0]=i,pos[2][1]=j;
                else if(a[i][j]=='c')pos[3][0]=i,pos[3][1]=j;
            }
        }
        ans[pos[0][0]][pos[0][1]] = 0;
        queue<int>qi,qj;
        qi.push(pos[0][0]),qj.push(pos[0][1]);
        while(!qi.empty()){
            ii = qi.front(),jj=qj.front();
            qi.pop(),qj.pop();
            if(valid(ii+1,jj))ans[ii+1][jj]=ans[ii][jj]+1,qi.push(ii+1),qj.push(jj);
            if(valid(ii-1,jj))ans[ii-1][jj]=ans[ii][jj]+1,qi.push(ii-1),qj.push(jj);
            if(valid(ii,jj+1))ans[ii][jj+1]=ans[ii][jj]+1,qi.push(ii),qj.push(jj+1);
            if(valid(ii,jj-1))ans[ii][jj-1]=ans[ii][jj]+1,qi.push(ii),qj.push(jj-1);
        }
        printf("%d\n",max(max(ans[pos[1][0]][pos[1][1]],ans[pos[2][0]][pos[2][1]]),ans[pos[3][0]][pos[3][1]]));
    }
    return 0;
}