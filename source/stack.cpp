//	Colben Kharrl | STACK DATA STRUCTURE (dynamic array)

#include "stack.h"
#include <iostream>

using namespace std;

//	constructor for creating the array internally
Stack::Stack(int s)
{
    A = new int[size];
    size = s;
    top = 0;
	passed = 0;
}
//	constructor for passing a dynamic array
Stack::Stack(int *I, int t, int s)
{
    A = I;
    size = s;
    top = t;
	passed = 1;
}
//	destructor to delete list if created internally
Stack::~Stack()
{
    if (!passed)
    {
	delete[] A;
    }
}
//	empty stack validation
int Stack::StackEmpty()
{
    if (top == 0)
    {
	return 1;
    }
    else
    {
	return 0;
    }
}
//	push an element on to the stack
void Stack::Push(int x)
{
    if (top == size)
    {
	cout << "Error: Stack full; unable to push." << endl;
    }
    else
    {
	top++;
	A[top - 1] = x;
    }
}
//	pop an element off of the stack
int Stack::Pop()
{
    if (StackEmpty())
    {
	cout << "Error: Stack empty; unable to pop." << endl;
	return -1;
    }
    else
    {
	top--;
	return A[top];
    }
}
//	print the stack
void Stack::Print()
{
    for (int i = 0; i < top; i++)
    {
	cout << A[i] << " ";
    }
    cout << endl;
}