#include<bits/stdc++.h>
using namespace std;
  #define ll long long
#define endl "\n"
#define pb push_back
  const int MAX = 1+1e5;
vector<int> num[MAX];
double f[MAX];
  void sieve(){
    for(int i = 2; i < MAX; i++){
        for(int j = i+i; j< MAX; j+=i){
            num[j].pb(i);
        }
    }
}
  void go(int n){
    double ans = 0;
    for(int i = 0; i<num[n].size();i++)
        ans += f[num[n][i]];
    f[n] = (num[n].size()+2+ans)/(num[n].size()+1);
    }
  int main(){ //freopen("in.txt","r",stdin);
    f[0] = f[1] = 0;
    sieve();
    for(int i = 2 ; i < MAX ; i++) go(i);
    int t = 1, tc;
    for(scanf("%d",&tc);t<=tc;t++){
        int n;
        scanf("%d",&n);
        printf("Case %d: %.6lf\n",t,f[n]);
    }
}