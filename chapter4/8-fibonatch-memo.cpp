#include <iostream>
#include <vector>
using namespace std;

vector<long long> memo;
int target_fibo = 50;

int fibo(int N) {
    if (N==0) return 0;
    if (N==1) return 1;

    if (memo[N] != -1) return memo[N];
    return memo[N] =  fibo(N-1) + fibo(N-2);
}

int main() {
    memo.assign(target_fibo ,-1);
    fibo(target_fibo - 1);
    for (int i=2; i < target_fibo; ++i) {
        cout << "fibo(" << i << ") = "<< memo[i] << endl;
    }    
}
