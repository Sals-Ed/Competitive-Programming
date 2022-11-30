#include <bits/stdc++.h>
#define ppf pop_front
#define ppb pop_back
#define puf push_front
#define pub push_back
#define ept empty
using namespace std;

int n, L, ans = 0;
int arr[200005];
deque <int> mx; //維護區間最大值
deque <int> mn; //維護區間最小值

void push(int x, int y = (int)1e9+5){ // x為欲插入元素、y為欲彈出之元素
	
	if (!mx.ept() && y == mx.front()) mx.ppf();
	if (!mn.ept() && y == mn.front()) mn.ppf();
	
	while (!mx.ept() && x > mx.back()) mx.ppb();
	while (!mn.ept() && x < mn.back()) mn.ppb();
	
	mx.pub(x);
	mn.pub(x);
	
	ans = max(ans, mx.front() - mn.front());
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> L;
	
	for (int i=0; i<n; i++) cin >> arr[i];
	for (int i=0; i<L; i++) push(arr[i]);
	for (int i=L; i<n; i++) push(arr[i], arr[i-L]);
	
	cout << ans;
}
