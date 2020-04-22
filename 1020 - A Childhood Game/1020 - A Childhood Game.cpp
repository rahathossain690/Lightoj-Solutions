#include <bits/stdc++.h>
using namespace std;
  int main() {
    int t,q;
    scanf("%d",&t);
    q=t;
    while(t--){
        int n;
        char a[6];
        scanf("%d %s",&n,a);
        printf("Case %d: ",q-t);
        if(!strcmp(a,"Alice"))printf((3*((n-1)/3)==(n-1))?"Bob\n":"Alice\n");
        else printf(3*(n/3)==n?"Alice\n":"Bob\n");
    }
    return 0;
}