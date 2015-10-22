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
*       16        ------>         7   
*       /                       /   \
*      7                      4      16
*     /
*    4
*/
void test_dswTreeBalancing_given_lefttSide_has_higher_height_with_3_node_should_balance(void){
  
  setNode(&node16, &node7, NULL, 'b');
  setNode(&node7, &node4, NULL, 'b');

	Node *root = &node16;
  dswTreeBalancing(&root);
  TEST_ASSERT_EQUAL_PTR(&node7, root);
  TEST_ASSERT_EQUAL_NODE(&node4, &node16, 'b', &node7);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node16);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node4);
}

/**       
*       16        ------>         12
*       /                       /   \
*      7                      7      16
*     / \                    /
*    4  12                  4
*/
void test_dswTreeBalancing_given_lefttSide_has_higher_height_with_4_node_should_balance(void){
  
  setNode(&node16, &node7, NULL, 'b');
  setNode(&node7, &node4, &node12, 'b');

	Node *root = &node16;
  dswTreeBalancing(&root);
  TEST_ASSERT_EQUAL_PTR(&node12, root);
  TEST_ASSERT_EQUAL_NODE(&node7, &node16, 'b', &node12);
  TEST_ASSERT_EQUAL_NODE(&node4, NULL, 'b', &node7);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node16);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node4);
}

/**       
*       16        ------>         7
*       /                       /   \
*      7                      4       16
*     / \                    / \      /
*    4   12                 2   6   12
*   / \
*  2  6
*
*/
void test_dswTreeBalancing_given_lefttSide_has_higher_height_with_6_node_should_balance(void){
  
  setNode(&node16, &node7, NULL, 'b');
  setNode(&node7, &node4, &node12, 'b');
  setNode(&node4, &node2, &node6, 'b');

	Node *root = &node16;
  dswTreeBalancing(&root);
  TEST_ASSERT_EQUAL_PTR(&node7, root);
  TEST_ASSERT_EQUAL_NODE(&node4, &node16, 'b', &node7);
  TEST_ASSERT_EQUAL_NODE(&node2, &node6, 'b', &node4);
  TEST_ASSERT_EQUAL_NODE(&node12, NULL, 'b', &node16);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node6);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node12);
}

/**       
*         16        ------>        10
*        /                       /   \
*       7                      6       14
*     /  \                    / \      / \
*    4    12                 4   7   12   16
*   / \   / \               /
*  2  6  10  14            2
*
*/
void test_dswTreeBalancing_given_lefttSide_has_higher_height_with_8_node_should_balance(void){
  
  setNode(&node16, &node7, NULL, 'b');
  setNode(&node7, &node4, &node12, 'b');
  setNode(&node4, &node2, &node6, 'b');
  setNode(&node12, &node10, &node14, 'b');

	Node *root = &node16;
  dswTreeBalancing(&root);
  TEST_ASSERT_EQUAL_PTR(&node10, root);
  TEST_ASSERT_EQUAL_NODE(&node6, &node14, 'b', &node10);
  TEST_ASSERT_EQUAL_NODE(&node4, &node7, 'b', &node6);
  TEST_ASSERT_EQUAL_NODE(&node12, &node16, 'b', &node14);
  TEST_ASSERT_EQUAL_NODE(&node2, NULL, 'b', &node4);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node7);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node12);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node16);
}

/**       
*           16        ------>                    14
*        /     \                               /    \
*       7       24                           7        24
*     /  \        \                        /  \       / \
*    4    12      28                     4      12   16  28
*   / \   / \                          /  \    / 
*  2  6  10  14                       2    6  10 
*
*/
void test_dswTreeBalancing_given_lefttSide_height_is_4_and_rightSide_height_is_2_should_balance(void){
  
  setNode(&node16, &node7, &node24, 'b');;
  setNode(&node7, &node4, &node12, 'b');
  setNode(&node4, &node2, &node6, 'b');
  setNode(&node12, &node10, &node14, 'b');
  setNode(&node24, NULL, &node28, 'b');

	Node *root = &node16;
  dswTreeBalancing(&root);
  TEST_ASSERT_EQUAL_PTR(&node14, root);
  TEST_ASSERT_EQUAL_NODE(&node7, &node24, 'b', &node14);
  TEST_ASSERT_EQUAL_NODE(&node4, &node12, 'b', &node7);
  TEST_ASSERT_EQUAL_NODE(&node2, &node6, 'b', &node4);
  TEST_ASSERT_EQUAL_NODE(&node16, &node28, 'b', &node24);
  TEST_ASSERT_EQUAL_NODE(&node10, NULL, 'b', &node12);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node6);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node10);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node16);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node28);
}

/**       
*           16        ------>                      16  
*        /     \                               /         \
*       7       24                           7             28
*     /  \        \                        /  \           / \
*    4    12      28                     4      12      26  30
*   / \   / \     / \                  /  \    / \    /
*  2  6  10  14  26 30               2    6  10  14  24
*
*/
void test_dswTreeBalancing_given_lefttSide_height_is_0_and_rightSide_height_is_still_2_should_balance(void){
  
  setNode(&node16, &node7, &node24, 'b');;
  setNode(&node7, &node4, &node12, 'b');
  setNode(&node4, &node2, &node6, 'b');
  setNode(&node12, &node10, &node14, 'b');
  setNode(&node24, NULL, &node28, 'b');
  setNode(&node28, &node26, &node30, 'b');

	Node *root = &node16;
  dswTreeBalancing(&root);
  TEST_ASSERT_EQUAL_PTR(&node16, root);
  TEST_ASSERT_EQUAL_NODE(&node7, &node28, 'b', &node16);
  TEST_ASSERT_EQUAL_NODE(&node4, &node12, 'b', &node7);
  TEST_ASSERT_EQUAL_NODE(&node2, &node6, 'b', &node4);
  TEST_ASSERT_EQUAL_NODE(&node10, &node14, 'b', &node12);
  TEST_ASSERT_EQUAL_NODE(&node26, &node30, 'b', &node28);
  TEST_ASSERT_EQUAL_NODE(&node24, NULL, 'b', &node26);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node6);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node10);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node14);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node24);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node30);
}

/**       
*           16      
*        /     \                       
*       7        24                        
*     /  \      /  \                     
*    4    12   20   28                   
*   / \   / \                   
*  2  6  10  14                 
*
*/
void test_dswTreeBalancing_given_lefttSide_height_is_4_and_rightSide_height_is_3_should_not_balannce_because_it_full_fill_the_feature(void){
  
  setNode(&node16, &node7, &node24, 'b');;
  setNode(&node7, &node4, &node12, 'b');
  setNode(&node4, &node2, &node6, 'b');
  setNode(&node12, &node10, &node14, 'b');
  setNode(&node24, &node20, &node28, 'b');

	Node *root = &node16;
  dswTreeBalancing(&root);
  TEST_ASSERT_EQUAL_PTR(&node16, root);
  TEST_ASSERT_EQUAL_NODE(&node7, &node24, 'b', &node16);
  TEST_ASSERT_EQUAL_NODE(&node4, &node12, 'b', &node7);
  TEST_ASSERT_EQUAL_NODE(&node2, &node6, 'b', &node4);
  TEST_ASSERT_EQUAL_NODE(&node10, &node14, 'b', &node12);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node6);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node10);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node14);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node20);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node28);
}
