#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
#define int long long
#define pb push_back
using namespace std;

const int N = 31;
const int INF = 1e9;

int n, m, maze[N][N], dp[N][N][N][N];

int solve(int a, int b, int c, int d){
	if (!(a-b) || !(c-d)) return dp[a][b][c][d] = 0;
	if (dp[a][b][c][d] != -1) return dp[a][b][c][d];
	int ans = INF, cnt;
	cnt = 0;
	for (int i=a; i<=b; i++){
		if (maze[i][c]){
			++cnt;
		}
	}
	ans = min(ans, solve(a, b, c+1, d)+min(b-a+1-cnt, cnt));
	cnt = 0;
	for (int i=a; i<=b; i++){
		if (maze[i][d]){
			++cnt;
		}
	}
	ans = min(ans, solve(a, b, c, d-1)+min(b-a+1-cnt, cnt));
	cnt = 0;
	for (int i=c; i<=d; i++){
		if (maze[a][i]){
			++cnt;
		}
	}
	ans = min(ans, solve(a+1, b, c, d)+min(d-c+1-cnt, cnt));
	cnt = 0;
	for (int i=c; i<=d; i++){
		if (maze[b][i]){
			++cnt;
		}
	}
	ans = min(ans, solve(a, b-1, c, d)+min(d-c+1-cnt, cnt));
	return dp[a][b][c][d] = ans;
}

signed main(){
	SalAC;
	
	cin >> n >> m;
	
	for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++){
			cin >> maze[i][j];
		}
	}
	
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
			for (int k=1; k<=m; k++){
				for (int g=1; g<=m; g++){
					dp[i][j][k][g] = -1;
				}
			}
		}
	}
	
	cout << solve(1, n, 1, m);
}