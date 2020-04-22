#include <bits/stdc++.h>
using namespace std;
#define td(n)   scanf("%d",&n)
#define CASE(n) printf("Case %d: ",n)
int a[2010];
int n,i,j;
long long ans;
int main(){                     //freopen("in.txt","r",stdin);
    int t,q;
    for(scanf("%d",&q),t=1;t<=q;t++){
        CASE(t);
        td(n);
        i=ans=0;
        for(i=0;i<n;i++)td(a[i]);
        sort(a,a+n);
        for(i=0;i<n;i++)for(j=i+1;j<n;j++)
            ans += lower_bound(a,a+n,a[i]+a[j])-a-1-j;
        printf("%lld\n",ans);
    }
    return 0;
}