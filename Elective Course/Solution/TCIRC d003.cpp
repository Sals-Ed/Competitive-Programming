#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
#define int long long
using namespace std;

const int N = 5e4 + 5;

int n, L, arr[N];

int cost(int l, int r){
	if (r - l <= 1) return 0;
	int midValue = (arr[l] + arr[r]) >> 1;
	int midIndex = lower_bound(arr+l, arr+r, midValue) - arr;
	if (arr[midIndex-1] - arr[l] >= arr[r] - arr[midIndex]) --midIndex;
	return (cost(l, midIndex) + cost(midIndex, r) + arr[r] - arr[l]);
}

signed main(){
	SalAC;
	
	cin >> n >> L;
	
	for (int i=1; i<=n; i++) cin >> arr[i];
	
	arr[n+1] = L;
	
	cout << cost(0, n+1);
}