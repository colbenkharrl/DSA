#include "stack.h"
#include <iostream>

using namespace std;

Stack::Stack(int s) {
  A = new int[size];
  size = s;
  top = 0;
}
Stack::Stack(int *I, int t, int s) {
  A = I;
  size = s;
  top = t;
}
Stack::~Stack() {
  if (!passed) {
    delete[] A;
  }
}
int Stack::StackEmpty() {
  if (top == 0) {
    return 1;
  } else {
    return 0;
  }
}
void Stack::Push(int x) {
  if (top == size) {
    cout << "Error: Stack full; unable to push." << endl;
  } else {
    top++;
    A[top - 1] = x;
  }
}
int Stack::Pop() {
  if (StackEmpty()) {
    cout << "Error: Stack empty; unable to pop." << endl;
    return -1;
  } else {
    top--;
    return A[top];
  }
}
void Stack::Print() {
  for (int i = 0; i < top; i++) {
    cout << A[i] << " ";
  }
  cout << endl;
}