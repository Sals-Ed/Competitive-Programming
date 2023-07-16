#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
#define int long long
using namespace std;
 
const int mod = (int)1e9 + 7; 
 
int n, x;
int c[105];
int dp[1000005];
 
signed main(){
	
	cin >> n >> x;
 
	for (int i=0; i<n; i++) cin >> c[i];
	sort(c, c+n);
	
	dp[0] = 1;
	for (int i=0; i<n; i++){
		for (int j=1; j<=x; j++){
			if (c[i] > j) continue;
			dp[j] += dp[j-c[i]];
			dp[j] %= mod;
		}
	}
	cout << dp[x];
}