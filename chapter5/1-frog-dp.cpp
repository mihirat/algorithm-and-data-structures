#include <iostream>
#include <vector>

using namespace std;

int INF = 1 << 29;

int dp(int N, vector<int> h) {
    vector<long long> cost(N, INF);
    cost[0] = 0;
    
    for (int i=1; i<N; ++i) {
        if (i == 1) cost[i] = abs(h[i] - h[i-1]);
        else cost[i] = min(cost[i-1] + abs(h[i] - h[i-1]), cost[i-2] + abs(h[i] - h[i-2]));
    }
    return cost[N-1];
}

int main() {
    int N = 7;
    vector<int> h{2,9,4,5,1,6,10};
    cout << dp(N, h) << endl;
}
