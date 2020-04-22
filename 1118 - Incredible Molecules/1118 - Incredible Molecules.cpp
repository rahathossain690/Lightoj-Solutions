#include <bits/stdc++.h>
using namespace std;
#define tlf(n) scanf("%Lf",&n)
#define td(n) scanf("%d",&n)
#define CASE(n) printf("Case %d: ",n)
#define high(n) ((n)>0?(n):(-1)*(n))
int main(){
    //freopen("in.txt","r",stdin);
    int t,q;
    td(t);
    q=t;
    while(t--){
        CASE(q-t);
        long double x[2],y[2],r[2],ans,O[2];
        tlf(x[0]),tlf(y[0]),tlf(r[0]),tlf(x[1]),tlf(y[1]),tlf(r[1]);
        long double d = sqrt((x[0]-x[1])*(x[0]-x[1]) + (y[0]-y[1])*(y[0]-y[1]));
        if(d >= r[0]+r[1]){
            printf("0");
            puts("");
            continue;
        }
        if(d<=high(r[0]-r[1])){
            printf("%.10Lf",acos(-1.0)*min(r[0],r[1])*min(r[0],r[1]));
            puts("");
            continue;
        }
        long double half_s = 0.5 * (r[0]+r[1]+d);
        O[0] = 2*acos((r[0]*r[0]+d*d - r[1]*r[1])/(2*r[0]*d)),O[1]=2*acos((r[1]*r[1]+d*d-r[0]*r[0])/(2*r[1]*d));
        ans = 0.5*r[0]*r[0]*(O[0]-sin(O[0])) + 0.5*r[1]*r[1]*(O[1]-sin(O[1]));
        printf("%.10Lf",ans);
        puts("");
    }
    return 0;
}