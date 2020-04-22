#include <bits/stdc++.h>
  using namespace std;
  int main(){
    int t,q;
    scanf("%d",&t);
    q=t;
    while(t--){
        char a[1000],b[1000];
        scanf("%s %s",a,b);
        int dec[4],bin[4],k=0;
        for(int i=0;i<strlen(a);i++){
            if(i==0 || a[i-1]=='.'){
                dec[k]=atoi(&a[i]);
                k++;
            }
        }
        k=0;
        bin[0]=atoi(b);
        bin[1]=atoi(&b[9]);
        bin[2]=atoi(&b[18]);
        bin[3]=atoi(&b[27]);
        k=0;
        for(int i=0;i<4;i++){
            int temp = dec[i],l=0,base=1;
            while(temp>0){
                l += temp%2*base;
                temp=temp>>1;
                base*=10;
            }
            if(l!=bin[i]){
                k=1;
                break;
            }
        }
        printf("Case %d: ",q-t);
        printf(k==0?"Yes\n":"No\n");
    }
    return 0;
}