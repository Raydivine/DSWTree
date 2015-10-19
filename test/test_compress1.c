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
	resetNode(&node15, 15);
}

void tearDown(void){}

/**
*   void compress(Node **rootPtr, int times)
* 
*   -compress a rightVine to by using leftRotation, how many times to do compress is denpend of the input "times".
*    It is a sub fuction of rightVineToTree(), so there is a input condition fixed by mother function.
*
*    Input condition:
*    1)**rootPtr : has to be a rightVine Form.
*    2)    times : is set by the mother function, the value must be smaller then length of rightVine.
*
*   Test Term: (c) means  compress , doing rightRotation
*/


/**     compress 1 times   
*                        1st time                      
*     2(c)                   4                    
*    / \                   /  \       
*   1   4        ---->   2     6       
*      / \              /\    / \                       
*     3   6            1  3  5   8                    
*        / \                    / \                        
*       5   8                  7  10                                  
*          / \                   /  \                         
*         7  10                 9   15                        
*           /  \                  
*          9   15
*
*/
void xtest_compress_given_Vine_leftChilds_compress_1_times_should_change(void){
  setNode(&node2, &node1, &node4, 'b');
  setNode(&node4, &node3, &node6, 'b');
  setNode(&node6, &node5, &node8, 'b');
  setNode(&node8, &node7, &node10, 'b');
  setNode(&node10, &node9, &node15, 'b');
  setNode(&node1, NULL, NULL, 'b');
  setNode(&node3, NULL, NULL, 'b');
  setNode(&node5, NULL, NULL, 'b');
  setNode(&node7, NULL, NULL, 'b');
  setNode(&node9, NULL, NULL, 'b');
  setNode(&node15, NULL, NULL, 'b');
  Node *vine = &node2;

  compress(&vine, 1);
  TEST_ASSERT_EQUAL_PTR(&node4, vine);
  TEST_ASSERT_EQUAL_NODE(&node2, &node6, 'b', &node4);
  TEST_ASSERT_EQUAL_NODE(&node1, &node3, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(&node5, &node8, 'b', &node6);
  TEST_ASSERT_EQUAL_NODE(&node7, &node10, 'b', &node8);
  TEST_ASSERT_EQUAL_NODE(&node9, &node15, 'b', &node10);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node3);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node5);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node7);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node9);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node15);
}

/**     compress 2 times   
*                        1st time               2nd time                
*     2(c)                   4                       4  
*    / \                   /  \                    /  \
*   1   4        ---->   2     6(c)   ---->       2     8
*      / \              /\    / \                / \   /  \       
*     3   6(c)         1  3  5   8              1  3  6     10        
*        / \                    / \                  / \   /  \  
*       5   8                  7  10                5   7  9  15             
*          / \                   /  \                         
*         7  10                 9   15                        
*           /  \                  
*          9   15
*
*/
void test_compress_given_Vine_leftChilds_compress_2_times_should_change(void){
  setNode(&node2, &node1, &node4, 'b');
  setNode(&node4, &node3, &node6, 'b');
  setNode(&node6, &node5, &node8, 'b');
  setNode(&node8, &node7, &node10, 'b');
  setNode(&node10, &node9, &node15, 'b');
  setNode(&node1, NULL, NULL, 'b');
  setNode(&node3, NULL, NULL, 'b');
  setNode(&node5, NULL, NULL, 'b');
  setNode(&node7, NULL, NULL, 'b');
  setNode(&node9, NULL, NULL, 'b');
  setNode(&node15, NULL, NULL, 'b');
  Node *vine = &node2;

  compress(&vine, 2);
  // printVine(vine);
  TEST_ASSERT_EQUAL_PTR(&node4, vine);
  TEST_ASSERT_EQUAL_NODE(&node2, &node6, 'b', &node4);
  TEST_ASSERT_EQUAL_NODE(&node1, &node3, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(&node6, &node10, 'b', &node8);
  TEST_ASSERT_EQUAL_NODE(&node5, &node7, 'b', &node6);
  TEST_ASSERT_EQUAL_NODE(&node9, &node15, 'b', &node10);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node3);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node5);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node7);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node9);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node15);
}





