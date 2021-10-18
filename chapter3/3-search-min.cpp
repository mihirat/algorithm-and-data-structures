#include <iostream>
#include <vector>
using namespace std;
const int INF = 200000000000;

int main() {
    int N;
    cout << "input total number of integers" << endl;
    cin >> N;
    cout << "input each integer" << endl;
    vector<int> a(N);
    for (int i=0; i< N; ++i) cin >> a[i];

    int min_value = INF;
    for (int i=0;i<N;++i) {
        if (a[i] < min_value) min_value = a[i];
    }
    
    cout << min_value << endl;
}
