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

void compress(Node **rootPtr, int times){
  int i;
  Node *root = *rootPtr, *current = root->right->right;
  
      // printf("root: %d\n",root->data);
     // printVine(root);
  
  
  if(times >0){
    leftRotate(&root);
 //   current = root->right;
  }
      // printf("current: %d\n",current->data);
     // printVine(current);

  for(i=1; i<times; i++){
     printf("root: %d\n",root->data);
    printVine(root);
    leftRotate(&current);
    printf("root: %d\n",root->data);
    printVine(root);

    replaceRightEndToNewNode( &root, current);
    current = current->right;
  }
  *rootPtr = root;
 // printVine(*rootPtr);
 // printVine(current);
}

void replaceRightEndToNewNode(Node **rootPtr, Node *newNode){
  Node *root = *rootPtr;
    
	if(root == NULL || root->right == NULL){
		*rootPtr = newNode;
		return;
	}
  else
    replaceRightEndToNewNode( &root->right, newNode);
  
}


