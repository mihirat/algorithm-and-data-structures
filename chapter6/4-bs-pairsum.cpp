#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 2000000;

int binary_search(int N, int K, vector<int> a, vector<int> b) {
    int min_value = INF;
    sort(b.begin(), b.end());
    for (int i = 0; i < N; ++i) {
        auto iter = lower_bound(b.begin(), b.end(), K-a[i]);

        int val = *iter;

        if (a[i] + val < min_value) {
            min_value = a[i] + val;
        }
    }
    return min_value;
}

int main() {
    int N = 15;
    int K = 4;
    vector<int> a(N), b(N);
    for (int i = 0; i < N; ++i) cin >> a[i];
    for (int i = 0; i < N; ++i) cin >> b[i];
    
    cout binary_search(N, K, a, b) << endl; 
}
