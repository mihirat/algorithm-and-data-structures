#include <iostream>
#include <vector>
using namespace std;


int fibo(int N) {
    cout << "fibo (" << N << ") is called" << endl;

    if (N==0) return 0;
    if (N==1) return 1;
    
    int result = fibo(N-1) + fibo(N-2);
    cout << "fibo(" << N << ") = "<< result << endl;
    return result;    
}

int main() {
    fibo(7);        
}
