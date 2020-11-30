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

node *insertD(nodeD* tree, double x){
	if(tree == NULL){
		nodeD *root = (nodeD*)malloc(sizeof(nodeD));
		root -> left = NULL;
		root -> right = NULL;
		root -> data = x;
		return root;
	}
	
	nodeD *iter = tree;
	
	if(iter->data < x){
		tree -> right = insert(tree -> right, x);
		return tree;	
	}
	
	tree->left = insert(tree -> left, x);	

	return tree;
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

void travers(node *tree){
	if(tree == NULL) return;
	travers(tree->left);
	printf("%d  ", tree->data);
	travers(tree->right);
}

void inorder(node *tree){
    if(tree == NULL){
        return;
    }

    inorder(tree->left);
    printf("%d ", tree->data);
    inorder(tree->right);
}

void preorder(node *tree){
    if(tree == NULL){
        return;
    }

    printf("%d ", tree->data);
    preorder(tree->left);
    preorder(tree->right);
}

void postorder(node *tree){
    if(tree == NULL){
        return;
    }

    postorder(tree->left);
    postorder(tree->right);
    printf("%d ", tree->data);
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



void printCurrent(node *tree, int level){
    if(tree == NULL){
        return;
    }

    if(level == 1){ 
        printf("%d ", tree->data);
    } 

    else if(level > 1){ 
        printCurrent(tree->left, level-1); 
        printCurrent(tree->right, level-1); 
    } 
}

void levelorder(node *tree){
    int height = TreeHeight(tree);

    for(int i = 0; i <= height; i++){
        printCurrent(tree, i);
        printf("\n");
    }
}
