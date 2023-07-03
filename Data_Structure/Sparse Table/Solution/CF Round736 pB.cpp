#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
#define int long long
using namespace std;

const int N = 200005;

int t, n, ans, l, r;
int arr[N], st[20][N];

void sparse_table(){ 
	for (int i=1; i<=n; i++) st[0][i] = arr[i];
	for (int i=1; i<=n; i++) st[1][i] = abs(arr[i] - arr[i+1]);
	for (int i=2; i<20; i++){
		for (int j=1; j<=n; j++){
			st[i][j] = __gcd(st[i-1][j], st[i-1][j+(1<<(i-1))]);
			st[i][j] = __gcd(st[i][j], st[1][j+(1<<(i-1))-1]);
		}
	}
}

int query(int l, int r){
	int idx = __lg(r - l + 1);
	return __gcd(st[idx][l], st[idx][r-(1<<idx)+1]);
}

signed main(){
	SalAC;
	
	cin >> t;
	while (t--){
		cin >> n;
		ans = 0, l = 1, r = 1;
		for (int i=1; i<=n; i++) cin >> arr[i];
		sparse_table();
		for (; r<=n; r++){
			while (l < r && query(l, r) == 1){
				++l;
			}
			ans = max(ans, r-l+1);
		}
		cout << ans << "\n";
	}
}