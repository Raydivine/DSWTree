#include "TreeToVine.h"
#include "Node.h"
#include "Rotations.h"
#include <stdio.h>

void treeToRightVine(Node **rootPtr){
  Node *root = *rootPtr;
 
  if(root == NULL)
    return;
  
  while(root->left !=NULL){
    rightRotate(&root);
  }
  
  if(root->right != NULL){
    treeToRightVine(&(root->right));
  }
  
  *rootPtr = root;
}
