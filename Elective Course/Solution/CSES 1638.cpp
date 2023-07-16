#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;
 
int n, mod = (int)1e9 + 7;
int maze[1005][1005];
string s;
 
void init(){
	for (int i=1; i<=n; i++){
		cin >> s;
		for (int j=1; j<=n; j++){
			if (s[j-1] == '.' && i == 1 && j == 1) maze[i][j] = 1;
			else if (s[j-1] == '*') maze[i][j] = 0;
			else if (s[j-1] == '.') maze[i][j] = (maze[i-1][j] + maze[i][j-1]) % mod;
		}
	}
}
 
int main(){
	SalAC;
	
	cin >> n;
	init();
	cout << maze[n][n];
}