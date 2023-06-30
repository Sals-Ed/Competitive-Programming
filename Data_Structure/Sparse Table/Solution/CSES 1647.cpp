#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;
 
const int N = 2e5 + 5;
 
int n, m;
int arr[N], st[20][N];
 
void sparse_table(){
	for (int i=1; i<=n; i++) st[0][i] = arr[i];
	for (int i=1; i<20; i++){
		for (int j=1; j<=n; j++){
			st[i][j] = min(st[i-1][j], st[i-1][j+(1<<(i-1))]);
		}
	}
}
 
int query(int l, int r){
	int idx = __lg(r - l + 1);
	return min(st[idx][l], st[idx][r-(1<<idx)+1]);
}
 
signed main(){
	SalAC;
	
	cin >> n >> m;
	for (int i=1; i<=n; i++) cin >> arr[i];
	
	sparse_table();
	
	for (int i=0, l, r; i<m; i++){
		cin >> l >> r;
		cout << query(l, r) << "\n";
	}
}