//      Colben Kharrl | SORTING ALGORITHMS (for dynamic arrays)

#include "sort.h"
#include "heap.h"
#include <iostream>
#include <limits>

using namespace std;

//	print dynamic array from index start to end
void PrintList(int *A, int start, int end) {
  for (int i = start; i <= end; i++) {
    cout << A[i] << " ";
  }
  cout << endl;
}
void InsertionSort(int *A, int length) {
  int key, i;
  for (int j = 1; j < length; j++) {
    key = A[j];
    i = j - 1;
    while (i > -1 and A[i] > key) {
      A[i + 1] = A[i];
      i = i - 1;
    }
    A[i + 1] = key;
  }
}
void Merge(int *A, int p, int q, int r) {
  int n1, n2, i, j, k;
  n1 = q - p + 1;
  n2 = r - q;
  int *L = new int[n1 + 1];
  int *R = new int[n2 + 1];
  for (i = 0; i < n1; i++) {
    L[i] = A[p + i];
  }
  for (j = 0; j < n2; j++) {
    R[j] = A[q + j + 1];
  }
  L[n1] = numeric_limits<int>::max();
  R[n2] = numeric_limits<int>::max();
  i = 0;
  j = 0;
  for (k = p; k <= r; k++) {
    if (L[i] <= R[j]) {
      A[k] = L[i];
      i++;
    } else {
      A[k] = R[j];
      j++;
    }
  }
}
void MergeSort(int *A, int p, int r) {
  int q;
  if (p < r) {
    q = (p + r) / 2;
    MergeSort(A, p, q);
    MergeSort(A, q + 1, r);
    Merge(A, p, q, r);
  }
}
void HeapSort(int *A, int size) {
  int temp;
  Heap heap(A, size);
  for (int i = size - 1; i > 0; i--) {
    temp = A[0];
    A[0] = A[i];
    A[i] = temp;
    heap.heapSize--;
    heap.Heapify(1);
  }
}
void QuickSort(int *A, int p, int r) {
  if (p < r) {
    int q = Partition(A, p, r);
    QuickSort(A, p, q - 1);
    QuickSort(A, q + 1, r);
  }
}
int Partition(int *A, int p, int r) {
  int x, i, j, temp;
  x = A[r];
  i = p - 1;
  for (j = p; j < r; j++) {
    if (A[j] <= x) {
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
      break;
    }
  }
  i = p - 1;
  for (j = p; j < r; j++) {
    if (A[j] <= k) {
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
//	recursively selects ith smallest element using Median-of-Medians method:
//
//	5 steps:
//		1. Divide the n elements of the input array into floor(n/5) groups
//			of 5 elements each and at most one group made up of the remaining 
//			n mod 5 elements.
//		2. Find the median of each of the ceiling(n/5) groups by first
//			insertion-sorting the elements of each group (of which there are at
//			most 5) and then picking the median from the sorted list of group elements.
//		3. Use SELECT recursively to find the median x of the ceiling(n/5) medians found
//			in step 2. (If there are an even number of medians, then by my convention, x
//			is the higher median.)
//		4. Partition the input array around the median-of-medians x using the modified
//			version of PARTITION. Let k be one more than the number of elements on the
//			low side of the partition, so that x is the kth smallest element and there are n-k
//			elements on the high side of the partition.
//		5. If i != k, then return x. Otherwise, use SELECT recursively to find the ith
//			smallest element on the low side if i < k, or the (i-k)th smallest element on
//			the high side if i > k.
int Select(int *A, int i, int start, int end) {
  int size, arrays, x, k, j, iter, startIn, endIn;
  int *medians, *I, *arr;
  size = end - start + 1;
  if (size == 1) {
    return A[start];
  }
  if (size % 5 == 0) {
    arrays = size / 5;
  } else {
    arrays = (size / 5) + 1;
  }
  medians = new int[arrays];
  for (j = 0; j < arrays; j++) {
    startIn = start + j * 5;
    if (j == arrays - 1) {
      endIn = end;
      size = endIn - startIn + 1;
    } else {
      endIn = start + ((j + 1) * 5 - 1);
      size = 5;
    }
    arr = new int[size];
    for (iter = 0; iter < size; iter++) {
      arr[iter] = A[startIn + iter];
    }
    InsertionSort(arr, size);
    medians[j] = arr[size / 2];
  }

  x = Select(medians, (arrays / 2) + 1, 0, arrays - 1);
  k = PartitionAt(A, start, end, x);
  if (i == k) {
    return x;
  } else if (i < k) {
    return Select(A, i, start, k - 2);
  } else {
    return Select(A, i - k, k, end);
  }
}