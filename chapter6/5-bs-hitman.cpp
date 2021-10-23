#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 2000000;

int binary_search(int N, vector<int> h, vector<int> s) {
    long long left = 0, right = INF;
    while (right - left > 1){
        long long mid = (left + right) / 2;

        bool ok = true;
        // time limit for each baloon
        vector<long long> t(N, 0);
        for (int i = 0; i < N; ++i) {
            // at least mid should be higher than initial height
            if (mid < h[i]) ok = false;
            else t[i] = (mid - h[i]) / a[i];
        }
        sort(t.begin(), t.end());
        for (int i = 0; i < N; ++i) {
            // time up
            if (t[i] < i) ok = false;
        }

        if (ok) right = mid;
        else left = mid;
    }
    return right;
}

int main() {
    int N = 15;
    vector<int> h(N), s(N);
    for (int i = 0; i < N; ++i) cin >> s[i];
    
    cout << binary_search(N, h, s) << endl; 
}
