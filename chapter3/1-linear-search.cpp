#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, v;
    cout << "input total number of integers" << endl;
    cin >> N;
    cout << "input integer to search" << endl;
    cin >> v;
    cout << "input each integer" << endl;
    vector<int> a(N);
    for (int i=0; i< N; ++i) cin >> a[i];

    bool exist = false;
    for (int i=0;i<N;++i) {
        if (a[i] == v) {
            exist = true;
        }
    }
    
    if (exist) cout << "yes" << endl;
    else cout << "No" << endl;
}
