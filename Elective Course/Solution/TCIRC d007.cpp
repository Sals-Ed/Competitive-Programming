#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
#define int long long
using namespace std;

int n, k, arr[30], ans = 0;

void recur(int idx, int tmpSum){
    if (idx > n){
        if (tmpSum <= k){
            ans = max(ans, tmpSum);
        }
        return;
    }
    recur(idx+1, tmpSum+arr[idx]);
    recur(idx+1, tmpSum);
}

signed main(){
	SalAC;
	
	cin >> n >> k;
	
	for (int i=1; i<=n; i++) cin >> arr[i];
	
	recur(1, 0);
	
	cout << ans;
}