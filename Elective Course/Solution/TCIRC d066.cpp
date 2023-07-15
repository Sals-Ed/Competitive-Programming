#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;

const int N = 1e5 + 5;

int n, prv, nxt, ans;

signed main(){
	SalAC;
	
	cin >> n >> nxt;
	
	ans = nxt;
	
	for (int i=2, val; i<=n; i++){
		cin >> val;
		ans = min(prv, nxt) + val;
		prv = nxt;
		nxt = ans;
	}
	
	cout << ans;
}