#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;

const int N = 1e5 + 5;

int n, l, arr[N<<1], BIT[N<<1];
long long ans;
bitset <N> vis;

void modify(int i){
	while (i <= n){
		BIT[i]++;
		i += (i & -i);
	}
}

int query(int i){
	int ans = 0;
	while (i){
		ans += BIT[i];
		i -= (i & -i);
	}
	return ans;
}

signed main(){
	SalAC;
	
	cin >> n; l = n << 1;
	for (int i, val; i<l; i++){
		cin >> val;
		ans += (vis[val]? query(val-1): -query(val-1));
		vis[val] = true;
		modify(val);
	}
	cout << ans;
}