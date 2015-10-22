#include "unity.h"
#include "DSW.h"
#include "Node.h"
#include "TreeToVine.h"
#include "VineToTree.h"
#include "InitNode.h"
#include "CustomAssertion.h"
#include "GetNumNodes.h"
#include "Rotations.h"

Node node1,node2,node3,node4 ,node5, node6, node7, node8, node9, node10, node11, node12, node13, node14, node11, node12, node13, node14 , node15,
     node16, node17, node18, node19 , node20, node21, node22, node23, node24, node25, node26, node27 , node28 , node29, node30 , node31;

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
	resetNode(&node18, 18);
	resetNode(&node19, 19);
	resetNode(&node20, 20);
	resetNode(&node21, 21);
	resetNode(&node22, 22);
	resetNode(&node23, 23);
	resetNode(&node24, 24);
	resetNode(&node25, 25);
	resetNode(&node26, 26);
	resetNode(&node27, 27);
	resetNode(&node28, 28);
	resetNode(&node29, 29);
	resetNode(&node30, 30);
	resetNode(&node31, 31);
}

/** The tree below is used to test this fucntion
*
*                                             16
*                                         /         \
*                                     7                 24
*                                  /    \             /    \
*                                 4      12         20       28        
*                                / \     / \        / \     /  \
*                               2   6   10  14    18   22  26  30
*
*   This DSW function is convert the unbalance tree to rightVine, then rightVine convert back to leftVine,
*   So there is a output feature which leftSide's height is always equal or higher 1 compare to the rightSide's height.
*/


void tearDown(void)
{
}
/**
*  NULL

*/
void test_dswTreeBalancing_given_NULL_should_do_nothing(void){
	Node *root = NULL;
  
  dswTreeBalancing(&root);
  TEST_ASSERT_NULL(root);
}

/**
*  16
*
*/
void test_dswTreeBalancing_given_root_is_one_only_should_do_nothing(void){
  
  setNode(&node16, NULL, NULL, 'b');
	Node *root = &node16;
  
  dswTreeBalancing(&root);
  TEST_ASSERT_EQUAL_PTR(&node16, root);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node16);
}


/**       
*       16    ------>      24
*         \               /
*         24             16
*/
void test_dswTreeBalancing_given_root_is_rightVine_with_2_node_should_balance_because_this_DSW_function_is_balancing_from_right_to_left(void){
  
  setNode(&node16, NULL, &node24, 'b');
  setNode(&node24, NULL, NULL, 'b');

	Node *root = &node16;
  dswTreeBalancing(&root);
  TEST_ASSERT_EQUAL_PTR(&node24, root);
  TEST_ASSERT_EQUAL_NODE(&node16, NULL, 'b', &node24);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node16);
}

/**       
*           24
*         /
*        16
*/
void test_dswTreeBalancing_given_root_is_leftVine_with_2_node_should_balance_because_this_DSW_function_is_balancing_right_to_left(void){
  
  setNode(&node24, &node16, NULL, 'b');
  setNode(&node16, NULL, NULL, 'b');

	Node *root = &node24;
  dswTreeBalancing(&root);
  TEST_ASSERT_EQUAL_PTR(&node24, root);
  TEST_ASSERT_EQUAL_NODE(&node16, NULL, 'b', &node24);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node26);
}

/**       
*       16    ------>      24
*         \               /   \
*         24             16   28
*           \
*           28
*
*/
void test_dswTreeBalancing_given_rightSide_has_higher_height_with_3_node_should_balance(void){
  
  setNode(&node16, NULL, &node24, 'b');
  setNode(&node24, NULL, &node28, 'b');
  setNode(&node28, NULL, NULL, 'b');

	Node *root = &node16;
  dswTreeBalancing(&root);
  TEST_ASSERT_EQUAL_PTR(&node24, root);
  TEST_ASSERT_EQUAL_NODE(&node16, &node28, 'b', &node24);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node16);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node28);
}

/**       
*       16    ------>       24    
*         \               /   \
*         24             20   28
*        /  \          /
*      20    28       16    
*                      This is the output feathre of this DSW function, 
*                      leftSide's height is always equal or higher 1 compare to the rightSide's height
*                      So the output balanced tree will look like it  place the nodes from the left to right 
*
*/
void test_dswTreeBalancing_given_rightSide_has_higher_height_with_4_node_should_balance(void){
  
  setNode(&node16, NULL, &node24, 'b');
  setNode(&node24, &node20, &node28, 'b');
  setNode(&node28, NULL, NULL, 'b');
  setNode(&node20, NULL, NULL, 'b');

	Node *root = &node16;
  dswTreeBalancing(&root);
  TEST_ASSERT_EQUAL_PTR(&node24, root);
  TEST_ASSERT_EQUAL_NODE(&node20, &node28, 'b', &node24);
  TEST_ASSERT_EQUAL_NODE(&node16, NULL, 'b', &node20);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node28);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node16);
}

