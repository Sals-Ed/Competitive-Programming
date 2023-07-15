#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;
 
const int N = 205;

int n, k, pos[N], dp[N][N];

int rec(int l, int r){
    if (r-l <= 1){
        return 0;
    }
    if (dp[l][r]) return dp[l][r];
    int ans = 1e9;
    int L = l, R = r;
    for (int i=l+1; i<r; i++){
        ans = min(ans, rec(l, i) + rec(i, r) + pos[r] - pos[l]);
    }
    return dp[l][r] = ans;
}

signed main(){
    SalAC;

    cin >> n >> k;

    for (int i=1; i<=n; i++) cin >> pos[i]; pos[n+1] = k;

    cout << rec(0, n+1);
}
