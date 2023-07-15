#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
#define pb push_back
using namespace std;
 
const int N = 2e5 + 5;

int n;

vector <int> LIS;

signed main(){
    SalAC;

    cin >> n;

    for (int i=0, val; i<n; i++){
        cin >> val;
        int idx = lower_bound(LIS.begin(), LIS.end(), val) - LIS.begin();
        if (idx == LIS.size()) LIS.pb(val);
        else LIS[idx] = val;
    }

    cout << (int)LIS.size();
}
