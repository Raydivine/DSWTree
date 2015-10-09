#include "unity.h"
#include "CreateVine.h"
#include "Node.h"
#include "InitNode.h"
#include "CustomAssertion.h"
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


/**   Root->  2                 1
*            /                   \
*           1         ----->      2
*/
void test_createRightVine_given_root_leftChild_should_form_Vine(void){
  setNode(&node2, &node1, NULL, 'b');
  setNode(&node1, NULL, NULL, 'b');
  Node *root = &node2;
  
  createRightVine(&root);
  TEST_ASSERT_EQUAL_PTR(&node1, root);
  TEST_ASSERT_EQUAL_NODE(NULL, &node2, 'b', &node1);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node2);
}

/**   Root->  2                 
*              \                 
*               6         
*/
void test_createRightVine_given_root_is_rightVine_with_2_node_should_do_nothing(void){
  setNode(&node2, &node1, NULL, 'b');
  setNode(&node1, NULL, NULL, 'b');
  Node *root = &node2;
  
  createRightVine(&root);
  TEST_ASSERT_EQUAL_PTR(&node1, root);
  TEST_ASSERT_EQUAL_NODE(NULL, &node2, 'b', &node1);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node2);
}

/**   Root->  6                 5
*            / \                 \
*           5  8       ----->     6
*                                  \
*                                   8
*/
void test_createRightVine_given_root_bothChild_should_form_Vine(void){
  setNode(&node6, &node5, &node8, 'b');
  setNode(&node5, NULL, NULL, 'b');
  setNode(&node8, NULL, NULL, 'b');
  Node *root = &node6;
  
  createRightVine(&root);
  TEST_ASSERT_EQUAL_PTR(&node5, root);
  TEST_ASSERT_EQUAL_NODE(NULL, &node6, 'b', &node5);
  TEST_ASSERT_EQUAL_NODE(NULL, &node8, 'b', &node6);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node8);
}

/**   Root->  6                 5
*            / \                 \
*           5  8       ----->     6
*          /                              \
*         4                                 8
*/
void test_createRightVine_given_root_bothChild_should_return_3_and_form_Vine(void){
  setNode(&node6, &node5, &node8, 'b');
  setNode(&node5, NULL, NULL, 'b');
  setNode(&node8, NULL, NULL, 'b');
  Node *root = &node6;
  
  createRightVine(&root);
  TEST_ASSERT_EQUAL_PTR(&node5, root);
  TEST_ASSERT_EQUAL_NODE(NULL, &node6, 'b', &node5);
  TEST_ASSERT_EQUAL_NODE(NULL, &node8, 'b', &node6);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node8);
}