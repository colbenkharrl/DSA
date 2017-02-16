//      Colben Kharrl | HEAP DATA STRUCTURE

#include "heap.h"
#include <iostream>
#include <limits>

using namespace std;

int Heap::Parent(int i)
{
    return i / 2;
}
int Heap::Left(int i)
{
    return 2 * i;
}
int Heap::Right(int i)
{
    return 2 * i + 1;
}
void Heap::Heapify(int i)
{
    int largest, temp;
    int l = Left(i);
    int r = Right(i);
    if (l <= heapSize && A[l - 1] > A[i - 1])
    {
	largest = l;
    }
    else
    {
	largest = i;
    }
    if (r <= heapSize && A[r - 1] > A[largest - 1])
    {
	largest = r;
    }
    if (largest != i)
    {
	temp = A[i - 1];
	A[i - 1] = A[largest - 1];
	A[largest - 1] = temp;
	Heapify(largest);
    }
}
void Heap::BuildHeap()
{
    for (int i = heapSize / 2; i > 0; i--)
    {
	Heapify(i);
    }
}
Heap::Heap(int size)
{
    heapSize = 0;
    A = new int[size];
    passed = 0;
}
Heap::Heap(int *I, int size)
{
    A = I;
    heapSize = size;
    BuildHeap();
    passed = 1;
}
Heap::~Heap()
{
    if (!passed)
    {
	delete[] A;
    }
}
int Heap::Maximum()
{
    return A[0];
}
int Heap::ExtractMax()
{
    int max;
    if (heapSize <= 1)
    {
	cout << "Error: no elements to be extracted." << endl;
	return -1;
    }
    else
    {
	max = A[0];
	A[0] = A[heapSize - 1];
	heapSize--;
	Heapify(0);
	return max;
    }
}
void Heap::Insert(int key)
{
    int i;
    heapSize++;
    A[heapSize] = 0 - numeric_limits<int>::max();
    IncreaseKey(heapSize, key);
}
void Heap::IncreaseKey(int i, int key)
{
    int temp;
    if (key < A[i - 1])
    {
	cout << "Error: new key smaller than current key." << endl;
    }
    else
    {
	A[i - 1] = key;
	while (i > 1 && A[Parent(i) - 1] < A[i - 1])
	{
	    temp = A[i - 1];
	    A[i - 1] = A[Parent(i) - 1];
	    A[Parent(i) - 1] = temp;
	    i = Parent(i);
	}
    }
}

void Heap::Print() {
	for (int i = 0; i < heapSize; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
}