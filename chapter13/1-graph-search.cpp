#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using Graph = vector<vector<int> >;


void search(const Graph &G, int s) {
    int N = (int)G.size();
    vector<bool> seen(N, false);
    // queue => width preferred, stack => depth preferred 
    queue<int> todo;

    // init
    seen[s] = true;
    // todo only contains s
    todo.push(s);

    while (!todo.empty()){
        int v = todo.front();
        todo.pop();

        for (int x : G[v]) {
            if (seen[x]) continue;
            seen[x] = true;
            todo.push(x);
        }
    }
}