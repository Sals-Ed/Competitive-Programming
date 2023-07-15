#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
#define int long long
using namespace std;
typedef pair<int,int> pii;
 
const int N = 205;
const int mod = 1e9 + 9;

int n, C[N];

int Cata(int n){
    if (C[n]) return C[n];
    int ans = 0;
    for (int i=0; i<n; i++){
        ans = (ans + (Cata(i) * Cata(n-i-1)) % mod) % mod;
    }
    return C[n] = ans;
}

signed main(){
    SalAC;
    
    cin >> n;
    C[0] = 1;
    cout << Cata(n);
}
