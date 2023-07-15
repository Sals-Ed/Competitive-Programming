#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
#define pb push_back
#define int long long
using namespace std;
typedef pair<int,int> pii;
 
const int N = 1e5 + 5;

int n, k, arr[2][N], dp[2][N];

signed main(){
    SalAC;
    
    cin >> n >> k;
    
    arr[0][0] = arr[1][0] = k;

    for (int i=1; i<=n; i++){
        for (int j=0, l, r; j<2; j++){
            cin >> arr[j][i];
        }
    }

    for (int i=1; i<=n; i++){
        for (int j=0; j<2; j++){
            int disL = abs(arr[j][i] - arr[0][i-1]);
            int disR = abs(arr[j][i] - arr[1][i-1]);
            dp[j][i] = min(dp[0][i-1] + disL, dp[1][i-1] + disR);
        }
    }

    cout << min(dp[0][n], dp[1][n]);
}