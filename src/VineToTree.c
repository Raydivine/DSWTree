#include "VineToTree.h"
#include "Node.h"
#include "Rotations.h"
#include "GetNumNodes.h"
#include <math.h>
#include <stdio.h>

void rightVineToTree(Node **rightVine){
  Node *root = *rightVine;
  int i, j , n = getNumNodes(root), m = pow( 2, floor(log2(n+1))) -1;


  *rightVine = root;
}


void printVine(Node *root){
  while(root!=NULL){
    printf("root =%d  ", root->data);
    if(root->left)
        printf("leftChild =%d  ", (root->left)->data);
    if(root->right)
        printf("rightChild =%d  ", (root->right)->data);
    printf("\n");
    root = root->right;
  }
}

  // printf("root: %d\n",root->data);
  // printVine(root);
  // leftRotate(&current);
  // printf("root: %d\n",root->data);
  // printVine(root);

void compress(Node **rootPtr, int times){
  int i;
 
  for(i=0; i<times;i++){
    _compress( &(*rootPtr), i );
  }
  
}  

void _compress(Node **rootPtr, int times){
 
  if(times ==0)
    leftRotate(&(*rootPtr));
  else 
    _compress( &((*rootPtr)->right), times-1);  
}  
  
  
/*
void compress(Node **rootPtr, int times){
  int i;
  Node *root = *rootPtr, *current;
  
  if(times >0){
    leftRotate(&root);
    current = root->right;
  }
   
  for(i=1; i<times; i++){
    leftRotate(&current);
    replaceRightEndToNewNode( &root, current);
    current = current->right;
  }
  *rootPtr = root;
}

void replaceRightEndToNewNode(Node **rootPtr, Node *newNode){
  Node *root = *rootPtr;
    
	if(root == NULL || root->right == NULL){
		*rootPtr = newNode;
		return;
	}
  else
    replaceRightEndToNewNode( &root->right, newNode);
  
}*/


