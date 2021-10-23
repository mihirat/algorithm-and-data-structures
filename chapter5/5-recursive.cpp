#include <iostream>
#include <vector>

using namespace std;

int INF = 1 << 29;

template<class T> void chmin(T& a, T b){
    if (a > b) {
        a = b;
    }
}

long long recursive(int N, vector<int> h) {
    if (N == 0) return 0;
    long long res = INF;
    chmin(res, recursive(N - 1, h) + abs(h[N] - h[N-1]));

    if (N > 1) chmin(res, recursive(N - 2, h) + abs(h[N] - h[N-2])); 

    return res;
}

int main() {
    int N = 7;
    vector<int> h{2,9,4,5,1,6,10};
    cout << recursive(N, h) << endl;
}
