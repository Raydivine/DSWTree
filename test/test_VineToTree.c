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

// Test Termv: LR(root)  = leftRotate(root),  LR(rChild) = LeftRotate(rigthChild)


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
void xtest_rightVineToTree_given_Vine_has_2_node_should_do_nothing_becuz_it_is_balance(void){
  setNode(&node1, NULL, &node2, 'b');
  setNode(&node2, NULL, NULL, 'b');
  Node *vine = &node1;

  rightVineToTree(&vine);
  TEST_ASSERT_EQUAL_PTR(&node1, vine);
  TEST_ASSERT_EQUAL_NODE(NULL, &node2, 'b', &node1);
}

/** 1                                 2
*    \       LR(root)               /   \
*     2        ---->              1       3
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

/** 1                         2                              2
*    \         LR(root)     /   \          LR(rChild)     /    \
*     2        ---->       1     3          ---->       1       4 
*      \                          \                            /
*       3                         4                           3
*        \                          
*         4   
*/
void xtest_rightVineToTree_given_Vine_has_4_node_should_form_tree_and_left_Rotate_rightChild(void){
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

/** 1                     2                       2
*    \        LR(root)  /  \        LR(rChild)  /   \
*     2        ---->   1    3       ---->     1       4
*      \                     \                       / \
*       3                     4                     3   5
*        \                     \     
*         4                     5
*          \
*           5
*
*/
void xtest_rightVineToTree_given_Vine_has_5_node_should_form_tree(void){
  setNode(&node1, NULL, &node2, 'b');
  setNode(&node2, NULL, &node3, 'b');
  setNode(&node3, NULL, &node4, 'b');
  setNode(&node4, NULL, &node5, 'b');
  setNode(&node5, NULL, NULL, 'b');
  Node *vine = &node1;

  rightVineToTree(&vine);
  TEST_ASSERT_EQUAL_PTR(&node2, vine);
  TEST_ASSERT_EQUAL_NODE(&node1, &node4, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(&node3, &node5, 'b', &node4);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node3);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node5);
}

/**                                             1st time                                             2nd time  
*    1                    2                       2                            4                        4
*    \         LR(root) /  \        LR(rChild)  /   \       LR(root)         /  \      LR(rChild)     /   \  
*     2        ---->   1    3       ---->     1       4     ----->          2     5    ----->        2      6
*      \                     \                       / \                  /  \     \                / \    /
*       3                     4                     3   5                1   3      6              1   3   5
*        \                     \                         \
*         4                     5                         6
*          \
*           5
*            \
*             6
*/
void xtest_rightVineToTree_given_Vine_has_6_node_should_form_tree_and_do_step_2times(void){
  setNode(&node1, NULL, &node2, 'b');
  setNode(&node2, NULL, &node3, 'b');
  setNode(&node3, NULL, &node4, 'b');
  setNode(&node4, NULL, &node5, 'b');
  setNode(&node5, NULL, &node6, 'b');
  setNode(&node6, NULL, NULL, 'b');
  Node *vine = &node1;

  rightVineToTree(&vine);
  TEST_ASSERT_EQUAL_PTR(&node4, vine);
  TEST_ASSERT_EQUAL_NODE(&node2, &node6, 'b', &node4);
  TEST_ASSERT_EQUAL_NODE(&node1, &node3, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(&node5, NULL , 'b', &node6);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node3);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node5);
}

/**                                             1st time                                             2nd time  
*    1                    2                       2                            4                        4
*    \         LR(root) /  \        LR(rChild)  /   \       LR(root)         /  \      LR(rChild)     /   \  
*     2        ---->   1    3       ---->     1       4     ----->          2     5    ----->        2      6
*      \                     \                       / \                  /  \     \                / \    / \
*       3                     4                     3   5                1   3      6              1   3  5   7 
*        \                     \                         \                           \
*         4                     5                         6                           7            
*          \                     \                         \
*           5                     7                         7
*            \                  
*             6
*              \
*               7
*
*/
void xtest_rightVineToTree_given_Vine_has_7_node_should_form_tree_and_do_step_2times(void){
  setNode(&node1, NULL, &node2, 'b');
  setNode(&node2, NULL, &node3, 'b');
  setNode(&node3, NULL, &node4, 'b');
  setNode(&node4, NULL, &node5, 'b');
  setNode(&node5, NULL, &node6, 'b');
  setNode(&node6, NULL, &node7, 'b');
  setNode(&node7, NULL, NULL, 'b');
  Node *vine = &node1;

  rightVineToTree(&vine);
  TEST_ASSERT_EQUAL_PTR(&node4, vine);
  TEST_ASSERT_EQUAL_NODE(&node2, &node6, 'b', &node4);
  TEST_ASSERT_EQUAL_NODE(&node1, &node3, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(&node5, &node7 , 'b', &node6);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node3);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node5);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node7);
}



