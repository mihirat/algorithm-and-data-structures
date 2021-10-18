#include <iostream>
#include <vector>
using namespace std;


int fibo(int N) {
    vector<long long> F(N);
    F[0] = 0;
    F[1] = 1;
    for (int n = 2; n < 50; ++n) {
        F[n] = F[n-1] + F[n-2];
        cout << "fibo(" << n << ") = "<< F[n] << endl;
    }
}

int main() {
    fibo(7);        
}
