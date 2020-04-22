#include<bits/stdc++.h>
using namespace std;
  int main(){
    int t,q;
    scanf("%d",&t);
    q=t;
    while(t--){
        vector<int>aw(30,0),bw(30,0);
        char a[101],b[101];
        scanf(" %[^\n] %[^\n]",a,b);
        int la=strlen(a),lb=strlen(b);
        for(int i=0;i<la;i++){
            if(a[i]==' ')continue;
            a[i]+=(a[i]<'a'?32:0);
            aw[a[i]-'a']+=1;
        }
        for(int i=0;i<lb;i++){
            if(b[i]==' ')continue;
            b[i]+=(b[i]<'a'?32:0);
            bw[b[i]-'a']+=1;
        }
        printf("Case %d: ",q-t);
        bool hoise=true;
        for(int i=0;i<27;i++){
            if(aw[i]!=bw[i]){
                hoise=false;
                break;
            }
        }
        printf(hoise?"Yes\n":"No\n");
    }
    return 0;
}