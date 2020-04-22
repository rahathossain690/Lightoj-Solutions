#include "bits/stdc++.h"
using namespace std;
  #define ll long long
#define pb push_back
#define endl "\n"
  bool Check(int N,int pos){return (bool)(N & (1<<pos));}
int Set(int N,int pos){ return N=N | (1<<pos);}
  int rahatVaiErBinarySearch(int *mul, int n, int num){
    int hi = n-1,lo = 0,mid;
    while(hi>lo){
        mid = (hi+lo)>>1;
        if(mul[mid] == num) return mid;
        else if(mul[mid] < num) lo = mid + 1;
        else hi = mid - 1;
    }
    if(mid!=n-1)mid++;
    while(mul[mid]>num)mid--;
    return mid;
}
  int N =100000010;
int status[3125011];
int prim[11000000],sz=0;
void sieve()
{
     int i, j, sqrtN;
     sqrtN = int( sqrt( N ) );
     for( i = 3; i <= sqrtN; i += 2 )
     {
         if( Check(status[i>>5],i&31)==0)
         {
             for( j = i*i; j <= N; j += (i<<1) )
             {
                 status[j>>5]=Set(status[j>>5],j & 31)   ;
             }
         }
     }
     prim[sz++]=2;
     for(i=3;i<=N;i+=2)
         if( Check(status[i>>5],i&31)==0)
            prim[sz++]=i;
}
  ll kotobar(int n, int p){
      ll ans = 1;
    for(;;ans *= p){
        if(ans == n) return ans;
        else if(ans > n) return ans/p;
    }
}
unsigned int mul[10010];
  void save(){
    int m = 1;
    unsigned int k = mul[0];
    for(int i=1;i<sz;i++){
            k = k * prim[i];
            if(i % 1000 == 0)mul[m++] = k;
    }
}
  unsigned int val(int k){
    unsigned ans = mul[k / 1000];
    int to = k%1000;
    for(int i = 1;i <= to; i++) ans *= prim[1000*(k/1000) + i];
    return ans;
}
  int main(){ //freopen("in.txt","r",stdin);
    sieve();
    mul[0]=prim[0];
    save();
    int t=1,n,tc;
    for(scanf("%d",&tc);t<=tc;t++){
        unsigned int ans=1;
        scanf("%d",&n);
        int i;
        for(i = 0;prim[i]*prim[i]<=n;i++){
            ans *= kotobar(n,prim[i]) / prim[i];
        }
        ans *= val(rahatVaiErBinarySearch(prim,sz,n));
        printf("Case %d: %u\n",t,ans);
    }
}