#include "dset.h"
#include <iostream>

using namespace std;

DisjointSet::DisjointSet(int length) {
	A = new int[length];
	ulength = length;
	for (int i = 0; i < length; i++) {
		MakeSet(i);
	}
	passed = 0;
}
DisjointSet::~DisjointSet() {
	delete [] A;
}
void DisjointSet::MakeSet(int x) {
	A[x] = 0;
}
void DisjointSet::Link(int x, int y) {
	if ((0-A[x]) > (0-A[y])) {
		A[y] = x;
	} else {
		if ((0-A[x]) == (0-A[y])) {
			A[y] = A[y] - 1;
		}
		A[x] = y;
	}
}
int DisjointSet::FindSet(int x) {
	if (A[x] <= 0) {
		return x;
	} else {
		return FindSet(A[x]);
	}
}
void DisjointSet::Union(int x, int y) {
	Link(FindSet(x), FindSet(y));
}

void DisjointSet::Print() {
	for (int i = 0; i < ulength; i++) {
		cout << i << ":" << A[i] << " ";
	}
	cout << endl;
}