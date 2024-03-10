#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

struct Element {
    int value;
    int priority;
};

struct PriorityQueue {
    Element heap[MAX_SIZE];
    int size;
};

void heapifyUp(PriorityQueue& pq, int idx) {
    int parentIdx = (idx - 1) / 2;

    if (idx && pq.heap[parentIdx].priority < pq.heap[idx].priority) {
        swap(pq.heap[parentIdx], pq.heap[idx]);
        heapifyUp(pq, parentIdx);
    }
}

void heapifyDown(PriorityQueue& pq, int idx) {
    int leftChildIdx = 2 * idx + 1;
    int rightChildIdx = 2 * idx + 2;

    int largestIdx = idx;

    if (leftChildIdx < pq.size && pq.heap[leftChildIdx].priority > pq.heap[largestIdx].priority)
        largestIdx = leftChildIdx;

    if (rightChildIdx < pq.size && pq.heap[rightChildIdx].priority > pq.heap[largestIdx].priority)
        largestIdx = rightChildIdx;

    if (largestIdx != idx) {
        swap(pq.heap[idx], pq.heap[largestIdx]);
        heapifyDown(pq, largestIdx);
    }
}

void push(PriorityQueue& pq, int value, int priority) {
    if (pq.size == MAX_SIZE) {
        cout << "Coada de prioritati este plina!\n";
        return;
    }

    pq.heap[pq.size].value = value;
    pq.heap[pq.size].priority = priority;
    heapifyUp(pq, pq.size);
    pq.size++;
}

void pop(PriorityQueue& pq) {
    if (pq.size == 0) {
        cout << "Coada de prioritati este goala!\n";
        return;
    }

    pq.heap[0] = pq.heap[pq.size - 1];
    pq.size--;
    heapifyDown(pq, 0);
}

Element top(PriorityQueue& pq) {
    if (pq.size == 0) {
        cout << "Coada de prioritati este goala!\n";
        return { -1, -1 };
    }

    return pq.heap[0];
}

int main() {

    //teste
    PriorityQueue pq;
    pq.size = 0;
    push(pq, 3, 1);
    push(pq, 2, 2);
    push(pq, 15, 3);

    cout << "Elementul cu cea mai mare prioritate este: " << top(pq).value << " cu prioritatea: " << top(pq).priority << "\n";
    pop(pq);
    cout << "Elementul cu cea mai mare prioritate este: " << top(pq).value << " cu prioritatea: " << top(pq).priority << "\n";

    return 0;
}
