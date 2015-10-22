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


/**     compress 0 times                                       
*   1                                  
*    \               
*     2             
*      \                                          
*       3                                       
*        \                                           
*         4                                                      
*          \                                              
*           5                                             
*            \                  
*             6
*              \
*               7
*
*/
void test_compress_given_Vine_has_7_node_and_compress_0_times_should_no_compress(void){
  setNode(&node1, NULL, &node2, 'b');
  setNode(&node2, NULL, &node3, 'b');
  setNode(&node3, NULL, &node4, 'b');
  setNode(&node4, NULL, &node5, 'b');
  setNode(&node5, NULL, &node6, 'b');
  setNode(&node6, NULL, &node7, 'b');
  setNode(&node7, NULL, NULL, 'b');
  Node *vine = &node1;
  
  compress(&vine, 0);
  TEST_ASSERT_EQUAL_PTR(&node1, vine);
  TEST_ASSERT_EQUAL_NODE(NULL, &node3, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, &node4, 'b', &node3);
  TEST_ASSERT_EQUAL_NODE(NULL, &node5, 'b', &node4);
  TEST_ASSERT_EQUAL_NODE(NULL, &node6, 'b', &node5);
  TEST_ASSERT_EQUAL_NODE(NULL, &node7, 'b', &node6);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node7);
}

/**     compress 1 times   
*                    1st time                      
*   1(c)                  2                    
*    \                  /  \       
*     2        ---->   1    3       
*      \                     \                       
*       3                     4                    
*        \                     \                        
*         4                     5                                  
*          \                     \                         
*           5                     7                         
*            \                  
*             6
*              \
*               7
*
*/
void test_compress_given_Vine_has_7_node_and_compress_1_times_should_change(void){
  setNode(&node1, NULL, &node2, 'b');
  setNode(&node2, NULL, &node3, 'b');
  setNode(&node3, NULL, &node4, 'b');
  setNode(&node4, NULL, &node5, 'b');
  setNode(&node5, NULL, &node6, 'b');
  setNode(&node6, NULL, &node7, 'b');
  setNode(&node7, NULL, NULL, 'b');
  Node *vine = &node1;

  compress(&vine, 1);
  TEST_ASSERT_EQUAL_PTR(&node2, vine);
  TEST_ASSERT_EQUAL_NODE(&node1, &node3, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, &node4, 'b', &node3);
  TEST_ASSERT_EQUAL_NODE(NULL, &node5, 'b', &node4);
  TEST_ASSERT_EQUAL_NODE(NULL, &node6, 'b', &node5);
  TEST_ASSERT_EQUAL_NODE(NULL, &node7, 'b', &node6);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node7);
}

/**   compress 2 times     
*                     1st time                2nd time 
*   1(c)                  2                       2              
*    \                   /  \                   /   \      
*     2        ---->    1    3(c)        ----> 1      4    
*      \                      \                      / \                 
*       3(c)                   4                    3   5                
*        \                      \                        \                           
*         4                      5                        6                                   
*          \                      \                        \
*           5                     7                         7
*            \                  
*             6
*              \
*               7
*
*/
void test_compress_given_Vine_has_7_node_and_compress_2_times_should_change(void){
  setNode(&node1, NULL, &node2, 'b');
  setNode(&node2, NULL, &node3, 'b');
  setNode(&node3, NULL, &node4, 'b');
  setNode(&node4, NULL, &node5, 'b');
  setNode(&node5, NULL, &node6, 'b');
  setNode(&node6, NULL, &node7, 'b');
  setNode(&node7, NULL, NULL, 'b');
  Node *vine = &node1;

  compress(&vine,2);
  TEST_ASSERT_EQUAL_PTR(&node2, vine);
  TEST_ASSERT_EQUAL_NODE(&node1, &node4, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(&node3, &node5, 'b', &node4);
  TEST_ASSERT_EQUAL_NODE(NULL, &node6, 'b', &node5);
  TEST_ASSERT_EQUAL_NODE(NULL, &node7, 'b', &node6);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node7);
}

/**  compress 3 times  
*                       1st time                2nd time                  3rd time 
*   1(c)                   2                      2                       2
*    \                   /  \                   /   \                   /   \
*     2        ---->    1    3(c)        ----> 1      4       --->     1     4
*      \                      \                      / \                    / \         
*       3(c)                   4                    3   5(c)               3   6  
*        \                      \                        \                    / \           
*         4                      5(c)                     6                  5   7                      
*          \                      \                        \
*           5(c)                   6                        7
*            \                      \             
*             6                      7
*              \
*               7
*
*/
void test_compress_given_Vine_has_7_node_and_compress_3_times_should_change(void){
  setNode(&node1, NULL, &node2, 'b');
  setNode(&node2, NULL, &node3, 'b');
  setNode(&node3, NULL, &node4, 'b');
  setNode(&node4, NULL, &node5, 'b');
  setNode(&node5, NULL, &node6, 'b');
  setNode(&node6, NULL, &node7, 'b');
  setNode(&node7, NULL, NULL, 'b');
  Node *vine = &node1;

  compress(&vine,3);
  TEST_ASSERT_EQUAL_PTR(&node2, vine);
  TEST_ASSERT_EQUAL_NODE(&node1, &node4, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(&node3, &node6, 'b', &node4);
  TEST_ASSERT_EQUAL_NODE(&node5, &node7, 'b', &node6);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node3);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node5);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node7);
}


/**  compress 4 times  
*                       1st time                2nd time                  3rd time          4th time 
*   1(c)                   2                      2                       2                    2
*    \                   /  \                   /   \                   /   \                 / \
*     2        ---->    1    3(c)        ----> 1      4       --->     1     4      --->     1   4
*      \                      \                      / \                    / \                 / \ 
*       3(c)                   4                    3   5(c)               3   6               3   6
*        \                      \                        \                    / \                 / \
*         4                      5(c)                     6                  5   7(c)            5   8         
*          \                      \                        \                      \                 /
*           5(c)                   6                       7(c)                    8               7
*            \                      \                       \ 
*             6                      7(c)                    8
*              \                      \
*               7(c)                   8
*                \
*                 8
*/
void test_compress_given_Vine_has_8_node_and_compress_4_times_should_change(void){
  setNode(&node1, NULL, &node2, 'b');
  setNode(&node2, NULL, &node3, 'b');
  setNode(&node3, NULL, &node4, 'b');
  setNode(&node4, NULL, &node5, 'b');
  setNode(&node5, NULL, &node6, 'b');
  setNode(&node6, NULL, &node7, 'b');
  setNode(&node7, NULL, &node8, 'b');
  setNode(&node8, NULL, NULL, 'b');
  Node *vine = &node1;

  compress(&vine,4);
  TEST_ASSERT_EQUAL_PTR(&node2, vine);
  TEST_ASSERT_EQUAL_NODE(&node1, &node4, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(&node3, &node6, 'b', &node4);
  TEST_ASSERT_EQUAL_NODE(&node5, &node8, 'b', &node6);
  TEST_ASSERT_EQUAL_NODE(&node7, NULL, 'b', &node8);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node3);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node5);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node7);
}



