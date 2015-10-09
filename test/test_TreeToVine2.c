#include "unity.h"
#include "TreeToVine.h"
#include "Node.h"
#include "InitNode.h"
#include "CustomAssertion.h"
#include "Rotations.h"

Node node1,node2,node3,node4 ,node5, node6, node7, node8, node9, node10, node11, node12, node13, node14, node15, node16, node17; //Share to all test

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
	resetNode(&node16, 16);
	resetNode(&node17, 17);
}

void tearDown(void){}


/**   Root->   9                       
*            /   \                       
*          6      14       ----->    1-2-6-8-9-11-14-15    
*         / \   /   \                      
*       2   8  11   15       
*      /               
*     1                                                                                                                               
*/
void test_treeToRightVine_given_root_got_8_node_should_form_RightVine(void){
  setNode(&node9, &node6, &node14, 'b');
  setNode(&node6, &node2, &node8, 'b');
  setNode(&node2, &node1, NULL, 'b');
  setNode(&node14, &node11, &node15, 'b');
  setNode(&node8, NULL, NULL, 'b');
  setNode(&node11, NULL, NULL, 'b');
  setNode(&node15, NULL, NULL, 'b');
  setNode(&node1, NULL, NULL, 'b');
  Node *root = &node9;
  
  treeToRightVine(&root);
  TEST_ASSERT_EQUAL_PTR(&node1, root);
  TEST_ASSERT_EQUAL_NODE(NULL, &node2, 'b', &node1);
  TEST_ASSERT_EQUAL_NODE(NULL, &node6, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, &node8, 'b', &node6);
  TEST_ASSERT_EQUAL_NODE(NULL, &node9, 'b', &node8);
  TEST_ASSERT_EQUAL_NODE(NULL, &node11, 'b', &node9);
  TEST_ASSERT_EQUAL_NODE(NULL, &node14, 'b', &node11);
  TEST_ASSERT_EQUAL_NODE(NULL, &node15, 'b', &node14);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node15);
}

/**   Root->   10                       
*            /    \                       
*          6       14       ----->    1-2-3-6-8-10-11-14-15    
*         / \     /   \                      
*       2    8  11   15       
*      / \              
*     1   3                                                                                                                              
*/
void test_treeToRightVine_given_root_got_9_node_should_form_RightVine(void){
  setNode(&node10, &node6, &node14, 'b');
  setNode(&node6, &node2, &node8, 'b');
  setNode(&node2, &node1, &node3, 'b');
  setNode(&node14, &node11, &node15, 'b');
  setNode(&node8, NULL, NULL, 'b');
  setNode(&node11, NULL, NULL, 'b');
  setNode(&node15, NULL, NULL, 'b');
  setNode(&node1, NULL, NULL, 'b');
  setNode(&node3, NULL, NULL, 'b');
  Node *root = &node10;
  
  treeToRightVine(&root);
  TEST_ASSERT_EQUAL_PTR(&node1, root);
  TEST_ASSERT_EQUAL_NODE(NULL, &node2, 'b', &node1);
  TEST_ASSERT_EQUAL_NODE(NULL, &node3, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, &node6, 'b', &node3);
  TEST_ASSERT_EQUAL_NODE(NULL, &node8, 'b', &node6);
  TEST_ASSERT_EQUAL_NODE(NULL, &node10, 'b', &node8);
  TEST_ASSERT_EQUAL_NODE(NULL, &node11, 'b', &node10);
  TEST_ASSERT_EQUAL_NODE(NULL, &node14, 'b', &node11);
  TEST_ASSERT_EQUAL_NODE(NULL, &node15, 'b', &node14);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node15);
}

/**   Root->   10                       
*            /    \                       
*          6       14       ----->    1-2-3-6-7-8-10-11-14-15    
*         / \     /   \                      
*      2     8  11   15       
*     / \   /           
*   1   3  7                                                                                                                            
*/
void test_treeToRightVine_given_root_got_10_node_should_form_RightVine(void){
  setNode(&node10, &node6, &node14, 'b');
  setNode(&node6, &node2, &node8, 'b');
  setNode(&node2, &node1, &node3, 'b');
  setNode(&node14, &node11, &node15, 'b');
  setNode(&node8, &node7, NULL, 'b');
  setNode(&node11, NULL, NULL, 'b');
  setNode(&node15, NULL, NULL, 'b');
  setNode(&node1, NULL, NULL, 'b');
  setNode(&node3, NULL, NULL, 'b');
  setNode(&node7, NULL, NULL, 'b');
  Node *root = &node10;
  
  treeToRightVine(&root);
  TEST_ASSERT_EQUAL_PTR(&node1, root);
  TEST_ASSERT_EQUAL_NODE(NULL, &node2, 'b', &node1);
  TEST_ASSERT_EQUAL_NODE(NULL, &node3, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, &node6, 'b', &node3);
  TEST_ASSERT_EQUAL_NODE(NULL, &node7, 'b', &node6);
  TEST_ASSERT_EQUAL_NODE(NULL, &node8, 'b', &node7);
  TEST_ASSERT_EQUAL_NODE(NULL, &node10, 'b', &node8);
  TEST_ASSERT_EQUAL_NODE(NULL, &node11, 'b', &node10);
  TEST_ASSERT_EQUAL_NODE(NULL, &node14, 'b', &node11);
  TEST_ASSERT_EQUAL_NODE(NULL, &node15, 'b', &node14);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node15);
}

/**   Root->   10                       
*            /    \                       
*          6       14       ----->    1-2-3-6-7-8-10-11-14-15-16-17    
*         / \     /   \                      
*      2     8  11    16       
*     / \   /        /  \    
*   1   3  7        15    17                                                                                                                 
*/
void test_treeToRightVine_given_root_got_12_node_should_form_RightVine(void){
  setNode(&node10, &node6, &node14, 'b');
  setNode(&node6, &node2, &node8, 'b');
  setNode(&node2, &node1, &node3, 'b');
  setNode(&node14, &node11, &node16, 'b');
  setNode(&node16, &node15, &node17, 'b');
  setNode(&node8, &node7, NULL, 'b');
  setNode(&node11, NULL, NULL, 'b');
  setNode(&node15, NULL, NULL, 'b');
  setNode(&node1, NULL, NULL, 'b');
  setNode(&node3, NULL, NULL, 'b');
  setNode(&node7, NULL, NULL, 'b');
  setNode(&node17, NULL, NULL, 'b');
  Node *root = &node10;
  
  treeToRightVine(&root);
  TEST_ASSERT_EQUAL_PTR(&node1, root);
  TEST_ASSERT_EQUAL_NODE(NULL, &node2, 'b', &node1);
  TEST_ASSERT_EQUAL_NODE(NULL, &node3, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, &node6, 'b', &node3);
  TEST_ASSERT_EQUAL_NODE(NULL, &node7, 'b', &node6);
  TEST_ASSERT_EQUAL_NODE(NULL, &node8, 'b', &node7);
  TEST_ASSERT_EQUAL_NODE(NULL, &node10, 'b', &node8);
  TEST_ASSERT_EQUAL_NODE(NULL, &node11, 'b', &node10);
  TEST_ASSERT_EQUAL_NODE(NULL, &node14, 'b', &node11);
  TEST_ASSERT_EQUAL_NODE(NULL, &node15, 'b', &node14);
  TEST_ASSERT_EQUAL_NODE(NULL, &node16, 'b', &node15);
  TEST_ASSERT_EQUAL_NODE(NULL, &node17, 'b', &node16);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node17);
}