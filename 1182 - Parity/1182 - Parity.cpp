#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d",&t);
  int qq=t;
  while(t--){
    unsigned long long a;
    scanf("%llu",&a);
    int q=0;
    while(a>0){
      q+= ((a/2)*2==a?0:1);
      a=a>>1;
    }
    printf("Case %d: ",qq-t);
    if((q/2)*2==q)printf("even\n");
    else printf("odd\n");
  }
  }