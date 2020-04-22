#include "bits/stdc++.h"
using namespace std;
  #define td(n) scanf("%d",&n)
#define pb push_back
  int a[51],b[51];
  int main(){
  int t=1,tc;
  for(td(tc);t<=tc;t++){
    int n;
    td(n);
    for(int i = 0; i< n;i++) td(a[i]);
    for(int i = 0; i< n;i++) td(b[i]);
    sort(a,a+n);
    sort(b,b+n);
    int ans = 0;
    for(int i = 0; i < n; i++){
      int temp = 0;
      for(int j = 0; j < n; j++){
        if(a[(j + i)%n] > b[j]) temp += 2;
        if(a[(j + i)%n] == b[j]) temp += 1;
      }
      ans = max(ans, temp);
    }
    printf("Case %d: %d\n",t,ans);
  }
}