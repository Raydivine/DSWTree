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

// NULL
void test_rightVineToTree_given_Vine_is_NULL_should_do_nothing(void){
	Node *vine = NULL;
  
  rightVineToTree(&vine);
  TEST_ASSERT_NULL(vine);
}

// 1 
void test_rightVineToTree_given_Vine_has_1_node_should_do_nothing(void){
  setNode(&node1, NULL, NULL, 'b');
  Node *vine = &node1;

  rightVineToTree(&vine);
  TEST_ASSERT_EQUAL_PTR(&node1, vine);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
}

/**  1                      
*     \                 
*      2               
*/
void test_rightVineToTree_given_Vine_has_2_node_should_doNothing_because_already_balance(void){
  setNode(&node1, NULL, &node2, 'b');
  setNode(&node2, NULL, NULL, 'b');
  Node *vine = &node1;

  rightVineToTree(&vine);
  TEST_ASSERT_EQUAL_PTR(&node1, vine);
  TEST_ASSERT_EQUAL_NODE(NULL, &node2, 'b', &node1);
}

/** 1                          2
*    \                       /   \
*     2        ---->       1       3
*      \
*       3
*          
*/
void xtest_rightVineToTree_given_Vine_has_3_node_should_form_tree(void){
  setNode(&node1, NULL, &node2, 'b');
  setNode(&node2, NULL, &node3, 'b');
  setNode(&node3, NULL, NULL, 'b');
  Node *vine = &node1;

  rightVineToTree(&vine);
  TEST_ASSERT_EQUAL_PTR(&node2, vine);
  TEST_ASSERT_EQUAL_NODE(&node1, &node3, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node3);
}

/** 1                          2
*    \                       /   \
*     2        ---->       1       4
*      \                          /
*       3                        3
*        \                          
*         4   
*/
void xtest_rightVineToTree_given_Vine_has_4_node_should_form_tree(void){
  setNode(&node1, NULL, &node2, 'b');
  setNode(&node2, NULL, &node3, 'b');
  setNode(&node3, NULL, &node4, 'b');
  setNode(&node4, NULL, NULL, 'b');
  Node *vine = &node1;

  rightVineToTree(&vine);
  TEST_ASSERT_EQUAL_PTR(&node2, vine);
  TEST_ASSERT_EQUAL_NODE(&node1, &node4, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(&node3, NULL, 'b', &node4);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node3);
}



