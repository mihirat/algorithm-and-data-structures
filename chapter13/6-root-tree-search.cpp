#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int> >;


vector<int> depth;
vector<int> subtree_size;

void dfs(const Graph &G, int v, int p = -1, int d = 0) {
    depth[v] = d;
    for (auto c: G[v]) {
        // only search children's direction, not parent
        if (c == p) continue;
        dfs(G, c, v, d + 1); // when to search next child vertex, increment d
    }

    // when to finish search from th vertex v,
    // find subtree size: how many vertex in each partial tree.
    subtree_size[v] = 1; // itself 
    for (auto c: G[v]) {
        if (c == p) continue;
        subtree_size[v] += subtree_size[c];
    }
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
        G[b].push_back(a);
    }

    int root = 0;
    depth.assign(N, 0);
    subtree_size.assign(N, 0);
    dfs(G, root);
    
    for (int v =0; v < N; ++v){
        cout << v << ": depth = " << depth[v];
    }
    printV(depth);
    printV(subtree_size);
}