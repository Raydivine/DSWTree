#include "VineToTree.h"
#include "Node.h"
#include "Rotations.h"
#include "GetNumNodes.h"
#include <math.h>
#include <stdio.h>

void rightVineToTree(Node **rightVine){
  Node *root = *rightVine;
  int n = getNumNodes(root), m = pow(2, floor(log2(n+1)))- 1 ;

  compress( &root, n-m );
  
  while( m>1 ){
    m = floor( m/2 );
    compress( &root, m );
  }

  *rightVine = root;
}

void compress(Node **rootPtr, int times){
  int i;
 
  for(i=0; i<times; i++){
    _compress( &(*rootPtr), i );
  }  
}  

void _compress(Node **rootPtr, int times){
 
  if(times ==0)
    leftRotate(&(*rootPtr));
  else 
    _compress( &((*rootPtr)->right), times-1);  
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
 


