#include "BinarySearchTree.h"
#include <iostream>

//
// ����� ��� ��������� ������ ������ - ����� BinarySearchTree
//

//-----------------------------------------------------------------------------------------------------------------------
// ����� ���������� ������������
void printTest(BinarySearchTree<int>& tree, bool result = true)
{
	std::cout << "result = " << result << " ������: ";
	tree.print(std::cout);
}

//-----------------------------------------------------------------------------------------------------------------------
// ����� �� ����� (�����������)
void testIterativeSearch(BinarySearchTree<int>& tree)
{
	std::cout << '\n' << "----- ����� �� ����� (�����������) -----" << '\n';

	// �������� ��� � ������ - ���
	bool resultSearch1 = tree.iterativeSearch(15);
	printTest(tree, resultSearch1);

	// ������� ���� � ������ - ��
	bool resultSearch2 = tree.iterativeSearch(5);
	printTest(tree, resultSearch2);
}

//-----------------------------------------------------------------------------------------------------------------------
// ������� ������ �������� � ������ (�����������)
void testInsert(BinarySearchTree<int>& tree)
{
	std::cout << '\n' << "----- ������� ������ �������� � ������ (�����������) -----" << '\n';

	BinarySearchTree<int> emptyTree;

	// �������� ������� ���� � ������ - ���
	bool resultSearch1 = tree.insert(8);
	printTest(tree, resultSearch1);

	// ������ ������ - ��
	bool resultSearch2 = emptyTree.insert(9);
	printTest(emptyTree, resultSearch2);

	// ��������� �������� ��� � ������ - ��
	bool resultSearch3 = tree.insert(6);
	printTest(tree, resultSearch3);
	tree.deleteKey(6);
}

//-----------------------------------------------------------------------------------------------------------------------
// �������� �������� �� ������ (�����������)
void testDeleteKey()
{
	std::cout << '\n' << "----- �������� �������� �� ������ (�����������) -----" << '\n';

	BinarySearchTree<int> tree;
	tree.insert(7);

	// ������� �� ������ - ���
	std::cout << "\n�������� ������: ";
	tree.print(std::cout);
	bool resultSearch1 = tree.deleteKey(5);
	printTest(tree, resultSearch1);

	// � �������� ��� �����������, ������� �������� ������ - ��
	std::cout << "\n�������� ������: ";
	tree.print(std::cout);
	bool resultSearch2 = tree.deleteKey(7);
	printTest(tree, resultSearch2);

	tree.insert(7);
	tree.insert(5);

	// � �������� ��� �����������, ������� �� �������� ������ - ��
	std::cout << "\n�������� ������: ";
	tree.print(std::cout);
	bool resultSearch3 = tree.deleteKey(5);
	printTest(tree, resultSearch3);

	tree.insert(5);

	// � �������� ���� ���� ��������� �����, ������� �������� ������ - ��
	std::cout << "\n�������� ������: ";
	tree.print(std::cout);
	bool resultSearch4 = tree.deleteKey(7);
	printTest(tree, resultSearch4);

	tree.insert(7);
	tree.insert(6);

	// � �������� ���� ���� ��������� �����, ������� �� �������� ������ - ��
	std::cout << "\n�������� ������: ";
	tree.print(std::cout);
	bool resultSearch5 = tree.deleteKey(7);
	printTest(tree, resultSearch5);

	// � �������� ���� ���� ��������� ������, ������� �������� ������ - ��
	std::cout << "\n�������� ������: ";
	tree.print(std::cout);
	bool resultSearch6 = tree.deleteKey(5);
	printTest(tree, resultSearch6);

	tree.insert(0);
	tree.insert(1);

	// � �������� ���� ���� ��������� ������, ������� �� �������� ������ - ��
	std::cout << "\n�������� ������: ";
	tree.print(std::cout);
	bool resultSearch7 = tree.deleteKey(0);
	printTest(tree, resultSearch7);

	tree.insert(0);
	tree.insert(5);
	tree.insert(2);

	// � �������� ���� ��� ����������, � ������������ ���� ��� ����������� - ��
	std::cout << "\n�������� ������: ";
	tree.print(std::cout);
	bool resultSearch8 = tree.deleteKey(1);
	printTest(tree, resultSearch8);

	tree.insert(3);
	tree.insert(4);

	// � �������� ���� ��� ����������, � ������������ ���� ���� ���� ��������� (������) - ��
	std::cout << "\n�������� ������: ";
	tree.print(std::cout);
	bool resultSearch9 = tree.deleteKey(2);
	printTest(tree, resultSearch9);
}

//-----------------------------------------------------------------------------------------------------------------------
// ������ ���������� ����������� ������
void testPrint(BinarySearchTree<int>& tree)
{
	std::cout << '\n' << "----- ������ ���������� ����������� ������ -----" << '\n';

	BinarySearchTree<int> emptyTree;

	// ������ ������
	std::cout << "\n������: ";
	emptyTree.print(std::cout);

	// �������� ������
	std::cout << "\n������: ";
	tree.print(std::cout);
}

//-----------------------------------------------------------------------------------------------------------------------
// ����������� ���������� ����� ������ (�����������)
void testGetCount(BinarySearchTree<int>&tree)
{
	std::cout << '\n' << "----- ����������� ���������� ����� ������ (�����������) -----" << '\n';

	// ������� ����� � ������ - ��
	bool resultSearch1 = (tree.getCount() == 7);
	printTest(tree, resultSearch1);
}

//-----------------------------------------------------------------------------------------------------------------------
// ����������� ������ ������ (�����������)
void testGetHeight(BinarySearchTree<int>& tree)
{
	std::cout << '\n' << "----- ����������� ������ ������ (�����������) -----" << '\n';

	// ����������� ������ ������ - ��
	bool resultSearch1 = (tree.getHeight() == 2);
	printTest(tree, resultSearch1);

	// ����������� ������ ������ ����� ���������� �������� �� ����� ������� - ��
	tree.insert(1);
	bool resultSearch2 = (tree.getHeight() == 3);
	printTest(tree, resultSearch2);
	tree.deleteKey(1);
}

//-----------------------------------------------------------------------------------------------------------------------
// ��������� ����� ������ (�����������)
void testIterativeInorderWalk(BinarySearchTree<int>& tree)
{
	std::cout << '\n' << "----- ��������� ����� ������ (�����������) -----" << '\n';

	BinarySearchTree<int> emptyTree;

	// ��������� ����� ������� ������
	std::cout << "\n������: ";
	emptyTree.print(std::cout);
	std::cout << "�����: ";
	emptyTree.iterativeInorderWalk();

	// ��������� ����� ��������� ������
	std::cout << "\n������: ";
	tree.print(std::cout);
	std::cout << "�����: ";
	tree.iterativeInorderWalk();
}

//-----------------------------------------------------------------------------------------------------------------------
// ��������� ����� ������ (�����������)
void testInorderWalk(BinarySearchTree<int>& tree)
{
	std::cout << '\n' << "----- ��������� ����� ������ (�����������) -----" << '\n';

	BinarySearchTree<int> emptyTree;

	// ��������� ����� ������� ������
	std::cout << "\n������: ";
	emptyTree.print(std::cout);
	std::cout << "�����: ";
	emptyTree.inorderWalk();

	// ��������� ����� ��������� ������
	std::cout << "\n������: ";
	tree.print(std::cout);
	std::cout << "�����: ";
	tree.inorderWalk();
}