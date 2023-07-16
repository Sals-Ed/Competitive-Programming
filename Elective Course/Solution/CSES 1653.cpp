#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
 
const int N = 20;
 
int n, wgt, arr[N], lim;
 
pii dp[1<<N];
 
signed main(){
	SalAC;
	
	cin >> n >> wgt;
	
	lim = 1 << n;
	
	dp[0] = {0, wgt+1};
	
	for (int i=0; i<n; i++) cin >> arr[i];
	
	for (int i=1; i<lim; i++){ dp[i] = {21, 0};
		
		for (int j=0; j<n; j++){
			
			if (i>>j & 1){
				
				pii tmp = dp[i^(1<<j)];
				
				int tt = tmp.f, ww = tmp.s;
				
				if (ww + arr[j] > wgt){
					dp[i] = min(dp[i], {tt+1, min(ww, arr[j])});
				}
				
				else{
					dp[i] = min(dp[i], {tt, ww + arr[j]});
				}
			}
		}
	}
	
	cout << dp[(1<<n)-1].f;
}