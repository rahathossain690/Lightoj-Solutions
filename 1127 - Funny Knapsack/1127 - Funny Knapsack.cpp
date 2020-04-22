#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
vector<ull> p1,p2;
void way1(int limit,int array[],int position,ull sum,ull w){
    if(sum > w) return;
    if(position >= limit){
        p1.push_back(sum);
        return;
    }
    way1(limit,array,position+1,sum+array[position],w);
    way1(limit,array,position+1,sum,w);
}
  void way2(int limit,int array[],int position,ull sum,ull w){
    if(sum > w) return;
    if(position >= limit){
        p2.push_back(sum);
        return;
    }
    way2(limit,array,position+1,sum+array[position],w);
    way2(limit,array,position+1,sum,w);
}
 int bins(ull n){
    int hi = p2.size() , lo = 0,mid;
    while(hi>lo){
        mid = (lo+hi)>>1;
        if(p2[mid]==n){
            while(p2[mid+1]==n&&mid+1<p2.size())mid++;
            return mid+1;
        }
        else if(p2[mid]>n)hi = mid;
        else lo = mid + 1;
    }
    while(p2[mid]>n)mid--;
    return mid+1;
}
int main() {
    //freopen("in.txt","r",stdin);
    int t,qq;
    scanf("%d",&t);
    qq=t;
    while(t--){
    int n;
    ull w;
    scanf("%d%llu",&n,&w);
    int a[n];
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    p1.clear(),p2.clear();
    way1(n/2,a,0,0,w);
    way2(n,a,n/2,0,w);
    sort(p2.begin(),p2.end());
    unsigned long long q=0;
    for(int i=0;i<p1.size();i++){
        q += bins(w-p1[i]);
        /*
        if(p2[0] <= w-p1[i]){
            int lo = 0, hi = p2.size()-1,mid;
            while(lo<=hi){
            mid = (lo+hi)/2;
            if(p2[mid] == w-p1[i])break;
            else if(p2[mid] > w-p1[i])hi=mid-1;
            else  lo = mid+1;
            }
            q+=mid+1;
        }*/
    }
    printf("Case %d: %llu\n",qq-t,q);
    }
    return 0;
}