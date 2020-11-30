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
nodeD *insertD(nodeD* treeD,double x);
void findNode(node *tree,int x);
int findMin(node *tree);
int findMax(node *tree);
int TreeHeight(node *tree);


#endif
