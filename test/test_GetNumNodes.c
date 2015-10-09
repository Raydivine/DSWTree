#include "unity.h"
#include "GetNumNodes.h"
#include "Node.h"
#include "InitNode.h"
#include "CustomAssertion.h"

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

//  NULL
void test_getNumNodes_Vine_has_0_Nodes_should_return_0(void){
  Node *vine = NULL;
  
  int num = getNumNodes(vine);
  TEST_ASSERT_EQUAL(0,num);
}

//  1
void test_getNumNodes_Vine_has_1_Nodes_should_return_1(void){
  setNode(&node1, NULL, NULL, 'b');
  Node *vine = &node1;
  
  int num = getNumNodes(vine);
  TEST_ASSERT_EQUAL(1,num);
}

//  1-2
void test_getNumNodes_Vine_has_2_Nodes_should_return_2(void){
  setNode(&node1, NULL, &node2, 'b');
  setNode(&node2, NULL, NULL, 'b');
  Node *vine = &node1;
  
  int num = getNumNodes(vine);
  TEST_ASSERT_EQUAL(2,num);
}

//  1-2-3
void test_getNumNodes_Vine_has_3_Nodes_should_return_3(void){
  setNode(&node1, NULL, &node2, 'b');
  setNode(&node2, NULL, &node3, 'b');
  setNode(&node3, NULL, NULL, 'b');
  Node *vine = &node1;
  
  int num = getNumNodes(vine);
  TEST_ASSERT_EQUAL(3,num);
}

//  1-2-3-4
void test_getNumNodes_Vine_has_4_Nodes_should_return_4(void){
  setNode(&node1, NULL, &node2, 'b');
  setNode(&node2, NULL, &node3, 'b');
  setNode(&node3, NULL, &node4, 'b');
  setNode(&node4, NULL, NULL, 'b');
  Node *vine = &node1;
  
  int num = getNumNodes(vine);
  TEST_ASSERT_EQUAL(4,num);
}