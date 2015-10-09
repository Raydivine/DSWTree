#include "CreateVine.h"
#include "Node.h"
#include "Rotations.h"
#include <stdio.h>

void createRightVine(Node **rootPtr){
  Node *root = *rootPtr;
 
  if(root == NULL)
    return;
  
  while(root->left !=NULL){
    rightRotate(&root);
  }
  
  if(root->right != NULL){
    createRightVine(&(root->right));
  }
  
  *rootPtr = root;
}
