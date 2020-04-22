#include<bits/stdc++.h>
using namespace std;
  void solve(){
    int n,a[110],b[110],ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        b[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        if(a[i]!=i){
            int k = a[i],p=a[b[i]];
            swap(a[i],a[b[i]]);
            b[k]=b[i],b[p]=i;
            ans++;
        }
    }
    printf("%d\n",ans);
    return;
}
  int main(){
    int t,q;
    scanf("%d",&t);
    q=t;
    while(t--){
        printf("Case %d: ",q-t);
        solve();
    }
    return 0;
}