#include "../header/util.h"

#include <cstdlib>
#include <iostream>

using namespace std;

void Print(int *A, int p, int r) {
  int i;
  for (i = p; i <= r; i++) {
    cout << A[i] << " ";
  }
  cout << endl;
}
void Print(int *A, int s) {
	int i;
  for (i = 0; i < s; i++) {
    cout << A[i] << " ";
  }
  cout << endl;
}
void Randomize(int *A, int length) {
  srand(time(0));
  int element;
  for (int i = 0; i < length; i++) // fill array with random numbers
  {
    element = rand() % 100 + 1; // element E[1,100]
    A[i] = element;
  }
}
void FillReverse(int *A, int length) {
  int j = length;
  for (int i = 0; i < length; i++) // fill array with reverse sorted numbers
  {
    A[i] = j;
    j--;
  }
}