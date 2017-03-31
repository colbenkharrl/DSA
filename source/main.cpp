#include "../header/dset.h"
#include "../header/bst.h"
#include "../header/heap.h"
#include "../header/queue.h"
#include "../header/sort.h"
#include "../header/stack.h"
#include "../header/util.h"

#include <iostream>

using namespace std;

//	used for testing and debugging

int main() {
	BST tree;
	tree.Insert(new Node(5));
	tree.Insert(new Node(1));
	tree.Insert(new Node(2));
	tree.Insert(new Node(8));
	tree.Insert(new Node(10));
	tree.PrintInOrder(tree.root);
	cout << endl;
	cout << "Printing successor of 8" << endl;
	Node *s = tree.Search(tree.root, 8);
	cout << tree.Successor(s)->key << endl;
	cout << "Printing predecessor of 8" << endl;
	cout << tree.Predecessor(s)->key << endl;
}