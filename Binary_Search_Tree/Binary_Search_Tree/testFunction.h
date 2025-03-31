#ifndef _TEST_FUNCTION
#define _TEST_FUNCTION
#include "BinarySearchTree.h"

//
// ����� ��� ��������� ������ ������ - ����� BinarySearchTree
//

// ����� �� ����� (�����������)
void testIterativeSearch(BinarySearchTree<int>& tree);

// ������� ������ �������� � ������ (�����������)
void testInsert(BinarySearchTree<int>& tree);

// �������� �������� �� ������ (�����������)
void testDeleteKey();

// ������ ���������� ����������� ������
void testPrint(BinarySearchTree<int>& tree);

// ����������� ���������� ����� ������ (�����������)
void testGetCount(BinarySearchTree<int>& tree);

// ����������� ������ ������ (�����������)
void testGetHeight(BinarySearchTree<int>& tree);

// ��������� ����� ������ (�����������)
void testIterativeInorderWalk(BinarySearchTree<int>& tree);

// ��������� ����� ������ (�����������)
void testInorderWalk(BinarySearchTree<int>& tree);

// ����� ���������� ������������
void printTest(BinarySearchTree<int>& tree, bool result = true);

#endif