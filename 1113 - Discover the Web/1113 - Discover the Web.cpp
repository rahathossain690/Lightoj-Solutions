#include <bits/stdc++.h>
using namespace std;
  int main() {
    ios_base::sync_with_stdio(false);
    int t,q;
    cin>>t;
    q=t;
    while(t--){
        int i = 0,end = 0,k=0;
        string cmd,url[101],done[101];
        cin>>cmd;
        url[0]="http://www.lightoj.com/";
        done[k]=url[i];
        k=1;
        while(cmd.compare("QUIT")){
            if(!cmd.compare("VISIT")){
                i++;
                end=i;
                cin>>url[i];
                done[k]=url[i];
            }
            else if(!cmd.compare("BACK") && i>0){
                i--;
                done[k]=url[i];
            }
            else if(!cmd.compare("FORWARD")&&i<end){
                i++;
                done[k]=url[i];
            }
            else done[k]="Ignored";
            k++;
            cin>>cmd;
        }
        cout<<"Case "<<q-t<<":"<<endl;
        for(int i=1;i<k;i++){
            cout<<done[i]<<endl;
        }
    }
    return 0;
}