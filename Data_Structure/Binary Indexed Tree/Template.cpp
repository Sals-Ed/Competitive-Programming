#include <iostream>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;

// Binary Indexed Tree 以動態前綴和為範例

struct Binary_Indexed_Tree{
	
	static const int N = 1e5 + 5;
	
	int n;

	int BIT[N];

	int lowbit(int i){
		return (i & -i);
	}
	
	void init(int arr[]){
		for (int i=1; i<=n; i++){
			BIT[i] += arr[i];
			BIT[i+lowbit(i)] += BIT[i];
		}
	}
	
	void modify(int i, int val){
		while (i <= n){
			BIT[i] += val;
			i += lowbit(i);
		}
	}
	
	int query(int i){
		int ans = 0;
		while (i){
			ans += BIT[i];
			i -= lowbit(i);
		}
		return ans;
	}
}sample;

signed main(){
	fastio;
	
	int arr[] = {0, 8, 3, 2, 4, 1, 8, 9, 2}; 
	
	sample.n = 8;
	sample.init(arr);

	cout << sample.query(3) << "\n"; // {8, 3, 2}
	cout << sample.query(5) << "\n"; // {8, 3, 2, 4, 1}
	cout << sample.query(8) << "\n"; // {8, 3, 2, 4, 1, 8, 9, 2}
	sample.modify(2, 6); // {8, 9, 2, 4, 1, 8, 9, 2};
	sample.modify(7, 1); // {8, 3, 2, 4, 1, 8, 10, 2};
	cout << sample.query(3) << "\n"; // {8, 9, 2}
	cout << sample.query(5) << "\n"; // {8, 9, 2, 4, 1}
	cout << sample.query(8) << "\n"; // {8, 9, 2, 4, 1, 8, 10, 2}
}