#include "heap.h"
#include "queue.h"
#include "sort.h"
#include "stack.h"
#include <iostream>

//	used for testing and debugging
using namespace std;

int main() {
  int *A = new int[7];
  int j = 50;
  for (int i = 0; i < 7; i++) // fill array with non-sorted numbers
  {
    A[i] = j;
    if (i % 2 == 0) {
      j += i * 2;
    } else {
      j -= i * 3;
    }
  }
  PrintList(A, 0, 6);
  int res = Select(A, 7, 0, 6);
  cout << "Last smallest element: " << res << endl;
}