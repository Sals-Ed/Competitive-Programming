#include <iostream>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;

// st表以維護區間最小值為範例

struct sparse_table{
	
	int n;
	static const int N = 2e5 + 5;
	static const int LIM = __lg(N);
	
	int st[LIM][N];
	
	void init(int t[]){
		for (int i=0; i<n; i++) st[0][i] = t[i];
		for (int i=1; i<=LIM; i++){
			for (int j=0; j<n; j++){
				st[i][j] = min(st[i-1][j], st[i-1][j+(1<<(i-1))]);
			}
		}
	}
	
	int query(int l, int r){
		int p = __lg(r - l + 1);
		return min(st[p][l], st[p][r-(1<<p)+1]);
	}
}sample;

signed main(){
	fastio;
	
	int arr[] = {3, 2, 1, 5, 6, 8, 4, 9, 12, 0};
	
	sample.n = 10;
	sample.init(arr);
	
	cout << sample.query(0, 4) << "\n"; // {3, 2, 1, 5, 6}
	cout << sample.query(2, 3) << "\n"; // {1, 5}
	cout << sample.query(5, 8) << "\n"; // {8, 4, 9, 12}
	cout << sample.query(6, 9) << "\n"; // {4, 9, 12, 0}
}
