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
void test_createRightVine_given_root_is_leftVine_with_2_node_should_form_RightVine(void){
  setNode(&node2, &node1, NULL, 'b');
  setNode(&node1, NULL, NULL, 'b');
  Node *root = &node2;
  
  createRightVine(&root);
  TEST_ASSERT_EQUAL_PTR(&node1, root);
  TEST_ASSERT_EQUAL_NODE(NULL, &node2, 'b', &node1);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node2);
}

/**   Root->  9                 2
*            /                   \
*           6         ----->      6
*          /                       \
*         2                         9
*
*/
void test_createRightVine_given_root_is_leftVine_with_3_node_should_form_RightVine(void){
  setNode(&node9, &node6, NULL, 'b');
  setNode(&node6, &node2, NULL, 'b');
  setNode(&node2, NULL, NULL, 'b');
  Node *root = &node9;
  
  createRightVine(&root);
  TEST_ASSERT_EQUAL_PTR(&node2, root);
  TEST_ASSERT_EQUAL_NODE(NULL, &node6, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, &node9, 'b', &node6);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node9);
}

/**   Root->  9                 2
*            /                   \
*           6         ----->      6
*          /                       \
*         2                         9
*
*/
void test_createRightVine_given_root_is_unBalance_with_4_node_should_form_RightVine(void){
  setNode(&node9, &node6, NULL, 'b');
  setNode(&node6, &node2, NULL, 'b');
  setNode(&node2, NULL, NULL, 'b');
  Node *root = &node9;
  
  createRightVine(&root);
  TEST_ASSERT_EQUAL_PTR(&node2, root);
  TEST_ASSERT_EQUAL_NODE(NULL, &node6, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, &node9, 'b', &node6);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node9);
}

