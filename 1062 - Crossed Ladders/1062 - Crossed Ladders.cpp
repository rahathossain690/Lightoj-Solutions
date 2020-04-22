#include<bits/stdc++.h>
using namespace std;
  double x,y,c,hi,lo,mid,ans;
  int main(){ //freopen("in.txt","r",stdin);
    int t=1,C;
    for(scanf("%d",&C);t<=C;t++){
        scanf("%lf%lf%lf",&x,&y,&c);
        hi = max(x,y), lo = 0;
        while(hi-lo > 0.00000001){
            mid = (hi+lo)/2;
            if(x <= mid || y <= mid){
                hi = mid;
                continue;
            }
            ans = 1/sqrt(x*x - mid*mid)+1.0/sqrt(y*y-mid*mid);
            if(ans > (1/c)) hi = mid;
            else if(ans < (1/c)) lo = mid;
        }
        printf("Case %d: %.8lf\n",t,mid);
    }
}