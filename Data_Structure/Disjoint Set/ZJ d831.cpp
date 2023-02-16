#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;

const int N = 1e6 + 5;

int n, m, ans;
int table[N], sz[N];

void init(){
    ans = 1;
    for (int i=0; i<n; i++){
       table[i] = i;
       sz[i] = 1;
    }
}

int find(int i){
    if (i == table[i]) return i;
    return table[i] = find(table[i]);
}

void unite(int a, int b){
    int i = find(a);
    int j = find(b);
    if (i == j) return;
    if (sz[i] >= sz[j]){
        table[j] = i;
        sz[i] += sz[j];
        ans = max(ans, sz[i]);
    }
    else{
        table[i] = j;
        sz[j] += sz[i];
        ans = max(ans, sz[j]);
    }
}

signed main(){
    SalAC;
    
    while (cin >> n >> m){
        init();
        for (int i=0, a, b; i<m; i++){
            cin >> a >> b;
            unite(a, b);
        }
        cout << ans << "\n";
    }
}
