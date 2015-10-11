#ifndef VineToTree_H
#define VineToTree_H
#include "Node.h"

void rightVineToTree(Node **rightVine);
void compress(Node **rootPtr, int times);
void chooseNodeToRotate(Node *root, int times);
//Node *compress(Node **rootPtr, int times);


#endif // VineToTree_H
