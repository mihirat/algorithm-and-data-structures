#include <iostream>
#include <vector>
using namespace std;

vector<long long> memo;
int target_fibo = 50;

bool func(int i, int w, const vector<int> &a) {
    if (i==0) {
        if (w == 0) return true;
        return false;
    }
    // in case of not choosing a[i-1]
    if (func(i-1, w, a)) return true;
    // in case of choosing a[i-1]
    if (func(i-1, w - a[i-1], a)) return true;

    // if neither, the answer does not exist.
    return false;    
}

// N: the length of the integer set
// W: target number
int main() {
    int N, W;
    cin >> N >> W;
    vector<int> a(N);
    for (int i=0;i < N;++i) cin >> a[i];
    
    if (func(N,W,a)) cout << "Yes" << endl;
    else cout << "No" << endl;    
}
