#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
  map< ull ,int>all_ans;
vector<int> p;
bool aa[1000010];
  void kms(){
    p.push_back(2);
    for(int i=3;i*i<=1000000;i+=2){
        if(!aa[i])for(int j = i*i;j<=1000000;j+=i+i)aa[j] = 1;
    }
    for(int i=3;i<=1000000;i+=2)if(!aa[i])p.push_back(i);
}
  ull d(ull n){
    ull tot = 1;
    ull t = 0;
    for(int i = 0;n!=1 && i<p.size();i++){
        t = 0;
        while(n%p[i]==0)n/=p[i],t++;
        tot *= (t+1);
    }
    if(n!=1)tot*=2;
    return tot;
}
  int main(){// freopen("in.txt","r",stdin);
    kms();
    //printf("%llu",d(7));
    //return 0;
    int t,q;
    scanf("%d",&q);
    for(t=1;t<=q;t++){
        ull a,b;
        scanf("%llu %llu",&a,&b);
        printf("Case %d: ",t);
        if(a <= b*b)printf("0");
        else {
            ull ans = all_ans[a],m;
            if(ans==0){
                m=all_ans[a] = d(a);
                ans = m;
            }
            ans/=2;
            for(ull i = 1;i<b;i++){
                if(a%i==0)ans--;
            }
            printf("%llu",ans);
        }
        puts("");
    }
}