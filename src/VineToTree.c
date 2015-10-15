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

void compress(Node **rootPtr, int times){
  Node *root = *rootPtr;
  int i;
  for(i=0; i<times; i++){
    leftRotate(&root);
    root = root->right;
  }
  
  *rootPtr = root;
}


