#include "unity.h"
#include "CreateVine.h"
#include "Node.h"
#include "InitNode.h"
#include "CustomAssertion.h"
//#include "Rotations.h"

Node node1,node2,node3,node4 ,node5, node6, node7, node8, node9, node10, node15; //Share to all test

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

/**   Root-> NULL
*
*  return 0
*/
void test_createRightVine_given_NULL_should_return_0(void){

  int ans = createRightVine(NULL);
  TEST_ASSERT_EQUAL(ans, 0);
}

/**   Root->  1
*
*  return 1
*/
void test_createRightVine_given_1_no_child_should_return_1(void){
  setNode(&node1, NULL, NULL, 'b');
  Node *root = &node1;
  
  int ans = createRightVine(&root);
  TEST_ASSERT_EQUAL(ans, 1);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
}

/**   Root->  2                 1
*            /                   \
*           1         ----->      2
*
*  return 1
*/
void test_createRightVine_given_2_leftChild_1_should_return_2_and_form_Vine(void){
  setNode(&node2, &node1, NULL, 'b');
  setNode(&node1, NULL, NULL, 'b');
  Node *root = &node2;
  
  // int ans = createRightVine(&node1);
  // TEST_ASSERT_EQUAL(ans, 1);
}
