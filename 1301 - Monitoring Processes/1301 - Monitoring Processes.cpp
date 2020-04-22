#include <bits/stdc++.h>
using namespace std;
  #define td(n) scanf("%d",&n)
#define START       double cL = clock()
#define FINISH      printf("\n\nE = %lfs\n", (clock() - cL) / CLOCKS_PER_SEC);
  struct time{
    int s,t;
} a[50001];
  bool comp(struct time a, struct time b){
    if(a.s == b.s) return a.t <= b.t;
    return a.s <= b.s;
}
  int main(){
    //freopen("in.txt","r",stdin);
    //START;
    int t=1,tc;
    for(td(tc);t<=tc;t++){
        int n;
        td(n);
        for(int i = 0; i<n; i++)td(a[i].s),td(a[i].t);
        sort(a,a+n,comp);
        int ans = 1, cur = 0;
        priority_queue <int,vector<int>, greater<int> > jabe;
        for(int i = 0; i < n; i++){
            cur++;
            jabe.push(a[i].t);
            if(a[i].s > jabe.top())jabe.pop(),cur--;
            ans = max(cur,ans);
        }
        printf("Case %d: %d\n",t,ans);
    }
    //FINISH;
    return 0;
}