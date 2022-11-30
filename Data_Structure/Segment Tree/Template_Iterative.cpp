#include <iostream>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;

// 線段樹以維護區間最大值為範例

struct segment_tree{
	
	static const int N = 2e5 + 5;
	
	int n;
	int st[N<<1];
	
	void init(int arr[]){
        	for (int i=0; i<n; i++){
            		st[i+n] = arr[i];
        	}
        	for (int i=n-1; i>=0; i--){
            		st[i] = max(st[i<<1], st[i<<1|1]);
        	}
    	}
	
	void modify(int i, int val){
		//(modifyIndex, modifyValue)
        	st[i+=n] = val;
        	while (i){
            		st[i>>1] = max(st[i], st[i^1]);
            		i >>= 1;
        	}
	}
	
	int query(int l, int r){ 
		//(queryLeft, queryRight)
        	// query for [l, r)
        	int ans = 0;
		for (l+=n, r+=n; l<r; l>>=1, r>>=1){
            		if (l & 1) ans = max(ans, st[l++]);
            		if (r & 1) ans = max(ans, st[--r]);
        	}
		return ans;
	}
}sample;

signed main(){
	fastio;
	
	int arr[] = {3, 2, 1, 5, 6, 8, 4, 9, 12, 0}; 
	
    	sample.n = 10;
	sample.init(arr);
	
	cout << sample.query(0, 5) << "\n"; // {3, 2, 1, 5, 6}
	cout << sample.query(2, 4) << "\n"; // {1, 5}
	cout << sample.query(5, 9) << "\n"; // {8, 4, 9, 12}
	cout << sample.query(6, 10) << "\n"; // {4, 9, 12, 0}
    
	sample.modify(8, 10); // arr[8] 12 -> 10
	sample.modify(5, 13); // arr[5]  8 -> 13
    
	// {{3, 2, 1, 5, 6, 13, 4, 9, 10, 0}}
    
	cout << sample.query(0, 5) << "\n"; // {3, 2, 1, 5, 6}
	cout << sample.query(2, 4) << "\n"; // {1, 5}
	cout << sample.query(5, 9) << "\n"; // {13, 4, 9, 10}
	cout << sample.query(6, 10) << "\n"; // {4, 9, 10, 0}
}
