#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;
 
const int N = 505;
const int INF =  1e9;
 
int n, m, dp[N][N];
 
void init(){
	for (int i=0; i<N; i++) fill(dp[i], dp[i]+N, INF);
	for (int i=0; i<N; i++) dp[i][i] = 0;
}
 
signed main(){
	SalAC;
	
	cin >> n >> m;
	
	init();
	
	for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++){
			for (int k=1; k<i; k++){
				dp[i][j] = min(dp[i][j], dp[i-k][j] + dp[k][j] + 1);
			}
			for (int k=1; k<j; k++){
				dp[i][j] = min(dp[i][j], dp[i][j-k] + dp[i][k] + 1);
			}
		}
	}
	cout << dp[n][m];
}