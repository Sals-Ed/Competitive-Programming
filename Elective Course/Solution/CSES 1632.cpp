#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
#define end_t first
#define sta_t second
using namespace std;
typedef pair <int, int> pii;
 
int n, k, a, b, ans;
vector <pii> matt;
multiset <int> crew;
 
signed main(){
	SalAC;
	
	cin >> n >> k;
	for (int i=0; i<k; i++) crew.insert(0);
	for (int i=0; i<n; i++){
		cin >> a >> b;
		matt.push_back({b, a});
	}
	sort(matt.begin(), matt.end());
	for (int i=0; i<n; i++){
		auto data = matt[i];
		auto idx = crew.lower_bound(matt[i].sta_t);
		if (idx == crew.begin()){
			if (*idx <= matt[i].sta_t){
				ans++;
				crew.erase(idx);
				crew.insert(matt[i].end_t);
			}
		}
		else{
			ans++; idx--;
			crew.erase(idx);
			crew.insert(matt[i].end_t);
		}
	}
	cout << ans;
}
