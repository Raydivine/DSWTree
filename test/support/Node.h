#ifndef Node_H
#define Node_H

typedef struct Node Node;

struct Node {
  int data;
  char color;		// 'b' or 'r' (black or red)
	Node *left;
	Node *right;
};

#endif // Node_H