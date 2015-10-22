#include "DSW.h"
#include "Node.h"
#include "TreeToVine.h"
#include "VineToTree.h"
#include <stdio.h>

void dswTreeBalancing(Node **rootPtr){
  Node *root = *rootPtr;
  
  treeToRightVine(&root);
  rightVineToTree(&root);
  
  *rootPtr = root;
}