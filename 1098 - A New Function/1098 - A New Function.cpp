#include <bits/stdc++.h>
using namespace std;
  #define ull long long
#define pb push_back
  ull sum(int n){
    return ((ull)n*(ull)(n+1))/2;
}
  ull CSOD(int n){
    if(n<4) return 0;
    ull limit = sqrt(n);
    ull ans = sum(limit)-1;
    for(ull i = 2 ;i <= limit;i++){
        ans += i* (n/i - i) + sum(n/i) - sum(i);
    }
    return ans;
}
  int main(){ //freopen("in.txt","r",stdin);
    int t=1,tc;
    for(scanf("%d",&tc);t<=tc;t++){
        int n;
        scanf("%d",&n);
        printf("Case %d: %lld\n",t,CSOD(n));
    }
}