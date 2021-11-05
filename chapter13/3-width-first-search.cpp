#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using Graph = vector<vector<int> >;

// input: graph, starting point s
// output: array of shortest distance from s to each vertex
vector<int> bfs(const Graph &G, int s) {
    int N = (int)G.size();
    vector<int> distance(N, -1);
    queue<int> queue;

    // init: regard 0 as initial vertex 
    distance[0] = 0;
    queue.push(0);

    while(!queue.empty()) {
        int v = queue.front();
        queue.pop();

        for (int x : G[v]){
            // if already searched, skip
            if (distance[x] != -1) continue;
            
            distance[x] = distance[v] + 1;
            queue.push(x);
        }
    }
    return distance;
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

    vector<int> distance = bfs(G, 0);

    printV(distance);
}
