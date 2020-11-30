#ifndef weektwobinary_h
#define weektwobinary_h

typedef struct n{
	int data;

	struct n* left;
	struct n* right;
}node;

typedef struct p{
	double data;
	struct p* left;
	struct p* right;
}nodeD;

node * insert(node* tree, int x);
node *deleteNode(node *tree, int x);
void findNode(node *tree,int x);
void travers(node *tree);
void printCurrent(node *tree, int level);
void preorder(node *tree);
void inorder(node *tree);
void postorder(node *tree);
void levelorder(node *tree);
int findMin(node *tree);
int findMax(node *tree);
int TreeHeight(node *tree);


#endif
