#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
 
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
 
int n, m;
int arr[N];
 
vector <int> dp(101);
vector <int> tmp(101);
 
void init(){
	if (arr[1]) dp[arr[1]] = 1;
	else for (int i=1; i<=m; i++) dp[i] = 1;
}
 
pii getRange(int i){
	return {max(1, i-1), min(m, i+1)};
}
 
signed main(){
	SalAC;
	
	cin >> n >> m;
	for (int i=1; i<=n; i++) cin >> arr[i];
	init();
	for (int i=2; i<=n; i++){
		swap(dp, tmp);
		dp.assign(101, 0);
		if (arr[i]){
			if (arr[i-1]){
				if (abs(arr[i-1] - arr[i]) <= 1) dp[arr[i]] = tmp[arr[i-1]];
			}
			else{
				pii range = getRange(arr[i]);
				for (int j=range.f; j<=range.s; j++){
					dp[arr[i]] = (dp[arr[i]] + tmp[j]) % mod;
				}
			}
		}
		else{
			for (int j=1; j<=m; j++){
				pii range = getRange(j);
				for (int k=range.f; k<=range.s; k++){
					dp[j] = (dp[j] + tmp[k]) % mod;
				}
			}
		}
	}
	int ans = 0;
	for (int i: dp) ans = (ans + i) % mod;
	cout << ans;
}
