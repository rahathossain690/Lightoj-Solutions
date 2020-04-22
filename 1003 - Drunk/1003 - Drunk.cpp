#include<bits/stdc++.h>
  using namespace std;
  #define pb push_back
  const int MAX = 10005;
map <string, int> dic;
vector<int> node[MAX];
int vis[MAX];
bool dhora = false;
string word[2];
char temp[20];
  void in(int n){
    scanf(" %s ",temp);
    word[n] = temp;
}
    void dfs(int n){
    if(vis[n]==2) return;
    if(vis[n] == 1){
        dhora = true;
        return;
    }
    vis[n] = 1;
    for(int i = 0;i < node[n].size();i++)dfs(node[n][i]);
    vis[n] = 2;
}
    int main(){ //freopen("in.txt","r",stdin);
    int t=1,tc;
    for(scanf("%d",&tc);t<=tc;t++){
        int n, i = 1;
        scanf("%d",&n);
        dhora = false;
        for(int k = 0;k < n;k++){
            in(0);
            if(dic[word[0]]==0)dic[word[0]]=i++;
            in(1);
            if(dic[word[1]]==0)dic[word[1]]=i++;
            node[dic[word[0]]].push_back(dic[word[1]]);
        }
        for(int p = 1;p<i;p++){
            if(vis[p] == 0 && !dhora)dfs(p);
        }
        printf("Case %d: ",t);
        printf(dhora?"No\n":"Yes\n");
        dic.clear();
        memset(vis,0,sizeof(vis));
        for(int k = 0;k<i;k++)node[k].clear();
    }
    return 0;
}