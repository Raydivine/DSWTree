#ifndef VineToTree_H
#define VineToTree_H
#include "Node.h"

void rightVineToTree(Node **rightVine);
void compress(Node **rootPtr, int times);
void replaceRightEndToNewNode(Node **rootPtr, Node *newNode);

#endif // VineToTree_H
