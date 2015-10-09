#include "TreeToVine.h"
#include "Node.h"
#include "Rotations.h"
#include <stdio.h>

void treeToRightVine(Node **tree){
  Node *root = *tree;
 
  if(root == NULL)
    return;
  
  while(root->left !=NULL){
    rightRotate(&root);
  }
  
  if(root->right != NULL){
    treeToRightVine(&(root->right));
  }
  
  *tree = root;
}
