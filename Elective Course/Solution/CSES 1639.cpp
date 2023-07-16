#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
#define str string
using namespace std;
 
const int N = 5005;
 
str s1, s2;
int n, m, dp[N][N];
 
void init(){
	for (int i=0; i<N; i++) dp[i][0] = dp[0][i] = i;
}
 
signed main(){
	SalAC;
	
	cin >> s1 >> s2;
	
	n = s1.size(), m = s2.size();
	
	init();
	
	for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++){
			if (s1[i-1] == s2[j-1]){
				dp[i][j] = dp[i-1][j-1];
			}
			else{
				dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) + 1;
			}
		}
	}
	cout << dp[n][m];
}