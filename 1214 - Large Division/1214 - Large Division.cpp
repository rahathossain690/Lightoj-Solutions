#include <bits/stdc++.h>
  using namespace std;
  int main(){
    int tt,qq;
    scanf("%d",&tt);
    qq=tt;
    while(tt--){
        char a[1000];
        long long b;
        scanf("%s %lld",a,&b);
        b=abs(b);
            long long rmdr = 0;
        if(a[0]=='-'){
            long long n[strlen(a)-1];
            n[0] = 1-b*(1/b);
            for(long long i=1;i<strlen(a)-1;i++) n[i] = n[i-1]*10 - ((n[i-1]*10)/b)*b;
            for(long long i=strlen(a)-1;i>0;i--){
                rmdr = rmdr + (a[i]-48)*n[strlen(a)-1-i];
                rmdr = rmdr - (rmdr/b)*b;
            }
        }
        else{
            long long n[strlen(a)];
            n[0] = 1-b*(1/b);
            for(long long i=1;i<strlen(a);i++) n[i] = n[i-1]*10 - ((n[i-1]*10)/b)*b;
            for(long long i=strlen(a)-1;i>=0;i--){
                rmdr = rmdr + (a[i]-48)*n[strlen(a)-1-i];
                rmdr = rmdr - (rmdr/b)*b;
            }
        }
        printf("Case %d: ",qq-tt);
        printf(rmdr==0?"divisible\n":"not divisible\n");
    }
    return 0;
}