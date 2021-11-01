#include <iostream>
#include <vector>
using namespace std;

struct Heap {
    vector<int> heap;
    Heap() {}

    void push(int x) {
        // anyway, insert to the tail
        heap.push_back(x);
        // inserted vertex's index
        int i = (int)heap.size() - 1;
        while (i  > 0) {
            // its parent index
            int p = (i-1) / 2;
            // if not reversed, stop
            if(heap[p] >= x) break;
            // otherwise, climb up 
            heap[i] = heap[p];
            i = p;
        }
        // finally x is placed at index i
        heap[i] = x;
    }

    // know the biggest
    int top() {
        if(!heap.empty()) return heap[0];
        else return -1;
    }

    // remove the biggest 
    void pop() {
        if (heap.empty())return;
        int x = heap.back();
        heap.pop_back();
        // starts from the root
        int i = 0;
        while(i * 2 + 1 < (int)heap.size()) {
            int child1 = i * 2 + 1;
            int child2 = i * 2 + 2;
            // compare children index and pick bigger as child1
            if (child2 < (int)heap.size() && heap[child2] > heap[child1]) {
                child1 = child2;
            }
            // if not reversed, stop
            if(heap[child1] <= x) break;
            // replace itself with child1 value
            heap[i] = heap[child1];
            // decendent
            i = child1;
        }
        heap[i] = x;
    }
};

int main() {
    Heap h;
    h.push(5); h.push(3); h.push(7); h.push(1);

    cout << h.top() << endl;
    h.pop();
    cout << h.top() << endl;
    h.push(11);
    cout << h.top() << endl;
 }