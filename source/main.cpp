#include "heap.h"
#include "queue.h"
#include "sort.h"
#include "stack.h"
#include <iostream>

//	used for testing and debugging
using namespace std;

int main() {
  int *A = new int[7];
  int j = 7;
  for (int i = 0; i < 7; i++) // fill array with non-sorted numbers
  {
    A[i] = j;
    j--;
  }
  PrintList(A, 0, 6);
  BubbleSort(A, 7);
  PrintList(A, 0, 6);
}