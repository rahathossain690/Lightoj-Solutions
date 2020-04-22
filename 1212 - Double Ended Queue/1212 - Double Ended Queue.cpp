#include <bits/stdc++.h>
using namespace std;
  int main() {
    ios_base::sync_with_stdio(false);
    int t,q;
    cin>>t;
    q=t;
    while(t--){
        int n,m;
        cin>>n>>m;
        list<int>a;
        list<int>::iterator it;
        int ini = 0,k;
        string cmd;
        cout<<"Case "<<q-t<<":"<<endl;
        while(m--){
            cin>>cmd;
            if(!cmd.compare("pushLeft")){
                cin>>k;
                if(n>ini){
                    a.push_front(k);
                    cout<<"Pushed in left: "<<k;
                    ini++;
                }
                else cout<<"The queue is full";
            }
            else if(!cmd.compare("pushRight")){
                cin>>k;
                if(n>ini){
                    a.push_back(k);
                    cout<<"Pushed in right: "<<k;
                    ini++;
                }
                else cout<<"The queue is full";
            }
            else if(!cmd.compare("popLeft")){
                if(ini>0){
                    it = a.begin();
                    k = *it;
                    a.pop_front();
                    cout<<"Popped from left: "<<k;
                    ini--;
                }
                else cout<<"The queue is empty";
            }
            else{
                if(ini>0){
                    k=a.back();
                    a.pop_back();
                    cout<<"Popped from right: "<<k;
                    ini--;
                }
                else cout<<"The queue is empty";
            }
            cout<<endl;
        }
    }
    return 0;
}