#include <iostream>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;

struct disjoint_set{
	
	static const int N = 1e6 + 5;
	
	int table[N];
	
	void init(int n){
		for (int i=1; i<=n; i++){
			table[i] = i;
		}
	}
	
	int find(int i){
		if (i == table[i]) return i;
		return find(table[i]);
	}
	
	void unite(int i, int j){
		table[find(j)] = find(i);
	}
	
	bool same(int i, int j){
		return (find(i) == find(j));
	}
	
	void show(int n){
		for (int i=1; i<=n; i++){
			cout << i << " 的代表元素為 " << find(i) << "\n";
		}
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
}
