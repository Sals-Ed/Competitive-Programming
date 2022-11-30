#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
#define ll long long
using namespace std;

static const int N = 5e5 + 5;

int n, k, l, r;
int arr[N];
ll ans;

struct monotonic_queue{
	
	int dq[N];
	int front = 0, back = -1;
	
	void push(int i, bool mode){
		
		if (mode){
			while (front <= back && arr[i] >= arr[dq[back]]) --back;
			dq[++back] = i;
		}
		
		else{
			while (front <= back && arr[i] <= arr[dq[back]]) --back;
			dq[++back] = i;
		}
	}
} mx, mn;

bool valid(){
	return ((arr[mx.dq[mx.front]] - arr[mn.dq[mn.front]] > k) ? false : true);
}

signed main(){
	SalAC;
	
	cin >> n >> k;
	
	for (int i=0; i<n; i++) cin >> arr[i];
	
	for (; r<n; r++){
		
		mx.push(r, true);
		mn.push(r, false);
		
		while (!valid()){
			if (mx.dq[mx.front] == l) ++mx.front;
			if (mn.dq[mn.front] == l) ++mn.front;
			ans += r - l;
			++l;
		}
	}
	
	ll d = r - l;
	ans += (d * (d + 1)) / 2;
	
	cout << ans;
}