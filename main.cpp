#include "heap.h"
#include "queue.h"
#include "sort.h"
#include "stack.h"
#include <iostream>

using namespace std;

int main() {
  int *A = new int[8];
  int j = 7;
  for (int i = 0; i < 8; i++) {
	A[i] = j;
	j--;
  }
  PrintList(A, 0, 7);
  QuickSort(A, 0, 7);
  PrintList(A, 0, 7);
}