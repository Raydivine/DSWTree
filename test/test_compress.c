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


/**                                           
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
void xtest_compress_given_Vine_has_7_node_and_compress_0_times_should_no_compress(void){
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

/**                     1st time                      
*   1                    2                    
*    \         LR(root) /  \       
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
void xtest_compress_given_Vine_has_7_node_and_compress_1_times_should_change(void){
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

/**                    1st time                2nd time 
*   1                      2                      2              
*    \                   /  \                   /   \      
*     2        ---->    1    3       ---->     1      4    
*      \                      \                      / \                 
*       3                      4                    3   5                
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
  printf("%d\n",(node2.right)->data);
  TEST_ASSERT_EQUAL_PTR(&node2, vine);
  TEST_ASSERT_EQUAL_NODE(&node1, &node4, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(&node3, &node5, 'b', &node4);
  TEST_ASSERT_EQUAL_NODE(NULL, &node6, 'b', &node5);
  TEST_ASSERT_EQUAL_NODE(NULL, &node7, 'b', &node6);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node7);
}


/**                                             1st time                                             2nd time  
*   1                    2                       2                            4                         4
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
void xtest_compress_given_Vine_has_99_node_and_compress_1_times_should_change(void){
  setNode(&node1, NULL, &node2, 'b');
  setNode(&node2, NULL, &node3, 'b');
  setNode(&node3, NULL, &node4, 'b');
  setNode(&node4, NULL, &node5, 'b');
  setNode(&node5, NULL, &node6, 'b');
  setNode(&node6, NULL, &node7, 'b');
  setNode(&node7, NULL, NULL, 'b');
  Node *vine = &node1;

 // compress(&vine,0);
  TEST_ASSERT_EQUAL_PTR(&node1, vine);
  TEST_ASSERT_EQUAL_NODE(NULL, &node2, 'b', &node1);
  TEST_ASSERT_EQUAL_NODE(NULL, &node3, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, &node4, 'b', &node3);
  TEST_ASSERT_EQUAL_NODE(NULL, &node5, 'b', &node4);
  TEST_ASSERT_EQUAL_NODE(NULL, &node6, 'b', &node5);
  TEST_ASSERT_EQUAL_NODE(NULL, &node7, 'b', &node6);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node7);
}



