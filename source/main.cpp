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
    int length = 10, x;
    int *A = new int[length];
	cout << "Insertion Sort:" << endl;
	Randomize(A, length);
    InsertionSort(A, length);
    PrintList(A, 0, length-1);
	cout << "Bubble Sort:" << endl;
	Randomize(A, length);
    BubbleSort(A, length);
    PrintList(A, 0, length-1);
	cout << "Quick Sort:" << endl;
	Randomize(A, length);
    QuickSort(A, 0, length-1);
    PrintList(A, 0, length-1);
    cout << "Merge Sort:" << endl;
	Randomize(A, length);
    MergeSort(A, 0, length-1);
    PrintList(A, 0, length-1);
	cout << "Heap Sort:" << endl;
	Randomize(A, length);
    HeapSort(A, length);
    PrintList(A, 0, length-1);
	cout << "Median Selection (linear):" << endl;
	Randomize(A, length);
    x = Select(A, 3, 0, length-1);
    cout << "3rd smallest element: " << x << endl;
    delete[] A;
	cout << "Disjoint set 'i:A[i]': " << endl;
	DisjointSet set (length);
	set.PrintSet();
	set.Union(1, 2);
	set.PrintSet();
	set.Union(4,5);
	set.PrintSet();
	set.Union(5,2);
	set.PrintSet();
}