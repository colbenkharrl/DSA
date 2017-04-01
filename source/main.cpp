#include "../header/dset.h"
#include "../header/bst.h"
#include "../header/rbt.h"
#include "../header/heap.h"
#include "../header/queue.h"
#include "../header/sort.h"
#include "../header/stack.h"
#include "../header/util.h"

#include <iostream>

using namespace std;

//	used for testing and debugging

int main() {
	RBT tree;
	tree.Insert(new RNode(5));
	tree.Insert(new RNode(1));
	tree.Insert(new RNode(2));
	tree.Insert(new RNode(8));
	tree.Insert(new RNode(10));
	tree.PrintInOrder(tree.root);
	cout << endl << "Printing successor of 8" << endl;
	RNode *s = tree.Search(tree.root, 8);
	cout << tree.Successor(s)->key << endl;
	cout << "Printing predecessor of 8" << endl;
	cout << tree.Predecessor(s)->key << endl;
	cout << "Deleting Max" << endl;
	tree.Delete(tree.Maximum(tree.root));
	tree.PrintInOrder(tree.root);
	cout << endl <<  "Deleting Min" << endl;
	tree.Delete(tree.Minimum(tree.root));
	tree.PrintInOrder(tree.root);
	cout << endl;

}