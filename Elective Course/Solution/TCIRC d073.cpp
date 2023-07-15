#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
#define int long long
using namespace std;
typedef pair<int,int> pii;
 
const int N = 205;

int n, m, maze[N][N], pre[N][N], ans;

signed main(){
    SalAC;

    cin >> n >> m;

    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> maze[i][j];
            pre[i][j] = pre[i-1][j] + maze[i][j];
        }
    }

    for (int i=1; i<=n; i++){
        for (int j=i; j<=n; j++){
            int tmp = 0;
            for (int k=1; k<=m; k++){
                tmp = pre[j][k] - pre[i-1][k] + max(tmp, (ll)0);
                ans = max(ans, tmp);
            }
        }
    }

    cout << ans;
}