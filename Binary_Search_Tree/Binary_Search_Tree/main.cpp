#include "BinarySearchTree.h"
#include "testFunction.h"
#include <iostream>

int main()
{
	setlocale(LC_ALL, "rus");

	// Создание дерева для тестов
	BinarySearchTree<int> tree1;
	tree1.insert(7);
	tree1.insert(4);
	tree1.insert(9);
	tree1.insert(2);
	tree1.insert(5);
	tree1.insert(8);
	tree1.insert(10);

	// Тесты
	testIterativeSearch(tree1);
	testInsert(tree1);
	testDeleteKey();
	testPrint(tree1);
	testGetCount(tree1);
	testGetHeight(tree1);
	testIterativeInorderWalk(tree1);
	testInorderWalk(tree1);

	return 0;
}