/**       
*       16    ------>       24    
*         \               /   \
*         24             18   28
*        /  \          /  \
*      20    28       16   20 
*     /
*    18
*
*/
void test_dswTreeBalancing_given_rightSide_has_higher_height_with_5_node_should_balance(void){
  
  setNode(&node16, NULL, &node24, 'b');
  setNode(&node24, &node20, &node28, 'b');
  setNode(&node28, NULL, NULL, 'b');
  setNode(&node20, &node18, NULL, 'b');
  setNode(&node18, NULL, NULL, 'b');

	Node *root = &node16;
  dswTreeBalancing(&root);
  TEST_ASSERT_EQUAL_PTR(&node24, root);
  TEST_ASSERT_EQUAL_NODE(&node18, &node28, 'b', &node24);
  TEST_ASSERT_EQUAL_NODE(&node16, &node20, 'b', &node18);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node28);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node20);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node16);
}

/**       
*       16        ------>        22    
*         \                   /     \
*         24                 18       28
*        /  \               /  \     /
*      20    28           16   20   24
*     / \
*    18 22
*
*/
void test_dswTreeBalancing_given_rightSide_has_higher_height_with_6_node_should_balance(void){
  
  setNode(&node16, NULL, &node24, 'b');
  setNode(&node24, &node20, &node28, 'b');
  setNode(&node28, NULL, NULL, 'b');
  setNode(&node20, &node18, &node22, 'b');
  setNode(&node18, NULL, NULL, 'b');
  setNode(&node22, NULL, NULL, 'b');

	Node *root = &node16;
  dswTreeBalancing(&root);
  TEST_ASSERT_EQUAL_PTR(&node22, root);
  TEST_ASSERT_EQUAL_NODE(&node18, &node28, 'b', &node22);
  TEST_ASSERT_EQUAL_NODE(&node16, &node20, 'b', &node18);
  TEST_ASSERT_EQUAL_NODE(&node24, NULL, 'b', &node28);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node24);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node20);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node16);
}

/**       
*       16        ------>         22    
*         \                    /     \
*         24                 18       26
*        /  \               /  \     /  \
*      20     28           16   20  24  28
*     / \    /
*    18 22  26
*
*/
void test_dswTreeBalancing_given_rightSide_has_higher_height_with_7_node_should_balance(void){
  
  setNode(&node16, NULL, &node24, 'b');
  setNode(&node24, &node20, &node28, 'b');
  setNode(&node28, &node26, NULL, 'b');
  setNode(&node20, &node18, &node22, 'b');
  setNode(&node18, NULL, NULL, 'b');
  setNode(&node26, NULL, NULL, 'b');
  setNode(&node22, NULL, NULL, 'b');

	Node *root = &node16;
  dswTreeBalancing(&root);
  TEST_ASSERT_EQUAL_PTR(&node22, root);
  TEST_ASSERT_EQUAL_NODE(&node18, &node26, 'b', &node22);
  TEST_ASSERT_EQUAL_NODE(&node16, &node20, 'b', &node18);
  TEST_ASSERT_EQUAL_NODE(&node24, &node28, 'b', &node26);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node28);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node24);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node20);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node16);
}

/**       
*       16        ------>         24    
*         \                    /     \
*         24                 20       28
*        /  \               /  \     /  \
*      20     28           18   22  26  30
*     / \    /  \         /
*    18 22  26  30       16
*
*/
void test_dswTreeBalancing_given_rightSide_has_higher_height_with_8_node_should_balance(void){
  
  setNode(&node16, NULL, &node24, 'b');
  setNode(&node24, &node20, &node28, 'b');
  setNode(&node28, &node26, &node30, 'b');
  setNode(&node20, &node18, &node22, 'b');
  setNode(&node18, NULL, NULL, 'b');
  setNode(&node26, NULL, NULL, 'b');
  setNode(&node30, NULL, NULL, 'b');

	Node *root = &node16;
  dswTreeBalancing(&root);
  TEST_ASSERT_EQUAL_PTR(&node24, root);
  TEST_ASSERT_EQUAL_NODE(&node20, &node28, 'b', &node24);
  TEST_ASSERT_EQUAL_NODE(&node18, &node22, 'b', &node20);
  TEST_ASSERT_EQUAL_NODE(&node26, &node30, 'b', &node28);
  TEST_ASSERT_EQUAL_NODE(&node16, NULL, 'b', &node18);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node26);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node30);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node22);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node16);
}

