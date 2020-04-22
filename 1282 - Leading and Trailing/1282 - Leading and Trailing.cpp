#include "bits/stdc++.h"
using namespace std;
  long long last(long long n, long long p){
  if(p == 0) return 1;
  if(p == 1) return n%1000;
  long long ans = last(n, p/2);
  ans = (ans * ans) % 1000;
  if(p&1) ans = (ans * n) % 1000;
  return ans;
}
  int main(){ //freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
  int t = 1, tc;
  long long n, p, first;
  double temp;
  for(scanf("%d",&tc); t <= tc; t++){
    scanf("%lld %lld",&n,&p);
    temp = p * 1.0 * log10(n * 1.0);
    temp -= (int) temp;
    first = 100 * pow(10.0 , temp);
    printf("Case %d: %lld %03lld\n",t, first, last(n, p));
  }
}