#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
#define int long long
using namespace std;

const int N = 1e5 + 5;

int n, mini = 1e9 + 7, ans;

signed main(){
    SalAC;
    
    cin >> n;
    
    for (int i=1, val; i<=n; i++){
        cin >> val;
        mini = min(mini, val);
        ans = max(ans, val - mini);
    }
    cout << ans;
}
