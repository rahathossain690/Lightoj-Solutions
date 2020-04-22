#include<bits/stdc++.h>
using namespace std;
#define td(n) scanf("%d",&n)
int i,n,q,A,B,t,c,a[100010];
int main(){//freopen("in.txt","r",stdin);
    for(scanf("%d",&t),c=1;c<=t;c++){
        printf("Case %d:\n",c);
        td(n),td(q);
        for(i=0;i<n;i++)td(a[i]);
        for(i=0;i<q;i++){
            td(A),td(B);
            printf("%ld\n",upper_bound(a,a+n,B)-lower_bound(a,a+n,A));
        }
    }
    return 0;
}