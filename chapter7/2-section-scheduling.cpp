#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

using Interval = pair<int, int>;

// compare intervals with terminal time 
bool cmp(const Interval &a, const Interval &b) {
    return a.second > b.second;
}

int greedy(int N, vector<Interval> inter) {
    sort(inter.begin(), inter.end(), cmp);
    
    int res = 0;
    int current_end_time = 0;
    for (int i = 0; i < N; ++i) {
        if (inter[i].first < current_end_time) continue;
        ++res;
        current_end_time = inter[i].second;
    }
    return res;
}

int main() {
    // total number of tasks
    int N = 10;
    vector<Interval> inter(N);
    for (int i=0; i < N; ++i) {
        cin >> inter[i].first >> inter[i].second;
    }
    cout << greedy(N, inter) << endl;
}
