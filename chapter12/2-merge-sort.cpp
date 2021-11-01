#include <iostream>
#include <vector>
using namespace std;

// sort the section [left, right) of array a
// [left, right): left, left+1, ... right -1
void mergeSort(vector<int> &a, int left, int right) {
    // finish condition
    if (right - left == 1) return;
    
    int mid = left + (right - left) / 2;
    // sort left half
    mergeSort(a, left, mid);
    // sort right half
    mergeSort(a, mid, right);

    // copy each result
    vector<int> buf;
    for (int i = left; i < mid; ++i) buf.push_back(a[i]);
    for (int i = mid; i < right; ++i) buf.push_back(a[i]);

    // merge
    int index_left = 0;
    int index_right = (int)buf.size() - 1;
    for (int i = left; i < right; ++i) {
        // pick left side
        if (buf[index_left] <= buf[index_right]) {
            a[i] = buf[index_left++];
        }
        // or right
        else {
            a[i] = buf[index_right--];
        }
    }
}

int main() {
    // number of elements
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    // probably same as std::stable_sort()
    mergeSort(a, 0, N);
}
