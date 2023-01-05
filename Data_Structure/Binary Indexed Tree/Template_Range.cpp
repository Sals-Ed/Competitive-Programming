#include <iostream>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;

// Binary Indexed Tree 帶區間修改為範例

struct BIT_Range{
	
	static const int N = 1e5 + 5;
	
	int n;

	int D[N], BIT1[N], BIT2[N];

	int lowbit(int i){
		return (i & -i);
	}
	
	void init(int t[]){
		for (int i=1; i<=n; i++){
			D[i] = t[i] - t[i-1];
		}
		for (int i=1; i<=n; i++){
			BIT1[i] += D[i];
			BIT1[i+lowbit(i)] += BIT1[i];
			BIT2[i] += D[i] * i;
			BIT2[i+lowbit(i)] += BIT2[i];
		}
	}
	
	void update(int i, int val){
		int valMul = i * val;
		while (i <= n){
			BIT1[i] += val;
			BIT2[i] += valMul;
			i += lowbit(i);
		}
	}

	void modify(int l, int r, int val){
		update(l, val);
		update(r+1, -val);
	}

	int get(int theBIT[], int i){
		int ans = 0;
		while (i){
			ans += theBIT[i];
			i -= lowbit(i);
		}
		return ans;
	}

	int query(int l, int r){
		int Lval = l * get(BIT1, l-1) - get(BIT2, l-1);
		int Rval = (r+1) * get(BIT1, r) - get(BIT2, r);
		return Rval - Lval;
	}
}sample;

signed main(){
	fastio;
	
	int arr[] = {0, 8, 3, 2, 4, 1, 8, 9, 2}; 
	
	sample.n = 8;
	sample.init(arr);

	cout << sample.query(2, 5) << "\n"; // {3, 2, 4, 1}
	cout << sample.query(4, 8) << "\n"; // {4, 1, 8, 9, 2}
	sample.modify(5, 7, 1); // {0, 8, 3, 2, 4, 2, 9, 10, 2}
	sample.modify(2, 6, -2); // {0, 8, 1, 0, 2, 0, 7, 10, 2}
	cout << sample.query(4, 8) << "\n"; // {2, 0, 7, 10, 2}
	cout << sample.query(1, 7) << "\n"; // {8, 1, 0, 2, 0, 7, 10}
}