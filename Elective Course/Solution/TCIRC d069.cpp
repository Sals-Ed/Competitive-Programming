#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;

const int N = 205;

int n, m, maze[N][N], dp[N][N];

signed main(){
    SalAC;
    
    cin >> n >> m;
    
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> maze[i][j];
        }
    }
    
    dp[1][1] = maze[1][1];
    
    for (int i=2; i<=n; i++){
        dp[i][1] = dp[i-1][1] + maze[i][1];
    }
    
    for (int j=2; j<=m; j++){
        dp[1][j] = dp[1][j-1] + maze[1][j];
    }
    
    for (int i=2; i<=n; i++){
        for (int j=2; j<=m; j++){
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + maze[i][j];
        }
    }
    
    cout << dp[n][m];
}