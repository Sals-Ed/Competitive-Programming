#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;

const int N = 14;

int n, ans;
int mask[N], maze[N][N];

bool valid(int end, int target){
    if (!target) return true;
    for (int i=1; i<end; i++){
        if (!mask[i]) continue;
        if (mask[i] == target || abs(mask[i] - target) == end - i){
            return false;
        }
    }
    return true;
}

int cal(int end){
    int sum = 0;
    for (int i=1; i<=end; i++){
        sum += maze[mask[i]][i];
    }
    return sum;
}

void nQueen(int idx){
    if (idx > n) return;
    for (int i=0; i<=n; i++){
        if (valid(idx, i)){
            mask[idx] = i;
            ans = max(ans, cal(idx));
            nQueen(idx+1);
        }
    }
    return;
}

signed main(){
    SalAC;
    
    cin >> n;
    
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cin >> maze[i][j];
        }
    }
    
    nQueen(1);
    
    cout << ans;
}