//      Colben Kharrl | SORTING ALGORITHMS (for dynamic arrays)

#include "sort.h"
#include "heap.h"
#include <limits>
#include <iostream>

using namespace std;

//	print dynamic array from index start to end
void PrintList(int *A, int start, int end)
{
    for (int i = start; i <= end; i++)
    {
	cout << A[i] << " ";
    }
    cout << endl;
}
void InsertionSort(int *A, int length)
{
    int key, i;
    for (int j = 1; j < length; j++)
    {
	key = A[j];
	i = j - 1;
	while (i > -1 and A[i] > key)
	{
	    A[i + 1] = A[i];
	    i = i - 1;
	}
	A[i + 1] = key;
    }
}

void Merge(int *A, int p, int q, int r)
{
    int n1, n2, i, j, k;
    n1 = q - p + 1;
    n2 = r - q;
    int *L = new int[n1 + 1];
    int *R = new int[n2 + 1];
    for (i = 0; i < n1; i++)
    {
	L[i] = A[p + i];
    }
    for (j = 0; j < n2; j++)
    {
	R[j] = A[q + j + 1];
    }
    L[n1] = numeric_limits<int>::max();
    R[n2] = numeric_limits<int>::max();
    i = 0;
    j = 0;
    for (k = p; k <= r; k++)
    {
	if (L[i] <= R[j])
	{
	    A[k] = L[i];
	    i++;
	}
	else
	{
	    A[k] = R[j];
	    j++;
	}
    }
}

void MergeSort(int *A, int p, int r)
{
    int q;
    if (p < r)
    {
	q = (p + r) / 2;
	MergeSort(A, p, q);
	MergeSort(A, q + 1, r);
	Merge(A, p, q, r);
    }
}
void HeapSort(int *A, int size)
{
    int temp;
    Heap heap(A, size);
    for (int i = size - 1; i > 0; i--)
    {
	temp = A[0];
	A[0] = A[i];
	A[i] = temp;
	heap.heapSize--;
	heap.Heapify(1);
    }
}
void QuickSort(int *A, int p, int r)
{
    if (p < r)
    {
	int q = Partition(A, p, r);
	QuickSort(A, p, q - 1);
	QuickSort(A, q + 1, r);
    }
}
int Partition(int *A, int p, int r)
{
    int x, i, j, temp;
    x = A[r];
    i = p - 1;
    for (j = p; j < r; j++)
    {
	if (A[j] <= x)
	{
	    i++;
	    temp = A[i];
	    A[i] = A[j];
	    A[j] = temp;
	}
    }
    temp = A[i + 1];
    A[i + 1] = A[r];
    A[r] = temp;
    return i + 1;
}
//	partition variation to choose pivot value k
int PartitionAt(int *A, int p, int r, int k) {
	int i, j, l, temp;
	for (l = p; l <= r; l++) {
		if (A[l] == k) {
			temp = A[l];
	    	A[l] = A[r];
	    	A[r] = temp;
		}
	}
    i = p - 1;
    for (j = p; j < r; j++)
    {
	if (A[j] <= k)
	{
	    i++;
	    temp = A[i];
	    A[i] = A[j];
	    A[j] = temp;
	}
    }
    temp = A[i + 1];
    A[i + 1] = A[r];
    A[r] = temp;
    return i + 2 - p;
}
//	returns the median of the elements between indexes
int Median(int *A, int start, int end) {
	int index, size, i;
	int* I;
	size = end-start+1;
	I = new int[size];
	index = 0;
	for (i = start; i <= end; i++) {
		I[index] = A[i];
		index++;
	}
	InsertionSort(I, size);
	return I[size/2];
}
//	selects ith smallest element using median-of-medians method
int Select(int *A, int i, int start, int end) {
	int size, arrays, x, k, j;
	int *medians, *I;
	size = end - start + 1;
	if (size % 5 == 0) {
		arrays = size / 5;
	} else {
		arrays = (size / 5) + 1;
	}
	medians = new int [arrays];
	for (j = 0; j < arrays; j++) {
		if (j == arrays-1) {
			medians[j]  = Median(A, start+j*5, end);
		} else {
			medians[j]  = Median(A, start+(j*5), start+((j+1)*5-1));
		}
	}
	x = Median(medians, 0, arrays-1);
	k = PartitionAt(A, start, end, x);
	if (i == k) {
		return x;
	} else if (i < k) {
		return Select(A, i, start, k-2);
	} else {
		return Select(A, i-k, k, end);
	}
}