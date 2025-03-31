#ifndef _TEST_FUNCTION
#define _TEST_FUNCTION
#include "BinarySearchTree.h"
#include "Queue.h"

//
// ����� ��� ������� - ����� QueueArray
// ����� ��� ����������� ���������� ������ �������� �������� - ����� BinarySearchTree
//

// ���������� ��������
void testEnQueue();

// �������� � ����������� ��������
void testDeQueue();

// ����� ������ � ������ (�����������)
void testIterativeBreadthWalk();

// �����, ������������, �������� �� ��� ������ ��������
void testCheckSimilarityTrees();

// �����, ������������ ���� ���������� ����� � ���� �������� ������
void testCheckForIdenticalKeys();

// ����� ���������� ������������
void printTest(BinarySearchTree<int>& tree1, BinarySearchTree<int>& tree2, bool result = true);

#endif