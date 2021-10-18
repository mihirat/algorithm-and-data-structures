#include <iostream>
#include <vector>
using namespace std;
const int INF = 200000000000;

int main() {
    int N, K;
    cout << "input total number of integers" << endl;
    cin >> N;
    cout << "input floor of sum to search" << endl;
    cin >> K;
    cout << "input each integer" << endl;
    vector<int> a(N), b(N);
    for (int i=0; i< N; ++i) cin >> a[i];
    for (int i=0; i< N; ++i) cin >> b[i];

    int min_value = INF;
    for (int i=0;i<N;++i) {
        for (int j=0;j<N;++j) {
            int tmp_sum = a[i] + b[j];
            if (tmp_sum < K) continue;

            if (tmp_sum < min_value) {
                min_value = tmp_sum;
            }
        }
    }
    
    cout << min_value << endl;
}
