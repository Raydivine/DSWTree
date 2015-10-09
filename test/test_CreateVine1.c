#include "unity.h"
#include "CreateVine.h"
#include "Node.h"
#include "InitNode.h"
#include "CustomAssertion.h"
#include "Rotations.h"

Node node1,node2,node3,node4 ,node5, node6, node7, node8, node9, node10, node11, node12, node13, node14, node15; //Share to all test

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
	resetNode(&node11, 11);
	resetNode(&node12, 12);
	resetNode(&node13, 13);
	resetNode(&node14, 14);
	resetNode(&node15, 15);
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

/**   Root->  9                       2
*            / \                       \
*           6   14       ----->         6
*          /                             \
*         2                               9
*                                          \               
*                                           14
*/
void test_createRightVine_given_root_is_unBalance_with_4_node_should_form_RightVine(void){
  setNode(&node9, &node6, &node14, 'b');
  setNode(&node6, &node2, NULL, 'b');
  setNode(&node2, NULL, NULL, 'b');
  setNode(&node14, NULL, NULL, 'b');
  Node *root = &node9;
  
  createRightVine(&root);
  TEST_ASSERT_EQUAL_PTR(&node2, root);
  TEST_ASSERT_EQUAL_NODE(NULL, &node6, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, &node9, 'b', &node6);
  TEST_ASSERT_EQUAL_NODE(NULL, &node14, 'b', &node9);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node14);
}

/**   Root->  9                       
*            / \                       
*           6   14       ----->    2-6-8-9-14    
*          / \                           
*         2  8                           
*                                                                                                                                  
*/
void test_createRightVine_given_root_is_unBalance_with_5_node_should_form_RightVine(void){
  setNode(&node9, &node6, &node14, 'b');
  setNode(&node6, &node2, &node8, 'b');
  setNode(&node2, NULL, NULL, 'b');
  setNode(&node14, NULL, NULL, 'b');
  setNode(&node8, NULL, NULL, 'b');
  Node *root = &node9;
  
  createRightVine(&root);
  TEST_ASSERT_EQUAL_PTR(&node2, root);
  TEST_ASSERT_EQUAL_NODE(NULL, &node6, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, &node8, 'b', &node6);
  TEST_ASSERT_EQUAL_NODE(NULL, &node9, 'b', &node8);
  TEST_ASSERT_EQUAL_NODE(NULL, &node14, 'b', &node9);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node14);
}

/**   Root->   9                       
*            /   \                       
*          6     14       ----->    2-6-8-9-11-14    
*         / \   /                         
*       2   8  11                         
*                                                                                                                                  
*/
void test_createRightVine_given_root_got_6_node_should_form_RightVine(void){
  setNode(&node9, &node6, &node14, 'b');
  setNode(&node6, &node2, &node8, 'b');
  setNode(&node2, NULL, NULL, 'b');
  setNode(&node14, &node11, NULL, 'b');
  setNode(&node8, NULL, NULL, 'b');
  setNode(&node11, NULL, NULL, 'b');
  Node *root = &node9;
  
  createRightVine(&root);
  TEST_ASSERT_EQUAL_PTR(&node2, root);
  TEST_ASSERT_EQUAL_NODE(NULL, &node6, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, &node8, 'b', &node6);
  TEST_ASSERT_EQUAL_NODE(NULL, &node9, 'b', &node8);
  TEST_ASSERT_EQUAL_NODE(NULL, &node11, 'b', &node9);
  TEST_ASSERT_EQUAL_NODE(NULL, &node14, 'b', &node11);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node14);
}

