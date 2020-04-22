#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
    int main(){
    int t,q;
    cin>>t;
    q=t;
    while(t--){
    unsigned long long a,b,n=0;
    cin>>a;
    b=a;
    vector <int> v;
    while(a){
        v.push_back(a%2);
        a=a/2;
    }
    v.push_back(0);
        reverse(v.begin(),v.end());
    next_permutation(v.begin(), v.end());
    for(int i=v.size()-1;i>=0;i--)n+=v[i]*pow(2,v.size()-i-1);
    cout<<"Case "<<q-t<<": "<<n<<endl;
    }
    return 0;
}