#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, W;
    cout << "input total number of integers" << endl;
    cin >> N;
    cout << "input integer to search" << endl;
    cin >> W;
    cout << "input each integer" << endl;
    vector<int> a(N);
    for (int i=0; i< N; ++i) cin >> a[i];

    bool exist = false;
    for (int bit = 0; bit < (1 << N); ++bit) {
        int sum = 0;
        for (int i = 0; i < N; ++i) {
            if (bit & (1 << i)) {
                sum += a[i];
            }
        }

        if (sum == W) exist = true;
    }

    if (exist) cout << "Yes" << endl;
    else cout << "No" << endl;
}
