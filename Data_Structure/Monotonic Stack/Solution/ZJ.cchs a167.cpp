#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;

const int N = 2e5 + 5;

int n;
ll ans;
stack <pii> stk; // first維護高度, second 維護位置

signed main(){
	SalAC;
	
	cin >> n;
	
	for (int i=1, val; i<=n; i++){
		
		cin >> val;
		
		while (!stk.empty() && stk.top().f <= val){
			stk.pop();
		} //維護最接近的高人位置
		
		if (stk.empty()){ //代表是當前最高者
			ans += i;
		}
		else{
			ans += i - stk.top().s;
		}
		
		stk.push({val, i});
	}
	cout << ans;
}