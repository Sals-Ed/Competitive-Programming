#include <bits/stdc++.h>
#define f first  // 表示x座標
#define s second // 表示y座標
using namespace std;
typedef pair<int, int> pii;

int n, L, ans;
vector <pii> v;
deque <pii> mxst;
deque <pii> mnst;

void init(){ //座標先排序
	
	for (int i=0; i<n; i++)	cin >> v[i].f;
	for (int i=0; i<n; i++) cin >> v[i].s;
	
	sort(v.begin(), v.end());
}

void push(pii x){
	
	while (!mxst.empty() && x.f - mxst.front().f > L) mxst.pop_front();
	while (!mnst.empty() && x.f - mnst.front().f > L) mnst.pop_front();
	//當x座標超出預定範圍則彈出元素
	
	while (!mxst.empty() && x.s > mxst.back().s) mxst.pop_back();
	while (!mnst.empty() && x.s < mnst.back().s) mnst.pop_back();
	
	mxst.push_back(x);
	mnst.push_back(x);
	
	ans = max(ans, mxst.front().s - mnst.front().s);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> L;
	
	v.resize(n);
	
	init();
	
	for (auto i: v) push(i);
	
	cout << ans;
}
