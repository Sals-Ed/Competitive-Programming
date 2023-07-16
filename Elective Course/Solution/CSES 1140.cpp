#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
#define pb push_back
#define int long long
using namespace std;
 
const int N = 200005;
 
struct project{
 
	int f, s, w;
	
	bool operator <(const project &x) const{
		return f < x.f;
	}
	
} arr[N];
 
int n, BIT[N<<1], dp[N<<1];
vector <int> v;
 
void init(){
	v.pb(-1);
	sort(v.begin(), v.end());
	v.resize(distance(v.begin(), unique(v.begin(), v.end())));
	sort(arr, arr+n);
}
 
int get(int val){
	return (lower_bound(v.begin(), v.end(), val) - v.begin());
}
 
void modify(int i, int v){
	while (i <= (n<<1)){
		BIT[i] = max(BIT[i], v);
		i += (i & -i);
	}
}
 
int query(int i){
	int ans = 0;
	while (i){
		ans = max(ans, BIT[i]);
		i -= (i & -i);
	}
	return ans;
}
 
signed main(){
	SalAC;
	
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> arr[i].f >> arr[i].s >> arr[i].w;
		v.pb(arr[i].f);
		v.pb(arr[i].s);
	}
	init();
	for (int i=0; i<n; i++){
		dp[get(arr[i].s)] = max(dp[get(arr[i].s)], query(get(arr[i].f)-1) + arr[i].w);
		modify(get(arr[i].s), dp[get(arr[i].s)]);
	}
	cout << query(n<<1);
}