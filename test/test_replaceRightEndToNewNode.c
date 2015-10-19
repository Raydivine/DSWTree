#include "unity.h"
#include "VineToTree.h"
#include "Node.h"
#include "InitNode.h"
#include "CustomAssertion.h"
#include "GetNumNodes.h"
#include "Rotations.h"

Node node1,node2,node3,node4 ,node5, node6, node7, node8, node9, node10, node15; //Share to all test

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

/**  
  void replaceRightEndToNewNode(Node **rootPtr, Node *newNode)
  
  This function find the rightEnd  of **rootPtr, then replace it to *newNode.
  It is use to suppport void compress(), because void compress() got the issue of disconnection between root and complte rightChild.
  
  Test Term: RE means the rightEnd
*/

/** replace 10 to rightEnd 
*
*    NULL      ---->   10  
*
*/
void test_replaceRightEndToNewNode_given_root_is_NULL_should_add(void){
 
  setNode(&node10, NULL, NULL, 'b');
  
  Node *root = NULL;
  replaceRightEndToNewNode(&root, &node10);
  TEST_ASSERT_EQUAL_PTR(&node10, root);
}

/** replace 10 to rightEnd 
*
*   2(RE)      ---->   10  
*
*/
void test_replaceRightEndToNewNode_given_root_is_rightEnd_should_replace(void){
 
  setNode(&node2, NULL, NULL, 'b');
  setNode(&node10, NULL, NULL, 'b');
  
  Node *root = &node2;
  replaceRightEndToNewNode(&root, &node10);
  TEST_ASSERT_EQUAL_PTR(&node10, root);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node10);
}

/** replace 10 to rightEnd 
*
*    2(RE)      ---->     10  
*   /                   
*  1                      ( 1 is gone because 10 doest not has child, so entire root is replaced with no child left)
*/
void test_replaceRightEndToNewNode_given_root_has_leftChild_but_is_rightEnd_should_replace(void){
 
  setNode(&node2, &node1, NULL, 'b');
  setNode(&node10, NULL, NULL, 'b');
  setNode(&node1, NULL, NULL, 'b');
  
  Node *root = &node2;
  replaceRightEndToNewNode(&root, &node10);
  TEST_ASSERT_EQUAL_PTR(&node10, root);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node10);
}

/** replace 10 to rightEnd 
*
*    2      ---->    2 
*   / \             / \
*  1   3(RE)       1   10
*
*/
void test_replaceRightEndToNewNode_given_rightEnd_is_3_should_replace(void){
 
  setNode(&node2, &node1, &node3, 'b');
  setNode(&node1, NULL, NULL, 'b');
  setNode(&node3, NULL, NULL, 'b');
  setNode(&node10, NULL, NULL, 'b');
  
  Node *root = &node2;
  replaceRightEndToNewNode(&root, &node10);
  TEST_ASSERT_EQUAL_PTR(&node2, root);
  TEST_ASSERT_EQUAL_NODE(&node1, &node10, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node10);
}

/** replace 10 to rightEnd 
*
*    2      ---->    2 
*   / \             / \
*  1   4           1   4
*     /  \            /  \
*    3   5(RE)       3    10
*
*/
void test_replaceRightEndToNewNode_given_rightEnd_is_5_should_replace(void){
 
  setNode(&node2, &node1, &node4, 'b');
  setNode(&node4, &node3, &node10, 'b');
  setNode(&node1, NULL, NULL, 'b');
  setNode(&node3, NULL, NULL, 'b');
  setNode(&node10, NULL, NULL, 'b');
  
  Node *root = &node2;
  replaceRightEndToNewNode(&root, &node10);
  TEST_ASSERT_EQUAL_PTR(&node2, root);
  TEST_ASSERT_EQUAL_NODE(&node1, &node4, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(&node3, &node10, 'b', &node4);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node3);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node10);
}

/** replace 10 to rightEnd 
*
*    2      ---->    2 
*   / \             / \
*  1   4           1   4
*     /  \            /  \
*    3    5          3    5
*          \                \
*           6(RE)            10
*/
void test_replaceRightEndToNewNode_given_rightEnd_is_6_should_replace(void){
 
  setNode(&node2, &node1, &node4, 'b');
  setNode(&node4, &node3, &node5, 'b');
  setNode(&node5, NULL, &node6, 'b');
  setNode(&node1, NULL, NULL, 'b');
  setNode(&node3, NULL, NULL, 'b');
  setNode(&node6, NULL, NULL, 'b');
  setNode(&node10, NULL, NULL, 'b');
  
  Node *root = &node2;
  replaceRightEndToNewNode(&root, &node10);
  TEST_ASSERT_EQUAL_PTR(&node2, root);
  TEST_ASSERT_EQUAL_NODE(&node1, &node4, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(&node3, &node5, 'b', &node4);
  TEST_ASSERT_EQUAL_NODE(NULL, &node10, 'b', &node5);
}


