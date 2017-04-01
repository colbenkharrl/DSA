#include "../header/bst.h"
#include "../header/util.h"

#include <iostream>

using namespace std;

BNode::BNode(int k) {
	key = k;
	l = NULL;
	r = NULL;
	p = NULL;
}

BST::BST() {
	root = NULL;
}
BST::BST(BNode *r) {
	root = r;
}
void BST::PrintInOrder(BNode *x) {
	if (x != NULL) {
		PrintInOrder(x->l);
		cout << x->key << " ";
		PrintInOrder(x->r);
	}
}
void BST::PrintPreOrder(BNode *x) {
	if (x != NULL) {
		cout << x->key << " ";
		PrintInOrder(x->l);
		PrintInOrder(x->r);
	}
}
void BST::PrintPostOrder(BNode *x) {
	if (x != NULL) {
		PrintInOrder(x->l);
		PrintInOrder(x->r);
		cout << x->key << " ";
	}
}
BNode* BST::Search(BNode *x, int k) {
	if (x == NULL || x->key == k) {
		return x;
	}
	if (k < x->key) {
		return Search(x->l, k);
	} else {
		return Search(x->r, k);
	}
}
BNode* BST::SearchIterative(BNode *x, int k) {
	while (x != NULL && k != x->key) {
		if (k < x->key) {
			x = x->l;
		} else {
			x = x->r;
		}
	}
	return x;
}
BNode* BST::Minimum(BNode *x) {
	while (x->l != NULL) {
		x = x->l;
	}
	return x;
}
BNode* BST::Maximum(BNode *x) {
	while (x->r != NULL) {
		x = x->r;
	}
	return x;
}
BNode* BST::Successor(BNode *x) {
	BNode *y;
	if (x->r != NULL) {
		return Minimum(x->r);
	}
	y = x->p;
	while (y != NULL && x == y->r) {
		x = y;
		y = y->p;
	}
	return y;
}
BNode* BST::Predecessor(BNode *x) {
	BNode *y;
	if (x->l != NULL) {
		return Maximum(x->l);
	}
	y = x->p;
	while (y != NULL && x == y->l) {
		x = y;
		y = y->p;
	}
	return y;
}
void BST::Insert(BNode *z) {
	BNode *y = NULL;
	BNode *x = root;
	while (x != NULL) {
		y = x;
		if (z->key < x->key) {
			x = x->l;
		} else {
			x = x->r;
		}
	}
	z->p = y;
	if (y == NULL) {
		root = z;
	} else if (z->key < y->key) {
		y->l = z;
	} else {
		y->r = z;
	}
}
void BST::Transplant(BNode *u, BNode *v) {
	if (u->p == NULL) {
		root = v;
	} else if (u == u->p->l) {
		u->p->l = v;
	} else {
		u->p->r = v;
	}
	if (v != NULL) {
		v->p = u->p;
	}
}
void BST::Delete(BNode *z) {
	BNode *y;
	if (z->l == NULL) {
		Transplant(z, z->r);
	} else if (z->r == NULL) {
		Transplant(z, z->l);
	} else {
		y = Minimum(z->r);
		if (y->p != z) {
			Transplant(y, y->r);
			y->r = z->r;
			y->r->p = y;
		}
		Transplant(z, y);
		y->l = z->l;
		y->l->p = y;
	}
}