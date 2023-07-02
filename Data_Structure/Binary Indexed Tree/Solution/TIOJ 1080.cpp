#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;
typedef long long ll;

const int N = 1e5 + 5;

ll n, arr[N], BIT[N], ans, c;
priority_queue <ll> pq;
map<ll, ll> mp;

void init(){
    mp.clear();
    for (int i=1; i<=n; i++){
        BIT[i] = 0;
        cin >> arr[i];
        pq.push(arr[i]);
    }
    for (int i=1; !pq.empty(); i++, pq.pop()){
    	mp.insert({pq.top(), i});
    }
}

void modify(int i){
    while (i <= n){
        BIT[i]++;
        i += (i & -i);
    }
}

ll query(int i){
    ll ans = 0;
    while (i > 0){
        ans += BIT[i];
        i -= (i & -i);
    }
    return ans;
}

signed main(){
    SalAC;

    while (cin >> n){
        if (n == 0) break;
        init(); ans = 0;
        for (int i=1; i<=n; i++){
            ans += query(mp[arr[i]]-1);
            modify(mp[arr[i]]);
        }
        printf("Case #%d: %lld\n", ++c, ans);
    }
}