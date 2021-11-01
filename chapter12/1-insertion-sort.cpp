#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &a) {
    int N = (int)a.size();
    for (int i = 1; i < N; ++i) {
        // pick insertion target
        int v = a[i];
        // find proper index j
        int j = i;
        for(; j > 0; --j){
            // any value bigger than v, push it back 
            if (a[j-1] > v) {
                a[j] = a[j-1];
            }
            // if not, stop finding.
            else break;
        }
        a[j] = v;
    }
}

int main() {
    // number of elements
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    insertionSort(a);
}
