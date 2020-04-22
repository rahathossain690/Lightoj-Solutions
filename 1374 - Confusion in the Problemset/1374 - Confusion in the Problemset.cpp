#include <bits/stdc++.h>
using namespace std;
  #define td(n) scanf("%d",&n)
#define START       double cL = clock()
#define FINISH      printf("\n\nE = %lfs\n", (clock() - cL) / CLOCKS_PER_SEC);
  int n,cnt[1000001],tmp;
  int main(){
    //freopen("in.txt","r",stdin);
    //START;
    int t=1,tc;
    for(td(tc);t<=tc;t++){
        td(n);
        memset(cnt,0,sizeof(cnt));
        bool f = 1;
        for(int i = 0; i<n;i++)td(tmp),cnt[tmp]++;
        for(int i = 0; 2*i < n; i++)if(cnt[i]+cnt[n-i-1]!=2){
            f=0;
            break;
        }
        printf("Case %d: ",t);
        if(f)puts("yes");
        else puts("no");
    }
    //FINISH;
    return 0;
}