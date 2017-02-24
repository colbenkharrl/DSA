//      Colben Kharrl | MAX-HEAP DATA STRUCTURE (for dynamic arrays)

#include "heap.h"
#include <iostream>
#include <limits>

using namespace std;
//	returns index of parent node
int MaxHeap::Parent(int i)
{
    return i / 2;
}
//	returns index of left child
int MaxHeap::Left(int i)
{
    return 2 * i;
}
//	returns index of right child
int MaxHeap::Right(int i)
{
    return 2 * i + 1;
}
//	recursively apply the heap property to nodes at and below index
void MaxHeap::Heapify(int i)
{
    int largest, temp;
    int l = Left(i);
    int r = Right(i);
    if (l <= heaplength && A[l - 1] > A[i - 1])
    {
	largest = l;
    }
    else
    {
	largest = i;
    }
    if (r <= heaplength && A[r - 1] > A[largest - 1])
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
//	build a heap from an array
void MaxHeap::BuildHeap()
{
    for (int i = heaplength / 2; i > 0; i--)
    {
	Heapify(i);
    }
}
//	constructor to build the array internally
MaxHeap::MaxHeap(int length)
{
    heaplength = 0;
    A = new int[length];
    passed = 0;
}
//	constructor to pass an existing dynamic array
MaxHeap::MaxHeap(int *I, int length)
{
    A = I;
    heaplength = length;
    BuildHeap();
    passed = 1;
}
//	destructor to delete the array if it was created internally
MaxHeap::~MaxHeap()
{
    if (!passed)
    {
	delete[] A;
    }
}
//	return the largest key in the heap
int MaxHeap::Maximum()
{
    return A[0];
}
//	remove and return the largest key node
int MaxHeap::ExtractMax()
{
    int max;
    if (heaplength <= 1)
    {
	cout << "Error: no elements to be extracted." << endl;
	return -1;
    }
    else
    {
	max = A[0];
	A[0] = A[heaplength - 1];
	heaplength--;
	Heapify(0);
	return max;
    }
}
//	insert a node with value key into the heap
void MaxHeap::Insert(int key)
{
    int i;
    heaplength++;
    A[heaplength] = 0 - numeric_limits<int>::max();
    IncreaseKey(heaplength, key);
}
//	increase the key of value at index
void MaxHeap::IncreaseKey(int i, int key)
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
//	print the heap
void MaxHeap::Print()
{
    for (int i = 0; i < heaplength; i++)
    {
	cout << A[i] << " ";
    }
    cout << endl;
}

//
//	MIN-HEAP DATA STRUCTURE (for dynamic arrays)
//

MinHeap::MinHeap(int length) {
	heaplength = 0;
    A = new int[length];
    passed = 0;
}
MinHeap::MinHeap(int *I, int length) {
	A = I;
    heaplength = length;
    BuildHeap();
    passed = 1;
}
MinHeap::~MinHeap() {
	if (!passed)
    {
	delete[] A;
    }
}
void MinHeap::Heapify(int i) {
	int smallest, temp;
    int l = Left(i);
    int r = Right(i);
    if (l <= heaplength && A[l - 1] < A[i - 1])
    {
	smallest = l;
    }
    else
    {
	smallest = i;
    }
    if (r <= heaplength && A[r - 1] < A[smallest - 1])
    {
	smallest = r;
    }
    if (smallest != i)
    {
	temp = A[i - 1];
	A[i - 1] = A[smallest - 1];
	A[smallest - 1] = temp;
	Heapify(smallest);
    }
}
void MinHeap::BuildHeap() {
	for (int i = heaplength / 2; i > 0; i--)
    {
	Heapify(i);
    }
}
int MinHeap::Minimum() {
	return A[0];
}
int MinHeap::ExtractMin() {
	int min;
    if (heaplength <= 1)
    {
	cout << "Error: no elements to be extracted." << endl;
	return -1;
    }
    else
    {
	min = A[0];
	A[0] = A[heaplength - 1];
	heaplength--;
	Heapify(0);
	return min;
    }
}
void MinHeap::Insert(int key) {
	int i;
    heaplength++;
    A[heaplength] = 0 - numeric_limits<int>::max();
    DecreaseKey(heaplength, key);
}
void MinHeap::DecreaseKey(int i, int key) {
	int temp;
    if (key > A[i - 1])
    {
	cout << "Error: new key larger than current key." << endl;
    }
    else
    {
	A[i - 1] = key;
	while (i > 1 && A[Parent(i) - 1] > A[i - 1])
	{
	    temp = A[i - 1];
	    A[i - 1] = A[Parent(i) - 1];
	    A[Parent(i) - 1] = temp;
	    i = Parent(i);
	}
    }
}
int MinHeap::Parent(int i)
{
    return i / 2;
}
//	returns index of left child
int MinHeap::Left(int i)
{
    return 2 * i;
}
//	returns index of right child
int MinHeap::Right(int i)
{
    return 2 * i + 1;
}
void MinHeap::Print()
{
    for (int i = 0; i < heaplength; i++)
    {
	cout << A[i] << " ";
    }
    cout << endl;
}