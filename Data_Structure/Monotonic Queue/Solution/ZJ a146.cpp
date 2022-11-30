#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
#define f first
#define s second
#define pb push_back
using namespace std;
typedef pair <int, int> pii; // first維護數值, second維護位置

int n, k;
deque <pii> mxst;
deque <pii> mnst;
vector <int> out_mx; //答案存入vector
vector <int> out_mn;

void init(){
	mxst.clear();
	mnst.clear();
	out_mx.clear();
	out_mn.clear();
}

void push(int i, int v){ //單調隊列維護區間最大/最小值
	if (!mxst.empty() && mxst.front().s == (i - k)) mxst.pop_front();
	if (!mnst.empty() && mnst.front().s == (i - k)) mnst.pop_front();
	
	while (!mxst.empty() && v > mxst.back().f) mxst.pop_back();
	while (!mnst.empty() && v < mnst.back().f) mnst.pop_back();
	
	mxst.push_back({v, i});
	mnst.push_back({v, i});
	
	out_mx.pb(mxst.front().f);
	out_mn.pb(mnst.front().f);
}

signed main(){
	SalAC;
	
	while (cin >> n >> k){
		
		k = min(k, n);
		
		init();
		
		for (int i=0, v; i<n; i++) cin >> v, push(i, v);
		for (int i=k-1; i<n; i++) cout << out_mn[i] << ((i != n-1) ? " ": ""); cout << "\n";
		for (int i=k-1; i<n; i++) cout << out_mx[i] << ((i != n-1) ? " ": ""); cout << "\n";
		//嚴格比對，輸出完不能有空白
	}
}