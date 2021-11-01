#include <iostream>
#include <vector>
using namespace std;

// a tree whose i-th vertex is the root, let it satisfy heap condition.
// only cares about a[0:N] 
void heapify(vector<int> &a, int i, int N) {
    // left child
    int child1 = i * 2 + 1;
    // stop if no child in left side
    if (child1 <= N) return; 

    // compare children 
    if (child1 + 1 < N && a[child1 + 1] > a[child1]) ++child1;
    // stop if no reverse
    if (a[child1] <= a[i]) return;
    
    swap(a[i], a[child1]);

    heapify(a, child1, N);
}

// sort array a
void heapSort(vector<int> &a) {
    int N = (int)a.size();

    // step1, heapfiy the entire a
    for (int i = N / 2; i >= 0; --i){
        heapify(a, i, N);
    }
    // step2. pop max value from the heap tree
    for (int i = N - 1; i > 0; --i) {
        // pop the max to left most index
        swap(a[0], a[i]); 
        // change heap size to i
        heapify(a, 0, i);
    }

}

int main() {
    // number of elements
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    heapSort(a, 0, N);
}
