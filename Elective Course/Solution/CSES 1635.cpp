#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
#define int long long
using namespace std;
 
const int mod = (int)1e9 + 7; 
 
int n, x;
int c[105];
int dp[1000005];
 
signed main(){
	SalAC;
	
	cin >> n >> x;
 
	for (int i=0; i<n; i++) cin >> c[i];
	sort(c, c+n);
	
	dp[0] = 1;
	for (int i=c[0]; i<=x; i++){
		for (int j=0; j<n; j++){
			if (c[j] > i) break;
			dp[i] = dp[i] + dp[i-c[j]];
		}
		dp[i] %= mod;
	}
	cout << dp[x];
}