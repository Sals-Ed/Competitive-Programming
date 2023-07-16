#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
#define f first
#define s second
#define int long long
using namespace std;
typedef pair <int, int> pii;
 
int n, ans, a, b, now;
priority_queue <pii, vector<pii>, greater<pii>> pq;
 
signed main(){
	SalAC;
	
	cin >> n;
	while (n--){
		cin >> a >> b;
		pq.push({a, b});
	}
	while (!pq.empty()){
		auto data = pq.top(); pq.pop();
		now += data.f;
		ans += data.s - now;
	}
	cout << ans;
}