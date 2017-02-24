#include "dset.h"
#include "heap.h"
#include "queue.h"
#include "sort.h"
#include "stack.h"

#include <iostream>
#include <cstdlib>

//	used for testing and debugging
using namespace std;

void Randomize(int *I, int length)
{
    srand(time(0));
    int element;
    for (int i = 0; i < length; i++) // fill array with random numbers
    {
		element = rand() % 100 + 1; //element E[1,100]
		I[i] = element;
    }
    PrintList(I, 0, length - 1);
}

int main()
{
    int length = 20, x;
    int *A = new int[length];
	Randomize(A, length);
	cout << "Min-Heap: " << endl;
	MinHeap heap (A, length);
    PrintList(A, 0, length-1);
}