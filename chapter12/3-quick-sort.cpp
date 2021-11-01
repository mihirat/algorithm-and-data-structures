#include <iostream>
#include <vector>
using namespace std;

// sort the section [left, right) of array a
// [left, right): left, left+1, ... right -1
void quickSort(vector<int> &a, int left, int right) {
    // finish condition
    if (right - left <= 1) return;
    
    // if randomized, the performance gets better considering biased dataset
    int pivot_index = left + (right - left) / 2;
    int pivot = a[pivot_index];
    swap(a[pivot_index], a[right - 1]);

    // i: index of right end for pivoted elements smaller than pivot
    int i = left;
    for (int j = left; j < right - 1; ++j){
        // if smaller than pivot, move to left side
        if (a[j] < pivot) {
            swap(a[i++], a[j]);
        }
    }
    // set pivot to the proper place
    swap(a[i], a[right - 1]); 

    // recursively sort
    quickSort(a, left, i); // left half, smaller than pivot
    quickSort(a, i+1, right); // right half 

}

int main() {
    // number of elements
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    // probably same as std::stable_sort()
    quickSort(a, 0, N);
}
