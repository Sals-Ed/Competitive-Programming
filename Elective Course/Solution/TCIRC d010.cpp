#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;

int n;

vector <int> v;

signed main(){
    SalAC;

    cin >> n;
    for (int i=1, tmp; i<=n; i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    
    sort(v.begin(), v.end());
    
    v.resize(distance(v.begin(), unique(v.begin(), v.end())));
    
    cout << (int)v.size() << "\n";

    for (int val: v){
        cout << val << " ";
    }
}