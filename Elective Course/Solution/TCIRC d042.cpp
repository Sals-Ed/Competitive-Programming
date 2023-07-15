#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
#define int long long
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;

const int N = 1e5 + 5;

int n;

int judge(int val){
    int cnt = 0;
    cnt += val/50; val %= 50;
    cnt += val/10; val %= 10;
    cnt += val/5; val %= 5;
    cnt += val/1; val %= 1;
    return cnt;
}

signed main(){
	SalAC;
	
	cin >> n;
	
	for (int i=0, val; i<n; i++) cin >> val, cout << judge(val) << "\n";
}
