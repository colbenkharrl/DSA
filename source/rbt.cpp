#include "../header/rbt.h"
#include "../header/util.h"

#include <iostream>

using namespace std;

RNode::RNode(int k) {
	key = k;
	l = NULL;
	r = NULL;
	p = NULL;
	color = black;
}

RNode::RNode(int k, Color c) {
	key = k;
	l = NULL;
	r = NULL;
	p = NULL;
	color = c;
}

RBT::RBT() {
	nil = new RNode(0);
	root = nil;
}
RBT::RBT(RNode *r) {
	root = r;
	nil = new RNode(0);
}
void RBT::PrintInOrder(RNode *x) {
	if (x != nil) {
		PrintInOrder(x->l);
		cout << x->key << " ";
		PrintInOrder(x->r);
	}
}
void RBT::PrintPreOrder(RNode *x) {
	if (x != nil) {
		cout << x->key << " ";
		PrintInOrder(x->l);
		PrintInOrder(x->r);
	}
}
void RBT::PrintPostOrder(RNode *x) {
	if (x != nil) {
		PrintInOrder(x->l);
		PrintInOrder(x->r);
		cout << x->key << " ";
	}
}
RNode* RBT::Search(RNode *x, int k) {
	if (x == nil || x->key == k) {
		return x;
	}
	if (k < x->key) {
		return Search(x->l, k);
	} else {
		return Search(x->r, k);
	}
}
RNode* RBT::SearchIterative(RNode *x, int k) {
	while (x != nil && k != x->key) {
		if (k < x->key) {
			x = x->l;
		} else {
			x = x->r;
		}
	}
	return x;
}
RNode* RBT::Minimum(RNode *x) {
	while (x->l != nil) {
		x = x->l;
	}
	return x;
}
RNode* RBT::Maximum(RNode *x) {
	while (x->r != nil) {
		x = x->r;
	}
	return x;
}
RNode* RBT::Successor(RNode *x) {
	RNode *y;
	if (x->r != nil) {
		return Minimum(x->r);
	}
	y = x->p;
	while (y != nil && x == y->r) {
		x = y;
		y = y->p;
	}
	return y;
}
RNode* RBT::Predecessor(RNode *x) {
	RNode *y;
	if (x->l != nil) {
		return Maximum(x->l);
	}
	y = x->p;
	while (y != nil && x == y->l) {
		x = y;
		y = y->p;
	}
	return y;
}
void RBT::Insert(RNode *z) {
	RNode *y = nil;
	RNode *x = root;
	while (x != nil) {
		y = x;
		if (z->key < x->key) {
			x = x->l;
		} else {
			x = x->r;
		}
	}
	z->p = y;
	if (y == nil) {
		root = z;
	} else if (z->key < y->key) {
		y->l = z;
	} else {
		y->r = z;
	}
	z->l = nil;
	z->r = nil;
	z->color = red;
	InsertFixup(z);
}
void RBT::InsertFixup(RNode *z) {
	RNode *y;
	while (z->p->color == red) {
		if (z->p == z->p->p->l) {
			y = z->p->p->r;
			if (y->color == red) {
				z->p->color = black;
				y->color = black;
				z->p->p->color = red;
				z = z->p->p;
			} else {
				if (z == z->p->r) {
					z = z->p;
					LeftRotate(z);
				}
				z->p->color = black;
				z->p->p->color = red;
				RightRotate(z->p->p);
			}
		} else {
			y = z->p->p->l;
			if (y->color == red) {
				z->p->color = black;
				y->color = black;
				z->p->p->color = red;
				z = z->p->p;
			} else {
				if (z == z->p->l) {
					z = z->p;
					RightRotate(z);
				}
				z->p->color = black;
				z->p->p->color = red;
				LeftRotate(z->p->p);
			}
		}
	}
	root->color = black;
}
void RBT::LeftRotate(RNode *x) {
	RNode *y = x->r;
	x->r = y->l;
	if (y->l != nil) {
		y->l->p = x;
	}
	y->p = x->p;
	if (x->p == nil) {
		root = y;
	} else if (x == x->p->l) {
		x->p->l = y;
	} else {
		x->p->r = y;
	}
	y->l = x;
	x->p = y;
}
void RBT::RightRotate(RNode *x) {
	RNode *y = x->l;
	x->l = y->r;
	if (y->r != nil) {
		y->r->p = x;
	}
	y->p = x->p;
	if (x->p == nil) {
		root = y;
	} else if (x == x->p->r) {
		x->p->r = y;
	} else {
		x->p->l = y;
	}
	y->r = x;
	x->p = y;
}
void RBT::Transplant(RNode *u, RNode *v) {
	if (u->p == nil) {
		root = v;
	} else if (u == u->p->l) {
		u->p->l = v;
	} else {
		u->p->r = v;
	}
	v->p = u->p;
}
void RBT::Delete(RNode *z) {
	RNode *y = z, *x;
	Color yOC = y->color;
	if (z->l == nil) {
		x = z->r;
		Transplant(z, z->r);
	} else if (z->r == nil) {
		x = z->l;
		Transplant(z, z->l);
	} else {
		y = Minimum(z->r);
		yOC = y->color;
		x = y->r;
		if (y->p == z) {
			x->p = y;
		} else {
			Transplant(y, y->r);
			y->r = z->r;
			y->r->p = y;
		}
		Transplant(z, y);
		y->l = z->l;
		y->l->p = y;
		y->color = z->color;
	}
	if (yOC == black) {
		DeleteFixup(x);
	}
}
void RBT::DeleteFixup(RNode *x) {
	RNode *w;
	while (x != root && x->color == black) {
		if (x == x->p->l) {
			w = x->p->r;
			if (w->color == red) {
				w->color = black;
				x->p->color = red;
				LeftRotate(x->p);
				w = x->p->r;
			}
			if (w->l->color == black && w->r->color == black) {
				w->color = red;
				x = x->p;
			} else {
				if (w->r->color == black) {
					w->l->color = black;
					w->color = red;
					RightRotate(w);
					w = x->p->r;
				}
				w->color = x->p->color;
				x->p->color = black;
				w->r->color = black;
				LeftRotate(x->p);
				x = root;
			}
		} else {
			w = x->p->l;
			if (w->color == red) {
				w->color = black;
				x->p->color = red;
				RightRotate(x->p);
				w = x->p->l;
			}
			if (w->r->color == black && w->l->color == black) {
				w->color = red;
				x = x->p;
			} else {
				if (w->l->color == black) {
					w->r->color = black;
					w->color = red;
					LeftRotate(w);
					w = x->p->l;
				}
				w->color = x->p->color;
				x->p->color = black;
				w->l->color = black;
				RightRotate(x->p);
				x = root;
			}
		}
	}
	x->color = black;
}