#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;
 
int n, x, s, top;
int w[105], v[105];
int ww[1205], vv[1205];
int dp[100005];
 
signed main(){
	SalAC;
	
	cin >> n >> x;
	for (int i=0; i<n; i++) cin >> w[i];
	for (int i=0; i<n; i++) cin >> v[i];
	for (int i=0; i<n; i++){
		cin >> s;
		int c = 1;
		while (s - c >= 0){
			s -= c;
			ww[top] = w[i] * c;
			vv[top] = v[i] * c;
			c <<= 1;
			top++;
		}
		if (s){
			ww[top] = w[i] * s;
			vv[top] = v[i] * s;
			top++;
		}
	}
	for (int i=0; i<top; i++){
		for (int j=x; j>0; j--){
			if (j - ww[i] >= 0){
				dp[j] = max(dp[j], dp[j-ww[i]] + vv[i]);
			}
		}
	}
	cout << dp[x];
}