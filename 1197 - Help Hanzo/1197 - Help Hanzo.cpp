#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define endl "\n"
#define ll long long
  const int MAX = 70001;
vector<int> p;
bool _a[MAX];
  void sieve(){
    p.pb(2);
    for(int i = 3;i*i < MAX; i+=2){
        if(!_a[i]){
            for(int j = i*i;j < MAX; j+=i+i) _a[j] = 1;
        }
    }
    for(int i = 3;i<MAX;i+=2)if(!_a[i])p.pb(i);
}
  ll seg(ll a, ll b){
    ll ans = 0;
    if(a == 2 && b == 2) return 1;
    else if(a == 1){
        if(b == 1) return 0;
        if(b == 2) return 1;
        a = 3,ans++;
    }
    else if(a == 2) ans++,a++;
    bool mal[b-a+10];
    memset(mal,0,sizeof(mal));
    for(int i = 1; p[i] * 1LL * p[i] <= b ;i++){
        ll s = ((a + p[i] - 1LL) / p[i]) * 1LL * p[i];
        for(; s <= b ;s+=p[i]){
            if(s!=p[i])mal[s-a] = 1;
        }
    }
    for(ll i = a;i<=b;i++)if(!mal[i-a] && i%2 == 1)ans++;
    return ans;
}
  int main(){ //freopen("in.txt","r",stdin);
    sieve();
    int t=1,tc;
    for(scanf("%d",&tc);t<=tc;t++){
        ll a,b;
        scanf("%lld%lld",&a,&b);
        printf("Case %d: %lld\n",t,seg(a,b));
    }
}