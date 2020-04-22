#include<bits/stdc++.h>
using namespace std;
  int main(){
    double b[1000002];
    b[1]=log(1);
    b[2]=log(2);
    for(int i=3;i<=1000000;i++)b[i]=b[i-1]+log(i);
    int t;
    scanf("%d",&t);
    int q=t;
    while(t--){
        int a,c;
        scanf("%d%d",&a,&c);
        double k = b[a]/log(c);
        printf("Case %d: %.0lf\n",q-t,floor(k)+1); 
    }
    return 0;
}