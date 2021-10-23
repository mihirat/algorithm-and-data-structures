#include <iostream>
#include <vector>

using namespace std;

bool P(int x){

}

int binary_search() {
    // P(left) = false, P(right) = true
    int left, right;
    
    while (right - left > 1) {
        int mid = left + (right - left) / 2;
        if (P(mid)) right = mid;
        else left = mid;
    }
    return right;
}

int main() {
}
