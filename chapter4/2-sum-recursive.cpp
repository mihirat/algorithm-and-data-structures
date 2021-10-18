#include <iostream>
#include <vector>
using namespace std;

int func(int N) {
    cout << "func (" << N << ") is called" << endl;

    if (N == 0) return 0;

    int result = N + func(N-1);
    cout << "sum by " << N << ": "<< result << endl;

    return result;
}

int main() {
    func(5);
}
