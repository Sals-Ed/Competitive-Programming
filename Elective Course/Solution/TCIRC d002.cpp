#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;

int func(){
	string s;
	cin >> s;
	if (s == "f"){
		return 2 * func() - 3;
	}
	if (s == "g"){
		return 2 * func() + func() - 7;
	}
	if (s == "h"){
		return 3 * func() - 2 * func() + func();
	}
	return stoi(s);
}

signed main(){
	SalAC;
	
	cout << func();
}