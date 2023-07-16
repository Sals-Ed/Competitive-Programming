#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;
 
const int N = 1e5 + 5;
 
int n, v;
 
bitset <N> vis(1);
 
signed main(){
	SalAC;
	
	cin >> n;
	
	while (n--){
		cin >> v;
		vis |= (vis << v);
	}
	
	cout << vis.count()-1 << "\n";
	
	for (int i=0; i<N; i++){
		if (vis[i] && i) cout << i << " ";
	}
}