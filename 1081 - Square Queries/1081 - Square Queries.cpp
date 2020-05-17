#include<bits/stdc++.h>
using namespace std;
 
const int N = 505;
const int LOG = 10;
 
int st[N][N][LOG]; // sparse table
int a[N][N], n, q, l, r, s, T, TC;
 
int MAX(int a, int b, int c, int d){
    return max( max(a, b), max(c, d) );
}
 
void create_table(){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            st[i][j][0] = a[i][j];
    for(int k = 1; (1 << k) <= n; k++){
        int INC = 1 << (k-1);
        for(int i = 0; i + INC -1 < n; i++)
            for(int j = 0; j + INC -1 < n; j++){
                st[i][j][k] = MAX( st[i][j][k - 1], st[i + INC][j][k - 1], st[i][j + INC][k - 1], st[i + INC][j + INC][k - 1]);
            }
    }
}
 
int query(int l, int r, int s){
    int gap = log2(s);
    int INC = 1 << gap;
    return MAX( st[l][r][gap], st[l][r - INC + s][gap], st[l - INC + s][r][gap], st[l - INC + s][r - INC + s][gap]);
}
 
void solve(){
    scanf("%d %d", &n, &q);
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) scanf("%d", &a[i][j]);
    create_table();
    while(q--){
        scanf("%d %d %d", &l, &r, &s);
        printf("%d\n", query(l - 1, r - 1, s));
    }
}
 
int main(){
    for(scanf("%d", &TC); T < TC; T++){
        printf("Case %d:\n", T + 1);
        solve();
    }
}