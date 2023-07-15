#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
#define int long long
using namespace std;

const int N = 1e5 + 5;

int n, arr[N], dp[N];

signed main(){
	SalAC;
	
	cin >> n;
	
	for (int i=1; i<=n; i++) cin >> arr[i];
	
	dp[1] = arr[1], dp[2] = arr[2], dp[3] = arr[3] + dp[1];
	
	for (int i=4; i<=n; i++){
		dp[i] = min(dp[i-1], min(dp[i-2], dp[i-3])) + arr[i];
	}
	if (n == 1) cout << dp[1];
	else cout << min(dp[n], dp[n-1]);
}
