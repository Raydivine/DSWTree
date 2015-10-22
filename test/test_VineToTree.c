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

/**    void rightVineToTree(Node **rightVine)
*      
*      Convert the in-order list to a balanced tree, it has a sub function call compress(), 
*      which is doing leftRotation (compression) from top to Bottom.
*      The process to do compress() is follow the DSW algorithm solution
*      This function reference is taking from this site
*      http://courses.cs.vt.edu/cs2604/spring05/mcpherson/note/BalancingTrees.pdf
*      which locate at page 7 , under createPerfectTree()
*
*      The functions will first generate a 2 parameter , which are n and m
*      n = number of nodes of the vine ,  m = pow(2, floor(log2(n+1)))- 1  
*   
* ----------------------------------------------
*       compress( &root, n-m );    // First stage
*
*     while( m>1 ){
*       m = floor( m/2 );
*       compress( &root, m );     // Second stage
*     }
*--------------------------------------
*
*     the functions got 2 stage of compress, 
*     first stage is compres(n-m) time from top to bottom
*     Second stage is while m big than 1 , then  m divide by 2 , keep doing  compress(m) times, until m is not equal or smaller then one.
*
* TEST TERM
*
*  First compress : c1(n-m)
*
* Second compress : c2(m) , where m = m /2  while m >1 
*
*  leftRotation  :  R  
*/


// NULL
void test_rightVineToTree_given_Vine_is_NULL_should_do_nothing(void){
	Node *vine = NULL;
  
  rightVineToTree(&vine);
  TEST_ASSERT_NULL(vine);
}

/**  n = 1,     m = 2^[Floor(log2 (1+1))] - 1 
*                 = 1
*
*   1 
*/
void test_rightVineToTree_given_Vine_has_1_node_should_do_nothing(void){
  setNode(&node1, NULL, NULL, 'b');
  Node *vine = &node1;

  rightVineToTree(&vine);
  TEST_ASSERT_EQUAL_PTR(&node1, vine);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
}

