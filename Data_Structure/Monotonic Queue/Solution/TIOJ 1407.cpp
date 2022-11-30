#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;
typedef long long ll;

const int MAXN = 1e6 + 5;

int n, cap;

int dq[MAXN], fnt, bk;

vector <int> W, V, C;
vector <ll> dp1;
vector <ll> dp2;

signed main(){
	SalAC;
	
	cin >> n;
	
	W.resize(n+1);
	V.resize(n+1);
	C.resize(n+1);
	
	for (int i=1; i<=n; i++) cin >> W[i] >> V[i] >> C[i];
	
	cin >> cap;
	
	dp1.assign(cap+1, 0);
	dp2.assign(cap+1, 0);
	
	for (int i=1, w, v, c; i<=n; i++){
		
		w = W[i]; v = V[i]; c = C[i];
		
		swap(dp1, dp2);
		
		for (int j=0; j<w; j++){
			
			fnt = 0, bk = -1;
			
			for (int k=j; k<=cap; k+=w){
				
				dp1[k] = dp2[k];
				
				if (fnt <= bk && k > dq[fnt] + w * c) ++fnt;
				if (fnt <= bk) dp1[k] = max(dp1[k], dp2[dq[fnt]] + (k - dq[fnt]) / w * v);
				
				while (fnt <= bk && dp2[dq[bk]] + (k - dq[bk]) / w * v <= dp2[k]) --bk;
				
				dq[++bk] = k;
			}
		}
	}
	cout << dp1[cap];
}