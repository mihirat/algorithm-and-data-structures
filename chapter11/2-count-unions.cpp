#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int> >;

struct UnionFind {
    vector<int> parent, siz;

    // init
    UnionFind(int n): parent(n, -1), siz(n, 1) {}
    
    int root(int x) {
        // if x is the root, return x
        if (parent[x] == -1) return x;
        else return parent[x] = root(parent[x]);
    }
    // if 2 values in the same root, both belong to the same group
    bool isSame(int x, int y) {
        return root(x) == root(y);
    }
    // unite the group having x and the group having y
    bool unite(int x, int y){
        x = root(x);
        y = root(y);
        // if they are in 1 same group, do nothing
        if (x == y) return false;
        // union by size: regarding y as smaller 
        if (siz[x] < siz[y]) swap(x, y);
        // set y as x's child
        parent[y] = x;
        siz[x] += siz[y];
        return true;
    }

    int size(int x) {
        return siz[root(x)];
    }
};

int main() {
    // vertex, edge
    int N, M;
    cin >> N >> M;
    
    UnionFind uf(N);

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        uf.unite(a, b);
    }

    // totalling
    int res = 0;
    for(int x = 0; x < N; ++x) {
        if (uf.root(x) == x) ++res;
    }
    cout << res << endl;
}
