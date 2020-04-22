#include<bits/stdc++.h>
using namespace std;
    #define START       double cL = clock()
#define FINISH      printf("E = %lfs\n", (clock() - cL) / CLOCKS_PER_SEC);
  long double k,l,w,mid,hi,lo,ans;
  int main(){ //freopen("in.txt","r",stdin);
    int t=1,C;
    for(scanf("%d",&C);t<=C;t++){
        scanf("%Lf : %Lf",&l,&w);
        hi = 10000,lo = 0;
        k = l / w;
        while( hi - lo > 0.0000000001){
            mid = (lo+hi)/2;
            ans = 2*mid*sqrt(1+k*k)*atan(1/k)+2*k*mid;
            if(ans > 400) hi = mid;
            else lo = mid;
        }
        printf("Case %d: %.6Lf %.6Lf\n",t,k*mid,mid);
    }
}