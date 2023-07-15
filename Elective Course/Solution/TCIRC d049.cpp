#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;

const int N = 5e4 + 5;

int n, k, l, r, arr[N];

bool valid(int dis){
	int rest = k, pos = 1;
	while (rest && pos <= n){
		--rest;
		pos = upper_bound(arr+1, arr+n+1, arr[pos]+dis) - arr;
	}
	if (pos <= n){
		return false;
	}
	return true;
}

signed main(){
	SalAC;
	
	cin >> n >> k;
	
	for (int i=1; i<=n; i++) cin >> arr[i];
	
	sort(arr+1, arr+n+1);
	
	l = 1;
	r = arr[n];
	
	while (l < r){
		int mid = (l + r) >> 1;
		if (valid(mid)) r = mid;
		else l = mid+1;
	}
	
	cout << r;
}
