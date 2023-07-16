#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
#define pb emplace_back
using namespace std;
 
int n, val;
vector <int> v;
 
signed main(){
	SalAC;
	
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> val;
		int idx = lower_bound(v.begin(), v.end(), val) - v.begin();
		if (idx == v.size()) v.pb(val);
		else v[idx] = val;
	}
	cout << (int)v.size();
}
