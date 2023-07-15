#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;

int n;
int arr[100001];
vector <int> v;

signed main(){
	SalAC;
	
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> arr[i];
		v.emplace_back(arr[i]);
	}
	sort(v.begin(), v.end());
	auto ip = unique(v.begin(), v.end());
	for (int i=0; i<n; i++) cout << lower_bound(v.begin(), ip, arr[i]) - v.begin() << " ";
}
