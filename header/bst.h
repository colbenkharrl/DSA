struct Node {
	int key;
	Node *p;
	Node *l;
	Node *r;
	Node(int k);
};

class BST {
 public:
	Node *root;
	BST();
	BST(Node *r);
	void PrintInOrder(Node *x);
	void PrintPreOrder(Node *x);
	void PrintPostOrder(Node *x);
	Node* Search(Node *x, int k);
	Node* SearchIterative(Node *x, int k);
	Node* Minimum(Node *x);
	Node* Maximum(Node *x);
	Node* Successor(Node *x);
	Node* Predecessor(Node *x);
	void Insert(Node *z);
	void Transplant(Node *u, Node *v);
	void Delete(Node *z);
};