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
    return a.s < b.s;
}

signed main(){
	SalAC;
	
	cin >> n;
	
	for (int i=1; i<=n; i++) cin >> arr[i].f >> arr[i].s;
	
	sort(arr+1, arr+n+1, cmp);
	
	int ans = 0, tail = -1;
	
	for (int i=1; i<=n; i++){
	   if (tail < arr[i].f){
	        ++ans;
	        tail = arr[i].s;
	   }
	}
	
	cout << ans;
}
