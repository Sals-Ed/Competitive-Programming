#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
#define int long long
using namespace std;
typedef pair<int,int> pii;
 
const int N = 105;
const int MAXN = 1e5 + 5;

int n, k, w[MAXN], v[MAXN], dp[MAXN];

signed main(){
    SalAC;
 
    cin >> n >> k;
    
    for (int i=1; i<=n; i++) cin >> w[i];
    for (int i=1; i<=n; i++) cin >> v[i];

    for (int i=1; i<=n; i++){
        for (int j=k; j>0; j--){
            if (j-w[i] < 0) break;
            dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
        }
    }

    cout << dp[k];
}
