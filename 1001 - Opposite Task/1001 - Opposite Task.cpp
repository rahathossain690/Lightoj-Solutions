#include<stdio.h>
  int main(){
int t;
scanf("%d",&t);
while(t!=0){
int q;
scanf("%d",&q);
int i;
for(i=0;;i++){
    if(i<=10 && (q-i)<=10){
printf("%d %d\n",i,q-i);
break;
}
}
  t--;
}
  return 0;
}