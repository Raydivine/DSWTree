#include "unity.h"
#include "TreeToVine.h"
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
	resetNode(&node15, 15);
}

void tearDown(void){}

// THE TESTS BELOW IS THE CASES WHILE treeToRightVine() TAKE NO ACTION

/**   Root-> NULL
*
*/
void test_treeToRightVine_given_NULL_should_do_nothing(void){
  Node *root = NULL;

  treeToRightVine(&root);
  TEST_ASSERT_NULL(root);
}

/**   Root->  1
*
*/
void test_treeToRightVine_given_root_no_child_should_do_nothing(void){
  setNode(&node1, NULL, NULL, 'b');
  Node *root = &node1;
  
  treeToRightVine(&root);
  TEST_ASSERT_EQUAL_PTR(&node1, root);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
}

/**   Root->  2                 
*              \                 
*               6         
*/
void test_treeToRightVine_given_root_is_rightVine_with_2_node_should_do_nothing(void){
  setNode(&node2, NULL, &node6, 'b');
  setNode(&node6, NULL, NULL, 'b');
  Node *root = &node2;
  
  treeToRightVine(&root);
  TEST_ASSERT_EQUAL_PTR(&node2, root);
  TEST_ASSERT_EQUAL_NODE(NULL, &node6, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node6);
}

/**   Root->  2                 
*              \                 
*               6  
*                \       
*                 8
*/
void test_treeToRightVine_given_root_is_rightVine_with_3_node_should_do_nothing(void){
  setNode(&node2, NULL, &node6, 'b');
  setNode(&node6, NULL, &node8, 'b');
  setNode(&node8, NULL, NULL, 'b');
  Node *root = &node2;
  
  treeToRightVine(&root);
  TEST_ASSERT_EQUAL_PTR(&node2, root);
  TEST_ASSERT_EQUAL_NODE(NULL, &node6, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, &node8, 'b', &node6);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node8);
}