/**       
*       16        ------>         24    
*      /   \                    /     \
*     7    24                 20       28
*        /  \               /  \     /  \
*      20     28           16   22  26  30
*     / \    /  \         / \
*    18 22  26  30       7   18
*
*/
void test_dswTreeBalancing_given_rightSide_height_is_4_leftSide_is_2_should_balance(void){
  
  setNode(&node16, &node7, &node24, 'b');
  setNode(&node24, &node20, &node28, 'b');
  setNode(&node28, &node26, &node30, 'b');
  setNode(&node20, &node18, &node22, 'b');
  setNode(&node18, NULL, NULL, 'b');
  setNode(&node26, NULL, NULL, 'b');
  setNode(&node30, NULL, NULL, 'b');

	Node *root = &node16;
  dswTreeBalancing(&root);
  TEST_ASSERT_EQUAL_PTR(&node24, root);
  TEST_ASSERT_EQUAL_NODE(&node20, &node28, 'b', &node24);
  TEST_ASSERT_EQUAL_NODE(&node16, &node22, 'b', &node20);
  TEST_ASSERT_EQUAL_NODE(&node26, &node30, 'b', &node28);
  TEST_ASSERT_EQUAL_NODE(&node7, &node18, 'b', &node16);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node26);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node30);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node22);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node7);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node18);
}

/**       
*         16        ------>              24    
*      /     \                        /     \
*   7          24                   16        28
*  /\          /  \               /    \     /  \
* 4  12      20     28           7      20  26  30  
*           / \    /  \         / \    /  \
*          18 22  26  30       4   12 18  22
*
*/
void test_dswTreeBalancing_given_rightSide_height_is_4_leftSide_is_3_should_balance_because_of_this_function_feature(void){
  
  setNode(&node16, &node7, &node24, 'b');
  setNode(&node24, &node20, &node28, 'b');
  setNode(&node28, &node26, &node30, 'b');
  setNode(&node20, &node18, &node22, 'b');
  setNode(&node18, NULL, NULL, 'b');
  setNode(&node26, NULL, NULL, 'b');
  setNode(&node30, NULL, NULL, 'b');
  setNode(&node7, &node4, &node12, 'b');

	Node *root = &node16;
  dswTreeBalancing(&root);
  TEST_ASSERT_EQUAL_PTR(&node24, root);
  TEST_ASSERT_EQUAL_NODE(&node16, &node28, 'b', &node24);
  TEST_ASSERT_EQUAL_NODE(&node7, &node20, 'b', &node16);
  TEST_ASSERT_EQUAL_NODE(&node4, &node12, 'b', &node7);
  TEST_ASSERT_EQUAL_NODE(&node18, &node22, 'b', &node20);
  TEST_ASSERT_EQUAL_NODE(&node26, &node30, 'b', &node28);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node4);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node12);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node18);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node22);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node26);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node30);
}

/**       
*          16        ------>              22   
*       /     \                        /      \
*     7         24                   7            28
*    /         /  \               /    \         /  \
*   4        20     28           4      18      26  30  
*  /\       / \    /  \         / \    /  \     /
* 2  6     18 22  26  30       2   6  16  20   24
*
*/
void test_dswTreeBalancing_given_rightSide_height_is_4_leftSide_is_still_2_should_balance(void){
  
  setNode(&node16, &node7, &node24, 'b');
  setNode(&node24, &node20, &node28, 'b');
  setNode(&node28, &node26, &node30, 'b');
  setNode(&node20, &node18, &node22, 'b');
  setNode(&node18, NULL, NULL, 'b');
  setNode(&node26, NULL, NULL, 'b');
  setNode(&node30, NULL, NULL, 'b');
  setNode(&node7, &node4, NULL, 'b');
  setNode(&node4, &node2, &node6, 'b');

	Node *root = &node16;
  dswTreeBalancing(&root);
  TEST_ASSERT_EQUAL_PTR(&node22, root);
  TEST_ASSERT_EQUAL_NODE(&node7, &node28, 'b', &node22);
  TEST_ASSERT_EQUAL_NODE(&node4, &node18, 'b', &node7);
  TEST_ASSERT_EQUAL_NODE(&node2, &node6, 'b', &node4);
  TEST_ASSERT_EQUAL_NODE(&node16, &node20, 'b', &node18);
  TEST_ASSERT_EQUAL_NODE(&node26, &node30, 'b', &node28);
  TEST_ASSERT_EQUAL_NODE(&node24, NULL, 'b', &node26);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node6);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node16);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node20);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node24);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node30);
}


// setNode(&node16, &node7, &node24, 'b');
// setNode(&node7, &node4, &node12, 'b');
// setNode(&node4, &node2, &node6, 'b');
// setNode(&node12, &node10, &node14, 'b');
// setNode(&node24, &node20, &node28, 'b');
// setNode(&node20, &node18, &node22, 'b');
// setNode(&node28, &node26, &node30, 'b');
// setNode(&node2, NULL, NULL, 'b');
// setNode(&node6, NULL, NULL, 'b');
// setNode(&node10, NULL, NULL, 'b');
// setNode(&node14, NULL, NULL, 'b');
// setNode(&node18, NULL, NULL, 'b');
// setNode(&node22, NULL, NULL, 'b');
// setNode(&node26, NULL, NULL, 'b');
// setNode(&node30, NULL, NULL, 'b');
