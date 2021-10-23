#include <iostream>
#include <vector>

using namespace std;

int binary_search(int key, vector<int> a) {
    int left = 0;
    int right = (int)a.size() - 1;
    while (right >= left) {
        int mid = left + (right - left) / 2;
        if (a[mid] == key) return mid;
        else if (a[mid] > key) right = mid - 1;
        else if (a[mid] < key) left = mid + 1;
    }
    return -1;
}

int main() {
    // 
    int N = 8; 
    vector<int> a = {3,5,8,10,14,17,21,39};
    
    int target = 10;
    cout << binary_search(target, a) << endl;
}