/**  n = 2,     m = 2^[Floor(log2 (2+1))] - 1 
*                 = 1
*
*               c1(1) 
*    1(R)         2                    
*     \   -->    /      
*      2        1                 
*/
void test_rightVineToTree_given_Vine_has_2_node_should_do_c1(void){
  setNode(&node1, NULL, &node2, 'b');
  setNode(&node2, NULL, NULL, 'b');
  Node *vine = &node1;

  rightVineToTree(&vine);
  TEST_ASSERT_EQUAL_PTR(&node2, vine);
  TEST_ASSERT_EQUAL_NODE(&node1, NULL, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
}

/**  n = 3,     m = 2^[Floor(log2 (3+1))] - 1     c2(3/2) = c2(1)
*                 = 3
*
*                                    c2(1)    
*   1(R)                               2
*    \                              /   \
*     2        ---->              1       3
*      \
*       3
*          
*/
void test_rightVineToTree_given_Vine_has_3_node_should_do_c2_but_not_c1_because_n_and_m_are_equal(void){
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

/**  n = 4,     m = 2^[Floor(log2 (4+1))] - 1 
*                 = 3
*
*                            c1(1)                          c2(1)
*   1(R)                      2(R)                           3
*    \                      /   \                         /    \
*     2        ---->       1     3          ---->       2      4 
*      \                          \                    /
*       3                         4                   1
*        \                          
*         4   
*/
void test_rightVineToTree_given_Vine_has_4_node_should_form_do_c1_and_c2(void){
  setNode(&node1, NULL, &node2, 'b');
  setNode(&node2, NULL, &node3, 'b');
  setNode(&node3, NULL, &node4, 'b');
  setNode(&node4, NULL, NULL, 'b');
  Node *vine = &node1;

  rightVineToTree(&vine);
  TEST_ASSERT_EQUAL_PTR(&node3, vine);
  TEST_ASSERT_EQUAL_NODE(&node2, &node4, 'b', &node3);
  TEST_ASSERT_EQUAL_NODE(&node1, NULL, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node4);
}

/**  n = 5,     m = 2^[Floor(log2 (5+1))] - 1 
*                 = 3
*
*                         c1(2)                c2(1)
*   1(R)                  2(R)                    4
*    \                  /  \                    /   \
*     2        ---->   1    4       ---->     2      5
*      \                   / \              / \
*       3(R)              3   5            1   3
*        \                         
*         4                     
*          \
*           5
*
*/
void test_rightVineToTree_given_Vine_has_5_node_should_do_c1_and_c2(void){
  setNode(&node1, NULL, &node2, 'b');
  setNode(&node2, NULL, &node3, 'b');
  setNode(&node3, NULL, &node4, 'b');
  setNode(&node4, NULL, &node5, 'b');
  setNode(&node5, NULL, NULL, 'b');
  Node *vine = &node1;

  rightVineToTree(&vine);
  TEST_ASSERT_EQUAL_PTR(&node4, vine);
  TEST_ASSERT_EQUAL_NODE(&node2, &node5, 'b', &node4);
  TEST_ASSERT_EQUAL_NODE(&node1, &node3, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node3);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node5);
}

/**  n = 6,     m = 2^[Floor(log2 (6+1))] - 1 
*                 = 3
*
*                       c1(3)                 c2(1)
*   1(R)                  2(R)                  4
*    \                   /  \                 /   \  
*     2        ---->    1    4       ---->  2      6
*      \                    / \            / \    /
*       3(R)               3   6          1   3   5
*        \                    /                         
*         4                  5                         
*          \
*           5(R) 
*            \
*             6
*/
void test_rightVineToTree_given_Vine_has_6_node_should_form_tree_and_do_c1_and_c2(void){
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

/**  n = 7,     m = 2^[Floor(log2 (7+1))] - 1 
*                 = 7
*
*                       c2(3)                   c2(1)
*   1(R)                  2(R)                    4
*    \                  /  \                    /   \  
*     2        ---->   1    4      ---->      2      6
*      \                   / \               / \    / \
*       3(R)               3  6             1   3  5   7 
*        \                   /  \                         
*         4                 5    7                                 
*          \                                             
*           5(R)                                                
*            \                  
*             6
*              \
*               7
*
*/
void test_rightVineToTree_given_Vine_has_7_node_should_do_c2_2times(void){
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


/**  n = 9,     m = 2^[Floor(log2 (9+1))] - 1 
*                 = 7      
*                                  
*                        c1(2)                c2(3)                   c2(1)
*   1(R)                  2(R)                 4(R)                     6
*    \                  /   \                /   \                    /   \
*     2      ----->    1     4  ----->      2      6        ----->   4      8
*      \                    / \            / \    /  \              / \    / \
*       3(R)               3   5(R)       1   3  5    8            2   5  7   9
*        \                      \                    / \          / \
*         4                      6                  7    9       1   3             
*          \                     \
*           5                     7(R)
*            \                     \          
*             6                     8
*              \                     \
*               7                     9
*                \
*                 8
*                  \     
*                   9
*               
*/
void test_rightVineToTree_given_Vine_has_9_node_should_do_c1_and_c2_two_times(void){
  setNode(&node1, NULL, &node2, 'b');
  setNode(&node2, NULL, &node3, 'b');
  setNode(&node3, NULL, &node4, 'b');
  setNode(&node4, NULL, &node5, 'b');
  setNode(&node5, NULL, &node6, 'b');
  setNode(&node6, NULL, &node7, 'b');
  setNode(&node7, NULL, &node8, 'b');
  setNode(&node8, NULL, &node9, 'b');
  setNode(&node9, NULL, NULL, 'b');
  Node *vine = &node1;

  rightVineToTree(&vine);
  TEST_ASSERT_EQUAL_PTR(&node6, vine);
  TEST_ASSERT_EQUAL_NODE(&node4, &node8, 'b', &node6);
  TEST_ASSERT_EQUAL_NODE(&node2, &node5, 'b', &node4);
  TEST_ASSERT_EQUAL_NODE(&node7, &node9 , 'b', &node8);
  TEST_ASSERT_EQUAL_NODE(&node1, &node3 , 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node3);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node5);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node7);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node9);
}


