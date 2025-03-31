#include "BinarySearchTree.h"
#include <iostream>

//
// Тесты для бинарного дерева поиска - класс BinarySearchTree
//

//-----------------------------------------------------------------------------------------------------------------------
// Вывод результата тестирования
void printTest(BinarySearchTree<int>& tree, bool result = true)
{
	std::cout << "result = " << result << " Дерево: ";
	tree.print(std::cout);
}

//-----------------------------------------------------------------------------------------------------------------------
// Поиск по ключу (итеративный)
void testIterativeSearch(BinarySearchTree<int>& tree)
{
	std::cout << '\n' << "----- Поиск по ключу (итеративный) -----" << '\n';

	// Элемента нет в дереве - нет
	bool resultSearch1 = tree.iterativeSearch(15);
	printTest(tree, resultSearch1);

	// Элемент есть в дереве - да
	bool resultSearch2 = tree.iterativeSearch(5);
	printTest(tree, resultSearch2);
}

//-----------------------------------------------------------------------------------------------------------------------
// Вставка нового элемента в дерево (итеративный)
void testInsert(BinarySearchTree<int>& tree)
{
	std::cout << '\n' << "----- Вставка нового элемента в дерево (итеративный) -----" << '\n';

	BinarySearchTree<int> emptyTree;

	// Подобный элемент есть в дереве - нет
	bool resultSearch1 = tree.insert(8);
	printTest(tree, resultSearch1);

	// Дерево пустое - да
	bool resultSearch2 = emptyTree.insert(9);
	printTest(emptyTree, resultSearch2);

	// Подобного элемента нет в дереве - да
	bool resultSearch3 = tree.insert(6);
	printTest(tree, resultSearch3);
	tree.deleteKey(6);
}

//-----------------------------------------------------------------------------------------------------------------------
// Удаление элемента из дерева (итеративный)
void testDeleteKey()
{
	std::cout << '\n' << "----- Удаление элемента из дерева (итеративный) -----" << '\n';

	BinarySearchTree<int> tree;
	tree.insert(7);

	// Элемент не найден - нет
	std::cout << "\nИсходное дерево: ";
	tree.print(std::cout);
	bool resultSearch1 = tree.deleteKey(5);
	printTest(tree, resultSearch1);

	// У элемента нет наследников, элемент является корнем - да
	std::cout << "\nИсходное дерево: ";
	tree.print(std::cout);
	bool resultSearch2 = tree.deleteKey(7);
	printTest(tree, resultSearch2);

	tree.insert(7);
	tree.insert(5);

	// У элемента нет наследников, элемент не является корнем - да
	std::cout << "\nИсходное дерево: ";
	tree.print(std::cout);
	bool resultSearch3 = tree.deleteKey(5);
	printTest(tree, resultSearch3);

	tree.insert(5);

	// У элемента есть один наследник слева, элемент является корнем - да
	std::cout << "\nИсходное дерево: ";
	tree.print(std::cout);
	bool resultSearch4 = tree.deleteKey(7);
	printTest(tree, resultSearch4);

	tree.insert(7);
	tree.insert(6);

	// У элемента есть один наследник слева, элемент не является корнем - да
	std::cout << "\nИсходное дерево: ";
	tree.print(std::cout);
	bool resultSearch5 = tree.deleteKey(7);
	printTest(tree, resultSearch5);

	// У элемента есть один наследник справа, элемент является корнем - да
	std::cout << "\nИсходное дерево: ";
	tree.print(std::cout);
	bool resultSearch6 = tree.deleteKey(5);
	printTest(tree, resultSearch6);

	tree.insert(0);
	tree.insert(1);

	// У элемента есть один наследник справа, элемент не является корнем - да
	std::cout << "\nИсходное дерево: ";
	tree.print(std::cout);
	bool resultSearch7 = tree.deleteKey(0);
	printTest(tree, resultSearch7);

	tree.insert(0);
	tree.insert(5);
	tree.insert(2);

	// У элемента есть оба наследника, у последующего узла нет наследников - да
	std::cout << "\nИсходное дерево: ";
	tree.print(std::cout);
	bool resultSearch8 = tree.deleteKey(1);
	printTest(tree, resultSearch8);

	tree.insert(3);
	tree.insert(4);

	// У элемента есть оба наследника, у последующего узла есть один наследник (справа) - да
	std::cout << "\nИсходное дерево: ";
	tree.print(std::cout);
	bool resultSearch9 = tree.deleteKey(2);
	printTest(tree, resultSearch9);
}

//-----------------------------------------------------------------------------------------------------------------------
// Печать строкового изображения дерева
void testPrint(BinarySearchTree<int>& tree)
{
	std::cout << '\n' << "----- Печать строкового изображения дерева -----" << '\n';

	BinarySearchTree<int> emptyTree;

	// Пустое дерево
	std::cout << "\nДерево: ";
	emptyTree.print(std::cout);

	// Непустое дерево
	std::cout << "\nДерево: ";
	tree.print(std::cout);
}

//-----------------------------------------------------------------------------------------------------------------------
// Определение количества узлов дерева (рекурсивный)
void testGetCount(BinarySearchTree<int>&tree)
{
	std::cout << '\n' << "----- Определения количества узлов дерева (рекурсивный) -----" << '\n';

	// Подсчёт узлов в дереве - да
	bool resultSearch1 = (tree.getCount() == 7);
	printTest(tree, resultSearch1);
}

//-----------------------------------------------------------------------------------------------------------------------
// Определение высоты дерева (рекурсивный)
void testGetHeight(BinarySearchTree<int>& tree)
{
	std::cout << '\n' << "----- Определения высоты дерева (рекурсивный) -----" << '\n';

	// Определение высоты дерева - да
	bool resultSearch1 = (tree.getHeight() == 2);
	printTest(tree, resultSearch1);

	// Определение высоты дерева после добавления элемента на новый уровень - да
	tree.insert(1);
	bool resultSearch2 = (tree.getHeight() == 3);
	printTest(tree, resultSearch2);
	tree.deleteKey(1);
}

//-----------------------------------------------------------------------------------------------------------------------
// Инфиксный обход дерева (итеративный)
void testIterativeInorderWalk(BinarySearchTree<int>& tree)
{
	std::cout << '\n' << "----- Инфиксный обход дерева (итеративный) -----" << '\n';

	BinarySearchTree<int> emptyTree;

	// Инфиксный обход пустого дерева
	std::cout << "\nДерево: ";
	emptyTree.print(std::cout);
	std::cout << "Обход: ";
	emptyTree.iterativeInorderWalk();

	// Инфиксный обход непустого дерева
	std::cout << "\nДерево: ";
	tree.print(std::cout);
	std::cout << "Обход: ";
	tree.iterativeInorderWalk();
}

//-----------------------------------------------------------------------------------------------------------------------
// Инфиксный обход дерева (рекурсивный)
void testInorderWalk(BinarySearchTree<int>& tree)
{
	std::cout << '\n' << "----- Инфиксный обход дерева (рекурсивный) -----" << '\n';

	BinarySearchTree<int> emptyTree;

	// Инфиксный обход пустого дерева
	std::cout << "\nДерево: ";
	emptyTree.print(std::cout);
	std::cout << "Обход: ";
	emptyTree.inorderWalk();

	// Инфиксный обход непустого дерева
	std::cout << "\nДерево: ";
	tree.print(std::cout);
	std::cout << "Обход: ";
	tree.inorderWalk();
}