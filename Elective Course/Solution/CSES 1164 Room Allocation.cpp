#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
#define f first
#define s second
using namespace std;
typedef pair <int, int> pii;
 
int n, a, b, now = 1;
int room[200005], depa[200005];
priority_queue <pii, vector<pii>, greater<pii>> cust;
priority_queue <pii, vector<pii>, greater<pii>> allo;
 
signed main(){
	SalAC;
	
	cin >> n;
	for (int i=1; i<=n; i++){
		cin >> a >> b;
		cust.push({a, i}); depa[i] = b;
	}
	allo.push({0, 1});
	while (!cust.empty()){
		auto cuta = cust.top(); cust.pop();
		auto rota = allo.top();
		if (rota.f < cuta.f){
			allo.pop();
			allo.push({depa[cuta.s], rota.s});
			room[cuta.s] = rota.s;
		}
		else{
			now++;
			allo.push({depa[cuta.s], now});
			room[cuta.s] = now;
		}
	}
	cout << now << "\n";
	for (int i=1; i<=n; i++) cout << room[i] << " ";
}