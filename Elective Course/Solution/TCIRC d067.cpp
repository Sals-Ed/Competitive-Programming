#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;

const int N = 1e5 + 5;

int n, arr[N], dp[N];

signed main(){
	SalAC;
	
	cin >> n;
	
	for (int i=1; i<=n; i++) cin >> arr[i];
	
	dp[1] = arr[1];
	
	for (int i=2; i<=n; i++){
		dp[i] = max(dp[i-1], dp[i-2]+arr[i]);
	}
	
	cout << dp[n];
}