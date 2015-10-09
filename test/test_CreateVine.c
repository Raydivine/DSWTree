#include "unity.h"
#include "CreateVine.h"
#include "Node.h"
//#include "Rotations.h"

Node node1,node2,node3,node4 ,node5, node6, node7, node8, node9, node10, node15; //Share to all test

void setNode(Node *target, Node *left, Node *right, char color)	{
	target->left = left;
	target->right = right;
	target->color = color;
}

void resetNode(Node *target, int data)	{
	target->left = NULL;
	target->right = NULL;
	target->color = 'b';
	target->data = data;
}

/* Run reset before test*/
void setUp(void)	{
	resetNode(&node1, 1);
	resetNode(&node2, 2);
	resetNode(&node3, 3);
	resetNode(&node4, 4);
	resetNode(&node5, 5);
	resetNode(&node6, 6);
	resetNode(&node7, 7);
	resetNode(&node8, 8);
	resetNode(&node9, 9);
	resetNode(&node10, 10);
	resetNode(&node10, 15);
}

void tearDown(void){}

void test_createRightVine_given_NULL_should_return_0(void){
  
  
  
}
