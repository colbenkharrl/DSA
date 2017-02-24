#include "dset.h"
#include "heap.h"
#include "queue.h"
#include "sort.h"
#include "stack.h"

#include <iostream>
#include <cstdlib>

//	used for testing and debugging
using namespace std;

int main()
{
    int length = 20;
    int *A = new int[length];
	FillReverse(A, length);
	cout << "Min-Heap: " << endl;
	MinHeap heap (A, length);
    Print(A, 0, length-1);
}