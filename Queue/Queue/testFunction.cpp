#include "BinarySearchTree.h"
#include "Queue.h"
#include <iostream>

//
// ����� ��� ������� - ����� QueueArray
// ����� ��� ����������� ���������� ������ �������� �������� - ����� BinarySearchTree
//

//-----------------------------------------------------------------------------------------------------------------------
// ����� ���������� ������������
void printTest(BinarySearchTree<int>& tree1, BinarySearchTree<int>& tree2, bool result = true)
{
	std::cout << "result = " << result << std::endl;
	std::cout << "������ ������: ";
	tree1.print(std::cout);
	std::cout << "������ ������: ";
	tree2.print(std::cout);
}

//-----------------------------------------------------------------------------------------------------------------------
// ���������� ��������
void testEnQueue()
{
	std::cout << "\n----- ���������� �������� -----\n";

	QueueArray<int> queue(2);

	// ���������� ��������, ������� ������
	std::cout << "\n�������� �������: ";
	queue.print();
	queue.enQueue(1);
	std::cout << "������� ����� ���������� ��������: ";
	queue.print();

	// ���������� ��������, �������� ���� � �������
	std::cout << "\n�������� �������: ";
	queue.print();
	queue.enQueue(2);
	std::cout << "������� ����� ���������� ��������: ";
	queue.print();

	// ���������� �������� ����� �������� �� ����������� ������� ��������
	queue.deQueue();
	std::cout << "\n�������� �������: ";
	queue.print();
	queue.enQueue(3);
	std::cout << "������� ����� ���������� ��������: ";
	queue.print();
}

//-----------------------------------------------------------------------------------------------------------------------
// �������� � ����������� ��������
void testDeQueue()
{
	std::cout << "\n----- �������� � ����������� �������� -----\n";

	QueueArray<int> queue(2);
	queue.enQueue(1);
	queue.enQueue(2);

	// �������� ��������, ������� �����������
	std::cout << "\n�������� �������: ";
	queue.print();
	queue.deQueue();
	std::cout << "������� ����� �������� ��������: ";
	queue.print();

	// �������� ��������, ������� �� �� ����� �����������
	std::cout << "\n�������� �������: ";
	queue.print();
	queue.deQueue();
	std::cout << "������� ����� �������� ��������: ";
	queue.print();

	// �������� �������� ����� ����� ��������� ������ ������� � ���������� � �� ��������
	queue.enQueue(3);
	std::cout << "\n�������� �������: ";
	queue.print();
	queue.deQueue();
	std::cout << "������� ����� �������� ��������: ";
	queue.print();
}

//-----------------------------------------------------------------------------------------------------------------------
// ����� ������ � ������ (�����������)
void testIterativeBreadthWalk()
{
	std::cout << "\n----- ����� ������ � ������ (�����������) -----\n";

	BinarySearchTree<int> tree;
	tree.insert(7);
	tree.insert(4);
	tree.insert(9);
	tree.insert(2);
	tree.insert(5);
	tree.insert(8);
	tree.insert(10);
	BinarySearchTree<int> emptyTree;

	// ����� � ������ ������� ������
	std::cout << "\n������: ";
	emptyTree.print(std::cout);
	std::cout << "�����: ";
	emptyTree.iterativeBreadthWalk();

	// ����� � ������ ��������� ������
	std::cout << "\n������: ";
	tree.print(std::cout);
	std::cout << "�����: ";
	tree.iterativeBreadthWalk();
}

//-----------------------------------------------------------------------------------------------------------------------
// �����, ������������, �������� �� ��� ������ ��������
void testCheckSimilarityTrees()
{
	std::cout << "\n----- �����, ������������, �������� �� ��� ������ �������� -----\n";

	BinarySearchTree<int> tree1;
	tree1.insert(7);
	tree1.insert(4);
	tree1.insert(9);
	tree1.insert(2);
	tree1.insert(5);
	tree1.insert(8);
	tree1.insert(10);
	BinarySearchTree<int> tree2;
	tree2.insert(9);
	tree2.insert(5);
	tree2.insert(7);
	tree2.insert(10);
	tree2.insert(4);
	tree2.insert(8);
	tree2.insert(2);
	BinarySearchTree<int> tree3;
	tree3.insert(9);
	tree3.insert(5);
	tree3.insert(15);
	tree3.insert(10);
	tree3.insert(4);
	tree3.insert(8);
	tree3.insert(2);
	BinarySearchTree<int> tree4;
	tree4.insert(5);
	tree4.insert(7);
	tree4.insert(4);
	tree4.insert(8);
	tree4.insert(2);
	BinarySearchTree<int> emptyTree1;
	BinarySearchTree<int> emptyTree2;

	// ������� ����� ���������� ����� ������ - ��
	bool resultSearch1 = tree1.checkSimilarityTrees(tree2);
	printTest(tree1, tree2, resultSearch1);

	// ������� ����� ������ ����� ������ ���������� ����� - ���
	bool resultSearch2 = tree1.checkSimilarityTrees(tree3);
	printTest(tree1, tree3, resultSearch2);

	// ������� ����� ������ ����� ������ ������ ����� - ���
	bool resultSearch3 = tree1.checkSimilarityTrees(tree4);
	printTest(tree1, tree4, resultSearch3);

	// ���� �� �������� ������ - ���
	bool resultSearch4 = tree1.checkSimilarityTrees(emptyTree2);
	printTest(tree1, emptyTree2, resultSearch4);

	// ��� ������ ������ - ��
	bool resultSearch5 = emptyTree1.checkSimilarityTrees(emptyTree2);
	printTest(emptyTree1, emptyTree2, resultSearch5);
}

//-----------------------------------------------------------------------------------------------------------------------
// �����, ������������ ���� ���������� ����� � ���� �������� ������
void testCheckForIdenticalKeys()
{
	std::cout << "\n----- �����, ������������ ���� ���������� ����� � ���� �������� ������ -----\n";

	BinarySearchTree<int> tree1;
	tree1.insert(7);
	tree1.insert(4);
	tree1.insert(9);
	tree1.insert(2);
	tree1.insert(5);
	tree1.insert(8);
	tree1.insert(10);
	BinarySearchTree<int> tree2;
	tree2.insert(1);
	tree2.insert(3);
	tree2.insert(6);
	tree2.insert(11);
	tree2.insert(13);
	tree2.insert(12);
	tree2.insert(14);
	BinarySearchTree<int> tree3;
	tree3.insert(1);
	tree3.insert(3);
	tree3.insert(7);
	tree3.insert(11);
	tree3.insert(13);
	tree3.insert(12);
	tree3.insert(14);
	BinarySearchTree<int> emptyTree1;
	BinarySearchTree<int> emptyTree2;

	// ������� ����� ������ ����� ������ - ���
	bool resultSearch1 = tree1.checkForIdenticalKeys(tree2);
	printTest(tree1, tree2, resultSearch1);

	// ������� ����� ���� �� ���� ���������� ���� - ��
	bool resultSearch2 = tree1.checkForIdenticalKeys(tree3);
	printTest(tree1, tree3, resultSearch2);

	// ���� �� �������� ������ - ���
	bool resultSearch3 = tree1.checkForIdenticalKeys(emptyTree1);
	printTest(tree1, emptyTree1, resultSearch3);

	// ��� ������ ������ - ���
	bool resultSearch4 = emptyTree1.checkForIdenticalKeys(emptyTree2);
	printTest(emptyTree1, emptyTree2, resultSearch4);
}