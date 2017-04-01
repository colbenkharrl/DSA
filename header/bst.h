struct BNode {
	int key;
	BNode *p;
	BNode *l;
	BNode *r;
	BNode(int k);
};

class BST {
 public:
	BNode *root;
	BST();
	BST(BNode *r);
	void PrintInOrder(BNode *x);
	void PrintPreOrder(BNode *x);
	void PrintPostOrder(BNode *x);
	BNode* Search(BNode *x, int k);
	BNode* SearchIterative(BNode *x, int k);
	BNode* Minimum(BNode *x);
	BNode* Maximum(BNode *x);
	BNode* Successor(BNode *x);
	BNode* Predecessor(BNode *x);
	void Insert(BNode *z);
	void Transplant(BNode *u, BNode *v);
	void Delete(BNode *z);
};