#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;

// Merge Sort Tree 以回傳區間比 k 小的元素個數

int left(int i){
	return i<<1;
}

int right(int i){
	return i<<1|1;
}

struct MergeSort_Tree{
	
	static const int N = 1e5 + 5;
	
	int n;

	vector <int> st[N<<2];

	void build(int i, int l, int r, int arr[]){
		if (l == r){
			st[i].clear();
			st[i].push_back(arr[l]);
			return;
		}
		int mid = (l + r) >> 1;
		build(left(i), l, mid, arr);
		build(right(i), mid+1, r, arr);
		st[i].resize(r-l+1);
		merge(st[left(i)].begin(), st[left(i)].end(), st[right(i)].begin(), st[right(i)].end(), st[i].begin());
	}
	
	int query(int i, int ql, int qr, int l, int r, int k){ 
		//(curIndex, queryLeft, queryRight, curLeft, curRight, kValue)
		if (ql <= l && r <= qr){
			return upper_bound(st[i].begin(), st[i].end(), k) - st[i].begin();
		}
		int ans = 0;
		int mid = (l + r) >> 1;
		if (ql <= mid){
			ans += query(left(i), ql, qr, l, mid, k);
		}
		if (mid < qr){
			ans += query(right(i), ql, qr, mid+1, r, k);
		}
		return ans;
	}
}sample;

signed main(){
	fastio;
	
	int arr[] = {8, 3, 2, 4, 1, 8, 9, 2}; 
	
	sample.n = 8;
	sample.build(1, 0, 7, arr);

	cout << sample.query(1, 1, 7, 0, sample.n-1, 4) << "\n"; // {3, 2, 4, 1, 8, 9, 2}
	cout << sample.query(1, 2, 4, 0, sample.n-1, 9) << "\n"; // {2, 4, 1}
	cout << sample.query(1, 0, 7, 0, sample.n-1, 2) << "\n"; // {8, 3, 2, 4, 1, 8, 9, 2}
	cout << sample.query(1, 3, 6, 0, sample.n-1, 7) << "\n"; // {4, 1, 8, 9}
}