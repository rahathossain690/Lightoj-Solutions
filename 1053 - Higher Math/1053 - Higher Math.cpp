#include<stdio.h>
  int main(){
int t;
scanf("%d",&t);
int q=t;
while(t--){
int a,b,c;
scanf("%d%d%d",&a,&b,&c);
if(a*a==(b*b+c*c)){
    printf("Case %d: yes\n",q-t);
}
else if(a*a==(b*b-c*c)){
    printf("Case %d: yes\n",q-t);
}
else if(a*a==(c*c-b*b)){
    printf("Case %d: yes\n",q-t);
}
else{
    printf("Case %d: no\n",q-t);
}
  }
return 0;
}