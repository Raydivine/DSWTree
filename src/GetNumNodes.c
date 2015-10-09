#include "GetNumNodes.h"
#include "Node.h"
#include <stdio.h>

int getNumNodes(Node *vine){
  int count =0;
  
  while( vine != NULL){
    count ++;
    vine = vine->right; 
  }
  
  return count; 
}
