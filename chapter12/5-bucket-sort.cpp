#include <iostream>
#include <vector>
using namespace std;


const int MAX = 15;

void printV(vector<int> a){
    cout << "###########" << endl;
    for (int x: a) cout << x << ' ';
    cout << endl;
}

// sort array a
void bucketSort(vector<int> &a) {
    int N = (int)a.size();

    // count how many times each element appears
    vector<int> num(MAX, 0);
    for (int i = 0; i < N; ++i) {
        ++num[a[i]];
    }

    // cumulative sum
    vector<int> sum(MAX, 0);
    for (int v = 1; v < MAX; ++v) {
        sum[v] = sum[v-1] + num[v];
    }

    // a2: sorted a
    vector<int> a2(N);
    for (int i = N - 1; i > 0; --i) {
        a2[--sum[a[i]]] = a[i];
    }
    a = a2;
}

int main() {
    // number of elements
    vector<int> a = {4,8,2,3,8,6,7,9};

    bucketSort(a);
}
