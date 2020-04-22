#include<stdio.h>
  int main(){
int i,a,b,k;
scanf("%d",&k);
for(i=1;i<=k;++i){
    scanf("%d %d",&a,&b);
    printf("Case %d: %d\n",i,a+b);
}
    }