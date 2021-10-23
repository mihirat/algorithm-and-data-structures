#include <iostream>
#include <vector>

using namespace std;

const vector<int> value = {500, 100, 50, 10, 5, 1};

int greedy(int X, vector<int> a) {
    int result = 0;
    for (int i = 0;i < value.size(); ++i) {
        // without count limit
        int add = X / value[i]; 
        // consider count limit
        if (add > a[i]) add = a[i];
        // calc the rest and add to result       
        X -= value[i] * add;
        result += add;
    }
}

int main() {
    int X = 180;
    vector<int> a(value.size());
    for (int i = 0; i < value.size(); ++i) cin >> a[i];
    
    cout << greedy(X, a) << endl; 
}
