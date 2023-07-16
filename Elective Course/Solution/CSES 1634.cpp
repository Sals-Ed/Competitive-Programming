#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
#define int long long
using namespace std;
 
const int INF = (int)9e18;
 
int n, x;
vector <int> c(105);
vector <int> dp(1000005, INF);
 
signed main(){
	SalAC;
	
	cin >> n >> x;
	for (int i=0; i<n; i++) cin >> c[i], dp[c[i]] = 1;
	sort(c.begin(), c.begin()+n);
	
	for (int i=1; i<=x; i++){
		for (int j=0; j<n; j++){
			if (i <= c[j]) break;
			if (!dp[i - c[j]]) continue;
			dp[i] = min(dp[i], dp[i - c[j]]+1);
		}
	}
	cout << ((dp[x] != INF)? dp[x]: -1);
}