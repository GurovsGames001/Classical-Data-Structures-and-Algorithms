#ifndef _TEST_FUNCTION
#define _TEST_FUNCTION
#include "BinarySearchTree.h"
#include "Queue.h"

//
// Тесты для очереди - класс QueueArray
// Тесты для итеративных алгоритмов обхода двоичных деревьев - класс BinarySearchTree
//

// Добавление элемента
void testEnQueue();

// Удаление и возвращение элемента
void testDeQueue();

// Обход дерева в ширину (итеративный)
void testIterativeBreadthWalk();

// Метод, определяющий, являются ли два дерева похожими
void testCheckSimilarityTrees();

// Метод, определяющий есть одинаковые ключи в двух деревьях поиска
void testCheckForIdenticalKeys();

// Вывод результата тестирования
void printTest(BinarySearchTree<int>& tree1, BinarySearchTree<int>& tree2, bool result = true);

#endif