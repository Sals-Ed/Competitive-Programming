#include <iostream>
#include <stack>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define fa first
#define cd second
using namespace std;
typedef pair<int,int> pii;

struct disjoint_set{
	
	static const int N = 1e6 + 5;
	
	int table[N], sz[N];
	
	stack <pii> s;
	
	void init(int n){
		for (int i=1; i<=n; i++){
			table[i] = i;
			sz[i] = 1;
		}
	}
	
	int find(int i){
		if (i == table[i]) return i;
		return find(table[i]);
	}
	
	void unite(int i, int j){
		i = find(i);
		j = find(j);
		if (sz[i] >= sz[j]){
			table[j] = i;
			sz[i] += sz[j];
			s.push({i, j});
		}
		else{
			table[i] = j;
			sz[j] += sz[i];
			s.push({j, i});
		}
	}
	
	bool same(int i, int j){
		return (find(i) == find(j));
	}
	
	void show(int n){
		for (int i=1; i<=n; i++){
			cout << i << " 的代表元素為 " << find(i) << "\n";
		}
	}
	
	void undo(){
		pii tmp = s.top(); s.pop();
		table[tmp.cd] = tmp.cd;
		sz[tmp.fa] -= sz[tmp.cd];
	}
}sample;

signed main(){
	fastio;
	
	sample.init(5); // {1, 2, 3, 4, 5}
	sample.show(5);
	cout << "-----我是分隔線-----\n";
	sample.unite(1, 2); // {1, 1, 3, 4, 5}
	sample.unite(2, 3); // {1, 1, 1, 4, 5}
	sample.unite(4, 5); // {1, 1, 1, 4, 4}
	sample.show(5);
	cout << "-----我是分隔線-----\n";
	cout << (sample.same(1, 2) ? "True\n" : "False\n");
	cout << (sample.same(2, 4) ? "True\n" : "False\n");
	cout << (sample.same(4, 5) ? "True\n" : "False\n");
	cout << "-----我是分隔線-----\n";
	sample.undo(); // {1, 1, 1, 4, 5}
	sample.show(5);
}