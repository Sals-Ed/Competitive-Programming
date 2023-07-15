#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
#define int long long
#define pb push_back
using namespace std;

const int N = 20;

int n, w[1<<N], dp[1<<N];

signed main(){
	SalAC;
	
	cin >> n;
	
	memset(dp, 0, sizeof(dp));
	
	for (int i=0; i<(1<<n); i++) cin >> w[i];
	
	dp[0] = w[0];
	
	for (int i=0; i<(1<<n); i++){
		for (int j=0; j<n; j++){
			if (i&(1<<j)){
				dp[i] = max(dp[i], dp[i-(1<<j)] + w[i]);
			}
		}
	}
	
	cout << dp[(1<<n)-1];
}
