#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;

struct node{
    int min, max;
};

const int N = 50005;

int n, q, arr[N];

node st[N<<2];

void build(int i, int l, int r){
    if (l == r){
        st[i].min = arr[l];
        st[i].max = arr[r];
        return;
    }
    int mid = (l + r) >> 1;
    build(i<<1, l, mid);
    build(i<<1|1, mid+1, r);
    st[i].min = min(st[i<<1].min, st[i<<1|1].min);
    st[i].max = max(st[i<<1].max, st[i<<1|1].max);
}

node query(int i, int ql, int qr, int l, int r){
    if (ql <= l && r <= qr){
        return st[i];
    }
    node ans = {0x3f3f3f3f, 0};
    int mid = (l + r) >> 1;
    if (ql <= mid){
        node tmp = query(i<<1, ql, qr, l, mid);
        ans.min = min(ans.min, tmp.min);
        ans.max = max(ans.max, tmp.max);
    }
    if (mid < qr){
        node tmp = query(i<<1|1, ql, qr, mid+1, r);
        ans.min = min(ans.min, tmp.min);
        ans.max = max(ans.max, tmp.max);
    }
    return ans;
}

signed main(){
    SalAC;
    
    cin >> n >> q;
    
    for (int i=1; i<=n; i++) cin >> arr[i];
    
    build(1, 1, n);
    
    for (int i=0, a, b; i<q; i++){
        cin >> a >> b;
        node data = query(1, a, b, 1, n);
        cout << data.max - data.min << "\n";
    }
}