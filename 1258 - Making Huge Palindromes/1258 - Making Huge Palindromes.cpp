#include<bits/stdc++.h>
using namespace std;
  typedef long long ll;
const int N = 1000005;
  string a, pat;
char tem[N];
int f[N], t, tc;
  void getString(){
  scanf("%s", tem);
  a = tem;
}
  void ex(string tex){
  memset(f, 0, sizeof f);
  for(int i = 1, j = 0; i < tex.size();){
    if(tex[i] != tex[j]) {
      if(j == 0) f[i++] = 0;
      else j = f[j - 1];
    }
    else{
      f[i++] = ++j;
    }
  }
}
  int solve(){
  getString();
  pat = a;
  reverse(pat.begin(), pat.end());
  int last = 0;
  ex(pat);
  for(int i = 0, j = 0; i < a.size(); i++){
    if(a[i] == pat[j]) j++, last = j;
    else {
      if(j != 0) j = f[j - 1], --i;
      else j = 0;
      last = j;
    }
  }
  return 2 * a.size() - last;
}
  int main(){
  for(scanf("%d", &tc); t < tc; printf("Case %d: %d\n", ++t, solve()));
}