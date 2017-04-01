enum Color {black, red};

struct RNode {
	int key;
	RNode *p;
	RNode *l;
	RNode *r;
	Color color;
	RNode(int k);
	RNode(int k, Color c);
};

class RBT {
 public:
	RNode *root;
	RNode *nil;
	RBT();
	RBT(RNode *r);
	void PrintInOrder(RNode *x);
	void PrintPreOrder(RNode *x);
	void PrintPostOrder(RNode *x);
	RNode* Search(RNode *x, int k);
	RNode* SearchIterative(RNode *x, int k);
	RNode* Minimum(RNode *x);
	RNode* Maximum(RNode *x);
	RNode* Successor(RNode *x);
	RNode* Predecessor(RNode *x);
	void Insert(RNode *z);
	void InsertFixup(RNode *z);
	void LeftRotate(RNode *x);
	void RightRotate(RNode *x);
	void Transplant(RNode *u, RNode *v);
	void Delete(RNode *z);
	void DeleteFixup(RNode *x);
};