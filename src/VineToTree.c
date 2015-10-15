#include "VineToTree.h"
#include "Node.h"
#include "Rotations.h"
#include "GetNumNodes.h"
#include <math.h>
#include <stdio.h>

void rightVineToTree(Node **rightVine){
  Node *root = *rightVine;
  int i, j , num = getNumNodes(root), time = (int)log2(num);

  for(i=0; i<time; i++){
    leftRotate(&root);
    
    for(j=0; j<(num/2-1); j++)
      leftRotate( &(root->right)) ;
  }
  
  *rightVine = root;
}



