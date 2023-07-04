#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;

struct node{
    int min, max;
};

const int N = 50005;

int n, q, arr[N];

node st[N<<1];

void build(){
	for (int i=n-1; i>0; i--){
		st[i].min = min(st[i<<1].min, st[i<<1|1].min);
		st[i].max = max(st[i<<1].max, st[i<<1|1].max);
	}
}

node query(int l, int r){
	node ans;
	ans.min = 1e9;
	ans.max = 0;
	for (l+=n, r+=n; l<r; l>>=1, r>>=1){
		if (l & 1){
			ans.min = min(ans.min, st[l].min);
			ans.max = max(ans.max, st[l].max);
			l++;
		}
		if (r & 1){
			--r;
			ans.min = min(ans.min, st[r].min);
			ans.max = max(ans.max, st[r].max);
		}
	}
	return ans;
}

signed main(){
    SalAC;
    
    cin >> n >> q;
    
    for (int i=0, val; i<n; i++){
    	cin >> val;
    	st[i+n].min = st[i+n].max = val;
    }
    
    build();
    
    for (int i=0, a, b; i<q; i++){
        cin >> a >> b;
        node data = query(a-1, b);
        cout << data.max - data.min << "\n";
    }
}