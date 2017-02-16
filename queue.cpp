#include "queue.h"
#include <iostream>

using namespace std;

Queue::Queue(int s) {
  A = new int[s];
  passed = 0;
  size = s;
  head = 0;
  tail = 0;
  empty = 1;
}
Queue::Queue(int *I, int t, int h, int s) {
  A = I;
  passed = 1;
  size = s;
  tail = t;
  head = h;
  if (t == 0) {
    empty = 1;
  } else {
    empty = 0;
  }
}
Queue::~Queue() {
  if (!passed) {
    delete[] A;
  }
}
void Queue::Enqueue(int x) {
  if (tail == head && !empty) {
    cout << "Error: Queue full; unable to enqueue." << endl;
  } else {
    A[tail] = x;
    if (tail == size - 1) {
      tail = 0;
    } else {
      tail++;
    }
    empty = 0;
  }
}
int Queue::Dequeue() {
  if (head == tail && empty) {
    cout << "Error: Queue empty; unable to dequeue." << endl;
    return -1;
  } else {
    int x = A[head];
    if (head == size - 1) {
      head = 0;
    } else {
      head++;
    }
    if (head == tail) {
      empty = 1;
    }
    return x;
  }
}
void Queue::Print() {
  int loop;
  if (empty) {
    loop = 0;
  } else {
    loop = 1;
  }
  for (int i = head; (i != tail || loop); i++) {
    if (loop) {
      loop = 0;
    }
    cout << A[i] << " ";
    if (i == size - 1) {
      i = -1;
    }
  }
  cout << endl;
}