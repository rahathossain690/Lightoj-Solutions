#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll out(int a[],int n)
{
    ll ans = 0;
    for(int i=0; i<n; i++)
    {
        ll p = a[i];
        p*=(n-2*i-1);
        ans+=p;
    }
    return ans;
}
int main()
{
//    freopen("in.c","r",stdin);
    int t,q;
    scanf("%d",&t);
    q=t;
    while(t--)
    {
        printf("Case %d:\n",q-t);
        int n,qq;
        scanf("%d%d",&n,&qq);
        int a[200000];
        for(int i=0; i<n; i++)scanf("%d",&a[i]);
        ll ans = out(a,n);
        for(int i=0; i<qq; i++)
        {
            int cmd;
            scanf("%d",&cmd);
            if(cmd)
            {
                printf("%lld\n",ans);
            }
            else
            {
                int pos,con;
                scanf("%d%d",&pos,&con);
                ll p =(n-2*pos-1);
                p*=(con-a[pos]);
                ans += p;
                a[pos]=con;
            }
        }
    }
    return 0;
}