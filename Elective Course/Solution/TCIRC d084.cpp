#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;
typedef pair<int,int> pii;
 
const int N = 1e5 + 5;

int n, k, arr[N], dp[N];
int fnt = 0, bk = -1, mq[N];

void push(int idx){
    while (fnt <= bk && dp[mq[bk]] <= dp[idx]) bk--;
    mq[++bk] = idx;
}

int getMax(int idx){
    if (idx - mq[fnt] > k) fnt++;
    return dp[mq[fnt]];
}

signed main(){
    SalAC;

    cin >> n >> k;
    
    for (int i=1; i<=n; i++) cin >> arr[i];
    
    for (int i=1; i<=n; i++){
        dp[i] = max(getMax(i), dp[max(i-k-1, 0)]+arr[i]);
        push(i);
    }
    
    cout << dp[n];
}
