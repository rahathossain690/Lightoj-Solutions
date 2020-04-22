#include "bits/stdc++.h"
using namespace std;
  #define max(a, b) (a>b?a:b)
  int p[1130], sz = 1;
bool siv[10000];
string ans = "Rahat Voch 8)";
  string multyply(string a, int b){
  int carry = 0;
  ans = "";
  for(int i = 0; i < a.size(); i++){
    carry = ((a[i] - '0') * b + carry);
    ans += carry % 10 + '0';
    carry /= 10;
  }
  while(carry != 0){
    ans += carry % 10  + '0';
    carry /= 10;
  }
  return ans;
}
  int n, a, num, t = 1, tc;
  int main(){
  p[0] = 2;
  for(int i = 3; i * i <= 10000; i+=2){
    if(!siv[i]){
      for(int j = i*i; j <= 10000; j += i + i) siv[j] = 1;
    }
  }
  for(int i = 3; i <= 10000; i+=2) if(!siv[i])p[sz++] = i;
  for(scanf("%d", &tc); t <= tc; t++){
    scanf("%d", &n);
    map <int, int> pf;
    for(int i = 0; i < n; i++){
      scanf("%d", &a);
      for(int j = 0; j < sz && p[j]*p[j] <= a; j++){
        if(a % p[j] == 0){
          num = 1;
          while(a % p[j] == 0){
            num *= p[j];
            a /= p[j];
          }
          pf[p[j]] = max(pf[p[j]], num);
        }
      }
      if(a != 1) pf[a] = max(pf[a], a);
    }
    string ans = "1";
    for(map<int, int>:: iterator it = pf.begin(); it != pf.end(); it++){
      ans = multyply(ans, it->second);
    }
    reverse(ans.begin(), ans.end());
    printf("Case %d: %s\n", t, ans.c_str());
  }
  return 0;
}