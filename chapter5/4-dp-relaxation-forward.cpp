#include <iostream>
#include <vector>

using namespace std;

int INF = 1 << 29;

template<class T> void chmin(T& a, T b){
    if (a > b) {
        a = b;
    }
}

int dp(int N, vector<int> h) {
    vector<long long> cost(N, INF);
    cost[0] = 0;
    
    for (int i=0; i<N; ++i) {
        if (i + 1 < N) {
            chmin(cost[i + 1], (cost[i] + abs(h[i+1] - h[i])));
        }
        if (i + 2 < N) {
            chmin(cost[i + 2], (cost[i-2] + abs(h[i+2] - h[i])));
        }
    }
    return cost[N-1];
}

int main() {
    int N = 7;
    vector<int> h{2,9,4,5,1,6,10};
    cout << dp(N, h) << endl;
}
