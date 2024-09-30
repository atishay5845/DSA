#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class Queue {
private:
    float arr[MAX_SIZE];
    int frontIdx;
    int rearIdx;
    int size;

public:
    Queue() {
        frontIdx = -1;
        rearIdx = -1;
        size = 0;
    }

    bool isEmpty() {
        return (size == 0);
    }

    bool isFull() {
        return (size == MAX_SIZE);
    }

    void enqueue(float element) {
        if(isFull()){
            return;
        }
        if(isEmpty()){
            frontIdx = 0;
            rearIdx = 0;
        }else{
            rearIdx = (rearIdx+1)%MAX_SIZE;
        }
        arr[rearIdx]=element;
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            return;
        }

        if (frontIdx == rearIdx) {
            frontIdx = -1;
            rearIdx = -1;
        } else {
            frontIdx = (frontIdx + 1) % MAX_SIZE;
        }

        size--;
    }

    float front() {
        if (isEmpty()) {
            return -1.0;
        }

        return arr[frontIdx];
    }

};

int main() {
    Queue q;
    int n;

    cin >> n;

    if (n == 0) {
        cout << "Queue is empty" << endl;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        float element;
        cin >> element;
        q.enqueue(element);
    }


    while (!q.isEmpty()) {
        cout << q.front() << " ";
        q.dequeue();
    }

    return 0;
}