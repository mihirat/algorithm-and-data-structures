#include <iostream>
#include <vector>

using namespace std;

// max size of ring buffer queue
const int MAX = 100000;

// the queue
int qu[MAX];
// the elements of queue 
int tail = 0;
int head = 0;

void init() {
    tail = 0;
    head = 0;
}

bool isEmpty() {
    return (head == tail);
}

bool isFull() {
    return (head == (tail + 1) % MAX);
}

void enqueue(int x){
    if (isFull()) {
        cout << "error: queue is full" << endl;
        return;
    }
    qu[tail] = x;
    ++tail;
    // if tail reached the nd of buffer, move to 0.
    if (tail == MAX) tail = 0;
}

int dequeue() {
    if (isEmpty()){
        cout << "error: queue is empty" << endl;
        return -1;
    }
    int res = qu[head];
    ++head;
    if (head == MAX) head = 0;
    return res;
}

int main() {
    init();

    enqueue(3);
    enqueue(5);
    enqueue(7);

    cout << dequeue() << endl;
    cout << dequeue() << endl;
    
    enqueue(9);
}
