#include<bits/stdc++.h>
using namespace std;
int divs(int a){
    int k=0;
    for(int i=2;i<sqrt(a);i++)if((a/i)*i==a)k++;
    k=2*k;
    if((int)sqrt(a)*(int)sqrt(a)==a && a!=1)k++;
    return k;
}
int main(){
    vector<int> ans;
    vector<int> flag(1010,1);
    int k=1;
    ans.push_back(1);
    for(int j=0;j<=30;j++){
        for(int i=1000;i>1;i--){
            if(divs(i)==j && flag[i]!=0){
                ans.push_back(i);
                flag[i]=0;
            }
        }
    }
    int t,q;
    scanf("%d",&t);
    q=t;
    while(t--){
    scanf("%d",&k);
    printf("Case %d: %d\n",q-t,ans[k-1]);
    }
    return 0;
}