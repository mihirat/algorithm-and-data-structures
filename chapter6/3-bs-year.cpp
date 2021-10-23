#include <iostream>
#include <vector>

using namespace std;


int binary_search(int left, int right) {
    while (right - left > 1){
        int mid = left + (right - left) / 2;
        cout << "is the age less than " << mid << " ? (y/n)" << endl;
        string ans;
        cin >> ans;
        if (ans == "yes") right = mid;
        else left = mid;
    }
    return left;
}

int main() {
    int left = 20;
    int right = 38;
    cout << "the age is " << binary_search(left, right) << endl; 
}
