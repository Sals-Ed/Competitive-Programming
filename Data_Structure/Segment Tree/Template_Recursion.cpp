#include <iostream>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;

// 線段樹以維護區間最大值為範例

int left(int i){
	return (i << 1);
}

int right(int i){
	return (i << 1 | 1);
}

struct segment_tree{
	
	static const int N = 2e5 + 5;
	
	int n;
	int st[N<<2];
	
	void build(int i, int l, int r, int t[]){
		//(curIndex, curLeft, curRight, refArray)
		if (l == r){
			st[i] = t[l];
			return;
		}
		int mid = (l + r) >> 1;
		build(left(i), l, mid, t);
		build(right(i), mid+1, r, t);
		st[i] = max(st[left(i)], st[right(i)]);
	}
	
	void modify(int i, int pos, int val, int l, int r){
		//(curIndex, modifyIndex, modifyValue, curLeft, curRight)
		if (l == r){
			st[i] = val;
			return;
		}
		int mid = (l + r) >> 1;
		if (pos <= mid){
			modify(left(i), pos, val, l, mid);
		}
		else{
			modify(right(i), pos, val, mid+1, r);
		}
		st[i] = max(st[left(i)], st[right(i)]);
	}
	
	int query(int i, int ql, int qr, int l, int r){ 
		//(curIndex, queryLeft, queryRight, curLeft, curRight)
		// query for [ql, qr]
		if (ql <= l && r <= qr) return st[i];
		int ans = 0, mid = (l + r) >> 1;
		if (ql <= mid){
			ans = max(ans, query(left(i), ql, qr, l, mid));
		}
		if (mid < qr){
			ans = max(ans, query(right(i), ql, qr, mid+1, r));
		}
		return ans;
	}
}sample;

signed main(){
	fastio;
	
	int arr[] = {3, 2, 1, 5, 6, 8, 4, 9, 12, 0}; 
	
	sample.n = 10;
	sample.build(1, 0, sample.n-1, arr);
	
	cout << sample.query(1, 0, 4, 0, sample.n-1) << "\n"; // {3, 2, 1, 5, 6}
	cout << sample.query(1, 2, 3, 0, sample.n-1) << "\n"; // {1, 5}
	cout << sample.query(1, 5, 8, 0, sample.n-1) << "\n"; // {8, 4, 9, 12}
	cout << sample.query(1, 6, 9, 0, sample.n-1) << "\n"; // {4, 9, 12, 0}
    
	sample.modify(1, 8, 10, 0, sample.n-1); // arr[8] 12 -> 10
	sample.modify(1, 5, 13, 0, sample.n-1); // arr[5]  8 -> 13
    
	// {{3, 2, 1, 5, 6, 13, 4, 9, 10, 0}}
    
	cout << sample.query(1, 0, 4, 0, sample.n-1) << "\n"; // {3, 2, 1, 5, 6}
	cout << sample.query(1, 2, 3, 0, sample.n-1) << "\n"; // {1, 5}
	cout << sample.query(1, 5, 8, 0, sample.n-1) << "\n"; // {13, 4, 9, 10}
	cout << sample.query(1, 6, 9, 0, sample.n-1) << "\n"; // {4, 9, 10, 0}
}
