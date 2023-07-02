#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;
 
const int N = 200005;

int n, q;
int ans[N], BIT[N];

int lowbit(int i){
	return (i & -i);
}

void init(){
	for (int i=1; i<=n; i++){
		BIT[i] = 1<<__lg(lowbit(i));
	}
}

void modify(int i){
	while (i <= n){
		BIT[i]--;
		i += lowbit(i);
	}
}

int query(int k){
	int ans = 0;
	for (int i=18; i>=0; i--){
		int level = 1<<i;
		if (ans + level <= n && BIT[ans+level] < k){
			ans += level;
			k -= BIT[ans];
		}
	}
	++ans;
	return ans;
}

signed main(){
	SalAC;
	
	cin >> n >> q;
	init(); memset(ans, -1, sizeof(ans));
	for (int i=1, l, r; i<=q; i++){
		cin >> l >> r;
		int t = r - l + 1;
		while (t--){
			int idx = query(l);
			if (idx > n) break;
			ans[idx] = i;
			modify(idx);
		}
	}
	for (int i=1; i<=n; i++) cout << ans[i] << " ";
}