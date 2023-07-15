#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
#define int long long
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;

const int N = 1e5 + 5;

int n, arr[N];

signed main(){
	SalAC;
	
	cin >> n;
	
	for (int i=1; i<=n; i++) cin >> arr[i];
	
	sort(arr+1, arr+n+1);
	
	int ans = 0;
	
	for (int i=1; i<=n; i++){
	   arr[i] += arr[i-1];
	   ans += arr[i];
	}
	
	cout << ans;
}
