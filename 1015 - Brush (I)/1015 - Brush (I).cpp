#include<iostream>
using namespace std;
  int main(){
int a,b;
cin>>a;
b=a;
while(a--){
int c,m=0;
cin>>c;
int d[c];
for(int i=0;i<c;i++){
cin>>d[i];
if(d[i]>=0)m+=d[i];
}
cout<<"Case "<<b-a<<": "<<m<<endl;
}
return 0;
}