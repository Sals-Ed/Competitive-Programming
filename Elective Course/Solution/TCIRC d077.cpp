#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;
typedef pair<int,int> pii;
 
const int N = 2e5 + 5;

int n, k, area, arr[N], dp[N];
int fnt = 0, bk = -1, monoq[N];

void push(int idx){
    while (fnt <= bk && dp[monoq[bk]] >= dp[idx]) bk--;
    monoq[++bk] = idx;
}

int getMin(int idx){
    if (monoq[fnt] + area < idx) fnt++;
    return dp[monoq[fnt]];
}

signed main(){
    SalAC;

    cin >> n >> k;

    area = 2 * k + 1;

    for (int i=1; i<=n; i++) cin >> arr[i];

    for (int i=1; i<k+2; i++){
        dp[i] = arr[i];
        push(i);
    }

    for (int i=k+2; i<=n; i++){
        dp[i] = getMin(i) + arr[i];
        push(i);
    }

    int Minimum = 9e18;

    for (int i=n; i>=n-k; i--){
        Minimum = min(Minimum, dp[i]);
    } 

    cout << Minimum;
}
