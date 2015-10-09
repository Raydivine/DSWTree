#include "VineToTree.h"
#include "Node.h"
#include "Rotations.h"
#include "GetNumNodes.h"
#include <math.h>
#include <stdio.h>

void rightVineToTree(Node **rightVine){
  double num, time;
  int i, j;
  Node *root = *rightVine;
  num = getNumNodes(root);
  time = log2(num) - 1;
  
  for( i=0 ; i<time ; i++){
    leftRotate(&root);
  }
  
  *rightVine = root;
}
