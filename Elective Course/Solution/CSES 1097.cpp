#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
#define int long long
using namespace std;
 
const int N = 5005;
 
int n;
int arr[N], pre[N], dp[N][N];
 
void init(){
	for (int i=1; i<=n; i++) pre[i] = pre[i-1] + arr[i];
	for (int i=1; i<=n; i++) dp[i][i] = arr[i];
}
 
int sum(int l, int r){
	return (pre[r] - pre[l-1]);
}
 
signed main(){
	SalAC;
	
	cin >> n;
	
	for (int i=1; i<=n; i++) cin >> arr[i];
	
	init();
	
	for (int i=n; i>0; i--){
		for (int j=i+1; j<=n; j++){
			dp[i][j] = max(arr[i] + sum(i+1, j) - dp[i+1][j], arr[j] + sum(i, j-1) - dp[i][j-1]);
		}
	}
	
	cout << dp[1][n];
}