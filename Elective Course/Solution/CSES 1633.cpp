#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;
 
const int N = 1e6 + 5;
 
int n;
vector <int> dp(N);
 
signed main(){
	SalAC;
	
	cin >> n;
	dp[0] = 1;
	for (int i=1; i<=n; i++){
		for (int j=max(i-6, 0); j!=i; j++){
			dp[i] = (dp[i] + dp[j]) % ((int)1e9 + 7);
		}
	}
	cout << dp[n];
}