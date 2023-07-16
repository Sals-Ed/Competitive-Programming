#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
#define end_t first
#define start_t second
using namespace std;
typedef pair <int, int> pii;
 
int n, a, b, ans, e;
priority_queue <pii, vector<pii>, greater<pii>> pq;
 
signed main(){
	SalAC;
	
	cin >> n;
	while (n--){
		cin >> a >> b;
		pq.push({b, a});
	}
	while (!pq.empty()){
		auto data = pq.top(); pq.pop();
		if (e <= data.start_t) ans++, e = data.end_t;
	}
	cout << ans;
}