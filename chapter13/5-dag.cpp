#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using Graph = vector<vector<int> >;


vector<bool> seen;

// order of topological sort
vector<int> order; 
void dfs(const Graph &G, int v) {
    seen[v] = true;
    
    // reachable next_v from v
    for (auto next_v: G[v]) {
        if (seen[next_v]) continue;
        dfs(G, next_v);
    }
    order.push_back(v);
}

void printV(vector<int> a){
    cout << "###########" << endl;
    for (int x: a) cout << x << ' ';
    cout << endl;
}



int main() {
    // vertex and edge
    int N, M;
    cin >> N >> M;
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }

    seen.assign(N, -1);
    order.clear();
    for (int v = 0; v < N; ++v) {
        if(seen[v]) continue;
        dfs(G,v);
    }
    reverse(order.begin(), order.end());
    printV(order);
}
