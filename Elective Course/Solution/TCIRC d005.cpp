#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
#define int long long
using namespace std;

string s;

int n, ptr;

int recur(int dim){
    if (s[ptr] == '1') return dim*dim;
    if (s[ptr] == '0') return 0;
    int sum = 0;
    for (int i=0; i<4; i++){
        ++ptr;
        sum += recur(dim/2);
    }
    return sum;
}

signed main(){
	SalAC;
	
	cin >> s >> n;
	
	cout << recur(n);
}