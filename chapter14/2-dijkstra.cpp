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

    vector<bool> used(N, false);
    vector<long long> dist(N, INF);
    dist[s] = 0;
    for (int iter = 0; iter < N; ++iter) {
        // find minimum dist from non-used vertex.
        // i.e. choosing shortest path from the start.
        long long min_dist = INF;
        int min_v = -1;
        for(int v=0; v < N; ++v){
            if (!used[v] && dist[v] < min_dist) {
                min_dist = dist[v];
                min_v = v;
            }
        }
        // if all used, search completed.
        if (min_v == -1) break;

        // relax each edge connected to min_v
        for (auto e: G[min_v]) {
            chmin(dist[e.to], dist[min_v] + e.w);
        }
        // marked min_v as used
        used[min_v] = true; 
    }

    for (int v= 0; v < N; ++v){
        if(dist[v] < INF) cout << dist[v] << endl;
        else cout << "INF" << endl;
    }
}
