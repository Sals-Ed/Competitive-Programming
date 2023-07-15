#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
#define int long long
using namespace std;

const int N = 1e5 + 5;

int n, tot, piz;

priority_queue <int, vector<int>, greater<int>> pq;

signed main(){
	SalAC;
	
	cin >> n;
	
	for (int i=1, val; i<=n; i++){
		cin >> val;
		tot += val;
		pq.push(val);
	}
	
	while (pq.size() > 1){
		int x = pq.top(); pq.pop();
		int y = pq.top(); pq.pop();
		piz += x + y;
		pq.push(x + y);
	}
	
	cout << tot << "\n" << piz;
}
