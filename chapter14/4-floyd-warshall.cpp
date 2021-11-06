#include <iostream>
#include <vector>

using namespace std;

const long long INF = 10000000;

int main() {
    // number of vertex, edge
    int N, M;
    cin >> N >> M;
    
    vector<vector<long long> > dp(N, vector<long long>(N, INF));

    for(int e=0; e<M; ++e){
        int a, b;
        long long w;
        cin >> a >> b >> w;
        dp[a][b] = w;
    }
    for (int v = 0;v < N; ++v) dp[v][v] = 0;

    for(int k=0; k<N;++k) {
        for (int i=0; i<N; ++i) {
            for (int j=0; j<N; ++j) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }            
        }
    }
    // if dp[v][v] < 0, there must be a negative cycle
    bool exist_negative_cycle = false;
    for (int v = 0; v < N; ++v){
        if (dp[v][v] < 0) exist_negative_cycle = true;
    }
    if(exist_negative_cycle) {
        cout << "NEGATIVE CYCLE" << endl;
    }
    else {
        for (int i= 0; i < N; ++i){
            for (int j= 0; j < N; ++j){
                if (j) cout << " ";
                if(dp[i][j] < INF / 2) cout << dp[i][j];
                else cout << "INF";
            }
            cout << endl;
        }
    }
}
