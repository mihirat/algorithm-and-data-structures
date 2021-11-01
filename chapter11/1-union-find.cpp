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
    // {0}, {1}, {2}, {3}, {4}, {5}, {6}
    UnionFind uf(7); 
    // {0}, {1, 2}, {3}, {4}, {5}, {6}
    uf.unite(1, 2);
    // {0}, {1, 2, 3}, {4}, {5}, {6}
    uf.unite(2, 3);
    // {0}, {1, 2, 3}, {4}, {5,6}
    uf.unite(5, 6);
    cout << uf.isSame(1, 3) << endl;
    cout << uf.isSame(2, 5) << endl;    
    // {0}, {1, 2, 3, 5, 6}, {4}
    uf.unite(1,6); 
    cout << uf.isSame(2, 5) << endl;
}