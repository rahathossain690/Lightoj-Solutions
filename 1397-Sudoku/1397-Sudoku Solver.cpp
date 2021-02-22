#include<bits/stdc++.h>
using namespace std;
const int N = 12, MAX = 10000;


int t, tc;

int a[N][N];
char s[N];

bool used_row[N][N], used_col[N][N], used_sub[N][N];


int sub_index(int i, int j) {
	int ans = 0;

	if(j <= 3) ans = 1;
	else if(j <= 6) ans = 2;
	else ans = 3;

	if(i <= 3) ans += 0;
	else if(i <= 6) ans += 3;
	else ans += 6;

	return ans;
}

bool possible(int i, int j, int k){
	return !used_row[i][k] and !used_col[j][k] and !used_sub[ sub_index(i, j) ][k];
}

void sset(int i,int j,int k) {
	used_row[i][k] = used_col[j][k] = used_sub[ sub_index(i, j) ][k] = 1;
}

void sunset(int i,int j,int k) {
	used_row[i][k] = used_col[j][k] = used_sub[ sub_index(i, j) ][k] = 0;
}

pair<int, int> find_best(){
	int mn = INT_MAX, x = -1, y = -1, yes = 0;
	for(int i = 1; i <= 9; i++){
		for(int j = 1; j <= 9; j++){
			if(a[i][j]) {
				continue;
			}
			yes = 1;
			int cnt = 0;
			for(int k = 1; k <= 9; k++) cnt += possible(i, j, k);
				//cout << cnt << endl;
			if(mn > cnt){
				mn = cnt;
				x = i;
				y = j;
			} 
		}
	}
	if(!yes) return {-1, -1};
	return {x, y};
}

bool rec(){
	// if(x == 10) return true;
	// if(y == 10) return rec(x + 1, 1);
	// if(a[x][y]) {
	// 	return rec(x, y + 1);
	// }
	// for(int k = 1; k <= 9; k++){
	// 	if(possible(x, y, k)){ //cout << x << " " << y << " " << k << endl;
	// 		sset(x, y, k);
	// 		a[x][y] = k;
	// 		int ret = rec(x, y + 1);
	// 		if(ret) return true;
	// 		sunset(x, y, k);
	// 		a[x][y] = 0;
	// 	}
	// } //cout  << "r " << x << " " << y << endl;
	// return false;
	pair<int, int> pr = find_best();
	int x = pr.first;
	int y = pr.second; //cout << x << " " << y << endl;
	if(x == -1 and y == -1) return true;
	for(int k = 1; k <= 9; k++){
		if(possible(x, y, k)){
			sset(x, y, k);
			a[x][y] = k;
			bool ret = rec();
			if(ret) return true;
			sunset(x, y, k);
			a[x][y] = 0;
		}
	}
	return false;
}

void show(int ar[][N]){
	for(int i = 1; i<= 9; i++){
		for(int j = 1; j <= 9; j++){
			printf("%d", ar[i][j]);
			printf(j != 9 ? "": "\n");
		}
	}
}

void showb(bool ar[][N]){
	for(int i = 1; i<= 9; i++){
		for(int j = 1; j <= 9; j++){
			printf("%d", ar[i][j]);
			printf(j != 9 ? " ": "\n");
		}
	}
}

void solve(){
	memset(a, 0, sizeof a);
	memset(used_col, 0, sizeof used_col);
	memset(used_row, 0, sizeof used_row);
	memset(used_sub, 0, sizeof used_sub);

	for(int i = 1; i <= 9; i++){
		scanf("%s", s);
		for(int j = 1; j <= 9; j++){
			if('0' <= s[j - 1] and s[j - 1] <= '9') {
				int num = s[j - 1] - '0';
				a[i][j] = num;
				sset(i, j, num); 
			}
		}
	}

	// showb(used_sub);
	rec();

	show(a);

}

int main(){
    for(scanf("%d", &tc); t < tc; t++){
        printf("Case %d:\n", t + 1);
        solve();
    }
}
