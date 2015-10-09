#include "VineToTree.h"
#include "Node.h"
#include "Rotations.h"
#include "GetNumNodes.h"
#include <math.h>
#include <stdio.h>

void rightVineToTree(Node **rightVine){
  Node *root = *rightVine;
  double x = log2( getNumNodes(root)) ;
  int i, time = round(x)-1;

  for(i=0; i<time; i++){
    leftRotate(&root);
    
    if( root->right->right )
      leftRotate( &(root->right)) ;
  }
  
  *rightVine = root;
}



