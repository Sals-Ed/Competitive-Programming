#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;
 
const int N = 1e6 + 5;
const int INF = 1e9;
 
int n, dp[N];
 
int func(int x){
	if (dp[x] != INF) return dp[x];
	if (!(x / 10)) return dp[x] = 1;
	int tmp = x;
	while (tmp){
		if (tmp % 10) dp[x] = min(dp[x], func(x - tmp % 10) + 1);
		tmp /= 10;
	}
	return dp[x];
}
 
signed main(){
	SalAC;
	
	cin >> n;
	
	fill(dp, dp+N, INF);
	
	cout << func(n);
}