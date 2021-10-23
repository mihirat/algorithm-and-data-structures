#include <iostream>
#include <vector>

using namespace std;


int greedy(int N, vector<long long> A, vector<long long> B) {
    long long sum = 0;
    
    for (int i = N - 1; i >= 0; --i) {
        A[i] += sum;
        long long amari = A[i] % B[i];
        long long D = 0;
        if (amari != 0) D = B[i] - amari;
        sum += D;
    }
    return sum;
}

int main() {
    // total number of tasks
    int N = 10;
    vector<long long> A(N), B(N);
    for (int i=0; i < N; ++i) {
        cin >> A[i] >> B[i];
    }
    cout << greedy(N, A, B) << endl;
}
