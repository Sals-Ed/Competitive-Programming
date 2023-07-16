#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
#define int long long
using namespace std;
 
int n, k, val, ans;
queue <int> q;
map <int, int> mp;
 
void push(int i){
	if (!mp.count(i)){
		while (mp.size() == k){
			ans += q.size();
			mp[q.front()]--;
			if (!mp[q.front()]) mp.erase(q.front());
			q.pop();
		}
	}
	mp[i]++; q.push(i);
}
 
signed main(){
	SalAC;
	
	cin >> n >> k;
	for (int i=0; i<n; i++){
		cin >> val;
		push(val);
	}
	int rem = (int)q.size();
	cout << ans + (rem*(rem+1))/2;
}
