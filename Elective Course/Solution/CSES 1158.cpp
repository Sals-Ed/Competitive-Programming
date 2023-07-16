#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
#define int long long
#define f first
#define s second
using namespace std;
 
int n, x;
int dp[100005];
pair<int,int> book[1005];
 
signed main(){
	SalAC;
	
	cin >> n >> x;
	for (int i=0; i<n; i++) cin >> book[i].f;
	for (int i=0; i<n; i++) cin >> book[i].s;
	sort(book, book+n);
	
	for (int i=0; i<n; i++){
		for (int j=x; j>0; j--){
			if (j >= book[i].f){
				dp[j] = max(dp[j], dp[j-book[i].f]+book[i].s);
			}
		}
	}
	cout << dp[x];
}