#include<bits/stdc++.h>
using namespace std;
#define td(n)   scanf("%d",&n)
    int main(){   //freopen("in.txt","r",stdin);
    int t,q;
    td(t);
    q=t;
    while(t--){
        printf("Case %d: ",q-t);
        int n,prev = 0,p,m=-10,f;
        td(n);
        vector<int>dif;
        for(int i=0;i<n;i++){
            td(p);
            dif.push_back(p-prev);
            m = max(p-prev,m);
            prev=p;
        }
        f=m;
        bool hbe = true;
        //puts("");
        for(int i=0;i<dif.size();i++){
            //cout<<dif[i]<<" "<<f<<endl;
            if(dif[i] == f) f--;
            else if(dif[i] > f){
                hbe=false;
                break;
            }
        }
        printf("%d\n",hbe?m:m+1);
    }
    return 0;
}