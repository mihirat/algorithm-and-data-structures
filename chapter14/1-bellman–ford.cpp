#include <iostream>
#include <vector>
using namespace std;

const long long INF = 10000000;

struct Edge {
    int to;
    long long w;
    Edge(int to, long long w) : to(to), w(w) {}
};

using Graph = vector<vector<Edge> >;

template<class T> bool chmin(T& a, T b){
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    // number of vertex, edge, starting point
    int N, M, s;
    cin >> N >> M >> s;
    
    Graph G(N);
    for(int i=0; i<M; ++i){
        int a, b, w;
        cin >> a >> b >> w;
        G[a].push_back(Edge(b,w));
    }

    bool exist_negative_cycle = false;
    vector<long long> dist(N, INF);
    dist[s] = 0;
    for (int iter = 0; iter < N; ++iter) {
        bool update = false;
        for(int v=0; v < N; ++v){
            if (dist[v] == INF) continue;
            for (auto e: G[v]) {
                // do relaxation
                if(chmin(dist[e.to], dist[v] + e.w)) {
                    update = true;
                }
            }
        }
        // if all edges are already updated, shortest path is found.
        if (!update) break;
        // if updated at Nth iteration, there must be a negative cycle
        if (iter == N - 1 && update) exist_negative_cycle = true;
    }

    if(exist_negative_cycle) cout << "NEGATIVE CYCLE" << endl;
    else {
        for (int v= 0; v < N; ++v){
            if(dist[v] < INF) cout <<dist[v] << endl;
            else cout << "INF" << endl;
        }
    }
}
