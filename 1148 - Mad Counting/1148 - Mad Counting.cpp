#include <bits/stdc++.h>
using namespace std;
  #define sc(n) scanf("%d",&n)
  int main() {
    int t,q;
    sc(t);
    q=t;
    while(t--){
        int n;
        sc(n);
        int p=0;
        map<int,int> m;
        map<int,int>::iterator it;
        for(int i=0;i<n;i++){
            sc(p);
            m[p]+=1;
        }
        unsigned long long ans=0;
        for(it=m.begin();it!=m.end();it++){
            ans += ceil((double(it->second))/(it->first + 1))*(it->first + 1);
        }
        printf("Case %d: %llu\n",q-t,ans);
    }
    return 0;
}