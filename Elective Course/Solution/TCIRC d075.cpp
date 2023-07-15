#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
#define int long long
using namespace std;
typedef pair<int,int> pii;
 
const int N = 2e5 + 5;

int n, m, cap, tot;

bitset <N> dp(1);

signed main(){
    SalAC;
    
    cin >> n >> m >> cap;

    for (int i=0, val; i<n; i++){
        cin >> val;
        tot += val;
        dp |= (dp << val);
    }

    cap -= (m - tot);
    
    if (cap < 0){
        cout << 0;
        return 0;
    }

    for (int i=cap; i<=m; i++){
        if (dp[i]){
            cout << i;
            break;
        }
    }
}