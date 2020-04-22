#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d",&t);
  int qq=t;
  while(t--){
    unsigned long long l,g;
    scanf("%llu %llu",&l,&g);
    printf("Case %d: %llu\n",qq-t,(l*g)/2);
  }
  return 0;
}