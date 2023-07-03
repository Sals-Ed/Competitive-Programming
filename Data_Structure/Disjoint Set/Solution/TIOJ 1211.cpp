#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
#define f first
#define s second
using namespace std;
typedef pair<int, int> pii;

bool space = false;
vector <pair<int, pii>> G;

struct DSU{
	
	static const int MAXN =  1e7;
	
	int p[MAXN];
	
	void init(int n){
		for (int i = 0; i < n; i++) p[i] = i;
	}
	
	int find(int x){
		if (p[x] == x) return p[x];
		return p[x] = find(p[x]);
	}
	
	void unite(int x, int y){
		p[find(y)] = find(x);
	}
	
	bool same(int x, int y){
		return (find(p[x]) == find(p[y]));
	}
};

void clear(){
	while (!G.empty()) G.pop_back();
}

int main(){
	SalAC;
	
	int n, m;
	
	DSU check;
	
	while (cin >> n >> m){
		
		int weight = 0;
		bool flag = true;
		
		if (n == 0 && m == 0) break;
		if (space) cout << "\n";
		
		check.init(n);
		
		clear();
		for (int i=0, a, b, w; i<m; i++){
			cin >> a >> b >> w;
			a--, b--;
			G.push_back(make_pair(w, make_pair(a, b)));
		}
		
		sort(G.begin(), G.end());
		
		for (auto i: G){
			if (!check.same(i.s.f, i.s.s)){
				check.unite(i.s.f, i.s.s);
				weight += i.f;
			}
		}
		
		for (int i = 0; i < n; i++){
			if (!check.same(0, i)){
				cout << "-1";
				flag = !flag;
				break;
			}
		}
		
		if (flag) cout << weight;
		
		space = true;
	}
}