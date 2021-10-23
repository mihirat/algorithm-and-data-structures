#include <iostream>
#include <vector>

using namespace std;

int INF = 1 << 29;

template<class T> void chmin(T& a, T b){
    if (a > b) {
        a = b;
    }
}

long long sectionize(int N, vector<vector<long long> > c) {
    vector<long long> dp(N + 1, INF);
    dp[0] = 0;

    for(int i=0;i<=N; ++i) {
        for(int j=0;j<i; ++j) {
            chmin(dp[i], dp[j] + c[j][i]);
        }    
    }
    return dp[N];
}

int main() {
    int N = 10;
    vector<vector<long long> > c(N+1, vector<long long>(N+1));
    for(int i=0;i<=N+1; ++i) {
        for(int j=0;j<=N+1; ++j) {
            cin >> c[i][j];
        }    
    }
    cout << sectionize(N, c) << endl;
}
