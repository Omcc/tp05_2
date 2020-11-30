#include <stdio.h>
#include <stdlib.h>
#include "weekTwoBinary.h"

node *insert(node* tree, int x){
	if(tree == NULL){
		node *root = (node*)malloc(sizeof(node));
		root -> left = NULL;
		root -> right = NULL;
		root -> data = x;
		return root;
	}
	
	node *iter = tree;
	
	if(iter->data < x){
		tree -> right = insert(tree -> right, x);
		return tree;	
	}
	
	tree->left = insert(tree -> left, x);	

	return tree;
}

nodeD *insertD(nodeD* treeD, double x){
	if(treeD == NULL){
		nodeD *root = (nodeD*)malloc(sizeof(nodeD));
		root -> left = NULL;
		root -> right = NULL;
		root -> data = x;
		return root;
	}
	
	nodeD *iter = treeD;
	
	if(iter->data < x){
		treeD -> right = insertD(treeD -> right, x);
		return treeD;	
	}
	
	treeD->left = insertD(treeD -> left, x);	

	return treeD;
}

node *deleteNode(node *tree, int x){
    if(tree == NULL){
        return NULL;
    }

    if(tree->data == x){
        if(tree->left == NULL && tree->right == NULL){
            return NULL;
        }

        if(tree->right != NULL){
            tree->data = findMin(tree->right);
            tree->right = deleteNode(tree->right, findMin(tree->right));
            return tree;
        }

        tree->data = findMax(tree->left);
        tree->left = deleteNode(tree->left, findMax(tree->left));
        return tree;
    }

    if(tree->data < x){
        tree->right = deleteNode(tree->right, x);
        return tree;
    }

    tree->left = deleteNode(tree->left, x);
    return tree;
}

void findNode(node *tree,int x)
{
 	if(tree==NULL)
		return;
	if(tree->data == x)
		return;
	else if(tree->data > x)
		findNode(tree->left,x);
	else
		findNode(tree->right,x);
}


void findNodeD(nodeD *tree,double x)
{
 	if(tree==NULL)
		return;
	if(tree->data == x)
		return;
	else if(tree->data > x)
		findNode(tree->left,x);
	else
		findNode(tree->right,x);
}


int TreeHeight(node *tree){
    if(tree ==NULL){
        return 0;
    }

   else{ 
       int lD = TreeHeight(tree->left); 
       int rD = TreeHeight(tree->right); 
  
       if(lD > rD){
           return(lD+1);
       }

       else return(rD+1); 
   }
}


int findMax(node *tree){
	if(tree == NULL){
		printf("no element on tree.\n");
        return 0;
	}

	node *iter = tree;

	while(iter->right != NULL){
		iter = iter->right;
	}

	return iter->data;
}

int findMin(node *tree){
	if(tree == NULL){
		printf("no element on tree.\n");
        return 0;
	}

	node *iter = tree;

	while(iter->left != NULL){
		iter = iter->left;
	}

	return iter->data;
}



