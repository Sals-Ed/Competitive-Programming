#include <bits/stdc++.h>
using namespace std;

vector <int> G[7];
bitset <7> visited;

void addEdge(int u, int v){
    G[u].push_back(v);
    G[v].push_back(u);
}

void dfs(int u){
    cout << u << " ";
    visited[u] = true;
    for (int nxt: G[u]){
        if (!visited[nxt]){
            dfs(nxt);
        }
    }
}

int main(){
    
    addEdge(0, 2);
    addEdge(0, 4);
    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 3);
    addEdge(2, 6);
    addEdge(4, 5);
    
    dfs(0);
}