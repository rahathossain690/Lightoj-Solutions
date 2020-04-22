#include<bits/stdc++.h>
using namespace std;
  int main(){
    int t,q;
    int n;
    double a[100010];
    scanf("%d", &t);
    q=t;
    a[0] = 0.0;
    double k = 1.0;
    int d = 1000;
    for(int i = 2; i <= 100000000; i++){
        k += 1.0/i;
        if(i == d){
            a[d/1000] = k;
            d += 1000;
        }
    }
    while(t--){
        scanf("%d", &n);
        k = a[n/1000];
        for(int i = (n/1000) * 1000 + 1 ; i <= n; i++) k += 1.0/i;
        printf("Case %d: %.10lf\n",q-t,k);
    }
    return 0;
}