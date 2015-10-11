#include "VineToTree.h"
#include "Node.h"
#include "Rotations.h"
#include "GetNumNodes.h"
#include <math.h>
#include <stdio.h>

void rightVineToTree(Node **rightVine){
  Node *root = *rightVine;
  int i, j , n = getNumNodes(root), m = pow( 2, floor(log2(n+1))) -1;

  for(i=0; i<n-m; i++){
    leftRotate(&root);
    root = root->right;
  }
    
    // for(j=0; j<(num/2-1); j++)
      // leftRotate( &(root->right)) ;
 // }
  
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
  Node  *root = *rootPtr, *current;
  
  if(times >= 1){
    leftRotate(&root);
    current = root->right;
  }
  
  for( i=1; i<times; i++){
    leftRotate(&current);
    current = current->right;
    printf("in\n");
  }
 printVine(root);
  
  
  *rootPtr = root;
}




