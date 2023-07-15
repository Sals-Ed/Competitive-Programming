#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
#define int long long
using namespace std;

int n, arr[30], ans;

int recur(int idx, int tmpMul){
    if (idx > n){
        if (tmpMul == 1) return 1;
        else return 0;
    }
    return recur(idx+1, (tmpMul*arr[idx])%10009) + recur(idx+1, tmpMul);
}

signed main(){
	SalAC;
	
	cin >> n;
	
	for (int i=1; i<=n; i++) cin >> arr[i];
	
	cout << recur(1, 1) - 1;
}