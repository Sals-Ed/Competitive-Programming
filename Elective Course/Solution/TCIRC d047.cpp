#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
#define int long long
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;

const int N = 1e5 + 5;

int n;

pii arr[N];

bool cmp(pii a, pii b){
    if (a.f * b.s < b.f * a.s) return true;
    return false;
}

signed main(){
	SalAC;
	
	cin >> n;
	
	for (int i=1, val; i<=n; i++) cin >> arr[i].f;
	for (int i=1, val; i<=n; i++) cin >> arr[i].s;
	
	sort(arr+1, arr+n+1, cmp);
	
	int ans = 0;
	
	for(int i=1, tot=0; i<=n; i++){
	    ans += tot * arr[i].s;
	    tot += arr[i].f;
	}
	
	cout << ans;
}
