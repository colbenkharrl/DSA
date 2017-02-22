#include "heap.h"
#include "queue.h"
#include "sort.h"
#include "stack.h"
#include <iostream>
#include <cstdlib>

//	used for testing and debugging
using namespace std;

int main() {
  int *A = new int[10];
  srand(time(0));
  int element;
  for (int i = 0; i < 10; i++) // fill array with random numbers
  {
    element = rand()%100+1;      //element E[1,100]
	A[i] = element;
  }
  PrintList(A, 0, 9);
  int res = Select(A, 1, 0, 9);
  cout << "1st smallest element: " << res << endl;
}