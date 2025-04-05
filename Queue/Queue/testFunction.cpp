#include "BinarySearchTree.h"
#include "Queue.h"
#include <iostream>

//
// Тесты для очереди - класс QueueArray
// Тесты для итеративных алгоритмов обхода двоичных деревьев - класс BinarySearchTree
//

//-----------------------------------------------------------------------------------------------------------------------
// Вывод результата тестирования
void printTest(BinarySearchTree<int>& tree1, BinarySearchTree<int>& tree2, bool result = true)
{
	std::cout << "result = " << result << std::endl;
	std::cout << "Первое дерево: ";
	tree1.print(std::cout);
	std::cout << "Второе дерево: ";
	tree2.print(std::cout);
}

//-----------------------------------------------------------------------------------------------------------------------
// Добавление элемента
void testEnQueue()
{
	std::cout << "\n----- Добавление элемента -----\n";

	QueueArray<int> queue(2);

	// Добавление элемента, очередь пустая
	std::cout << "\nИсходная очередь: ";
	queue.print();
	queue.enQueue(1);
	std::cout << "Очередь после добавления элемента: ";
	queue.print();

	// Добавление элемента, элементы есть в очереди
	std::cout << "\nИсходная очередь: ";
	queue.print();
	queue.enQueue(2);
	std::cout << "Очередь после добавления элемента: ";
	queue.print();

	// Добавление элемента после удаления из заполненной очереди элемента
	queue.deQueue();
	std::cout << "\nИсходная очередь: ";
	queue.print();
	queue.enQueue(3);
	std::cout << "Очередь после добавления элемента: ";
	queue.print();
}

//-----------------------------------------------------------------------------------------------------------------------
// Удаление и возвращение элемента
void testDeQueue()
{
	std::cout << "\n----- Удаление и возвращение элемента -----\n";

	QueueArray<int> queue(2);
	queue.enQueue(1);
	queue.enQueue(2);

	// Удаление элемента, очередь заполненная
	std::cout << "\nИсходная очередь: ";
	queue.print();
	queue.deQueue();
	std::cout << "Очередь после удаления элемента: ";
	queue.print();

	// Удаление элемента, очередь не до конца заполненная
	std::cout << "\nИсходная очередь: ";
	queue.print();
	queue.deQueue();
	std::cout << "Очередь после удаления элемента: ";
	queue.print();

	// Удаление элемента после после получения пустой очереди и добавления в неё элемента
	queue.enQueue(3);
	std::cout << "\nИсходная очередь: ";
	queue.print();
	queue.deQueue();
	std::cout << "Очередь после удаления элемента: ";
	queue.print();
}

//-----------------------------------------------------------------------------------------------------------------------
// Обход дерева в ширину (итеративный)
void testIterativeBreadthWalk()
{
	std::cout << "\n----- Обход дерева в ширину (итеративный) -----\n";

	BinarySearchTree<int> tree;
	tree.insert(7);
	tree.insert(4);
	tree.insert(9);
	tree.insert(2);
	tree.insert(5);
	tree.insert(8);
	tree.insert(10);
	BinarySearchTree<int> emptyTree;

	// Обход в ширину пустого дерева
	std::cout << "\nДерево: ";
	emptyTree.print(std::cout);
	std::cout << "Обход: ";
	emptyTree.iterativeBreadthWalk();

	// Обход в ширину непустого дерева
	std::cout << "\nДерево: ";
	tree.print(std::cout);
	std::cout << "Обход: ";
	tree.iterativeBreadthWalk();
}

//-----------------------------------------------------------------------------------------------------------------------
// Метод, определяющий, являются ли два дерева похожими
void testCheckSimilarityTrees()
{
	std::cout << "\n----- Метод, определяющий, являются ли два дерева похожими -----\n";

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

	// Деревья имеют одинаковый набор ключей - да
	bool resultSearch1 = tree1.checkSimilarityTrees(tree2);
	printTest(tree1, tree2, resultSearch1);

	// Деревья имеют разный набор ключей одинаковой длины - нет
	bool resultSearch2 = tree1.checkSimilarityTrees(tree3);
	printTest(tree1, tree3, resultSearch2);

	// Деревья имеют разный набор ключей разной длины - нет
	bool resultSearch3 = tree1.checkSimilarityTrees(tree4);
	printTest(tree1, tree4, resultSearch3);

	// Одно из деревьев пустое - нет
	bool resultSearch4 = tree1.checkSimilarityTrees(emptyTree2);
	printTest(tree1, emptyTree2, resultSearch4);

	// Оба дерева пустые - да
	bool resultSearch5 = emptyTree1.checkSimilarityTrees(emptyTree2);
	printTest(emptyTree1, emptyTree2, resultSearch5);
}

//-----------------------------------------------------------------------------------------------------------------------
// Метод, определяющий есть одинаковые ключи в двух деревьях поиска
void testCheckForIdenticalKeys()
{
	std::cout << "\n----- Метод, определяющий есть одинаковые ключи в двух деревьях поиска -----\n";

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

	// Деревья имеют разный набор ключей - нет
	bool resultSearch1 = tree1.checkForIdenticalKeys(tree2);
	printTest(tree1, tree2, resultSearch1);

	// Деревья имеют хотя бы один одинаковый ключ - да
	bool resultSearch2 = tree1.checkForIdenticalKeys(tree3);
	printTest(tree1, tree3, resultSearch2);

	// Одно из деревьев пустое - нет
	bool resultSearch3 = tree1.checkForIdenticalKeys(emptyTree1);
	printTest(tree1, emptyTree1, resultSearch3);

	// Оба дерева пустые - нет
	bool resultSearch4 = emptyTree1.checkForIdenticalKeys(emptyTree2);
	printTest(emptyTree1, emptyTree2, resultSearch4);
}