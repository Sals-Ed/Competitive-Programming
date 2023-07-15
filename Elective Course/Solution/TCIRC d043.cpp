#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
#define int long long
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;

const int N = 1e5 + 5;

int n, enemy[N], mine[N];

signed main(){
	SalAC;
	
	cin >> n;
	
	for (int i=1; i<=n; i++) cin >> enemy[i];
	for (int i=1; i<=n; i++) cin >> mine[i];
	
	sort(enemy+1, enemy+n+1, greater<int>());
	sort(mine+1, mine+n+1, greater<int>());
	
	int ans = 0, ptr = 1;
	for (int i=1; i<=n; i++){
	    while (ptr <= n){
	        if (mine[i] > enemy[ptr++]){
	            ans++;
	            break;
	        }
	        ptr++;
	    }
	    if (ptr > n) break;
	}
	
	cout << ans;
}
