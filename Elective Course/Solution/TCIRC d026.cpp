#include<bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
#define t stk.top
using namespace std;

bool ismatch(string s){
	bool judge;
	stack <char> stk;
	
	for (char c: s){
		if (c == '{' || c == '[' || c == '(') stk.push(c);
		else{
			if (stk.empty()){
				return false;
			}
			if (c == '}' && t() == '{') stk.pop();
			else if (c == ']' && t() == '[') stk.pop();
			else if (c == ')' && t() == '(') stk.pop();
			else return false;
		}
	}
	if (!stk.empty()) return false;
	return true;
}

int main(){
	SalAC;
	
	string s;
	while (cin >> s){
		if (ismatch(s)) cout << "yes\n";
		else cout << "no\n";
	}
}
