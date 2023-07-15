#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;

const int N = 505;

int n, m, dp[N][N];

string s1, s2;

signed main(){
    SalAC;
    
    cin >> s1 >> s2;
    
    n = (int)s1.size();
    m = (int)s2.size();
    
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    cout << dp[n][m];
}
