#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
#define int long long
using namespace std;
 
const int N = 505;
const int LIM = (N*(N+1))/4;
const int mod = 1e9 + 7;
 
int n;
int dp[LIM];
 
int sum(){
	return (n*(n+1))/2;
}
 
signed main(){
	SalAC;
	
	cin >> n;
	
	dp[0] = 1;
	
	for (int i=1; i<=n; i++){
		for (int j=LIM-1; j>=0; j--){
			if (j-i >= 0){
				dp[j] = (dp[j-i] + dp[j]) % mod;
			}
		}
	}
	
	cout << (!(sum() & 1) ? (dp[sum()/2]*((int)5e8+4)) % mod : 0);
}