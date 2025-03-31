#ifndef _TEST_FUNCTION
#define _TEST_FUNCTION
#include "BinarySearchTree.h"

//
// Тесты для бинарного дерева поиска - класс BinarySearchTree
//

// Поиск по ключу (итеративный)
void testIterativeSearch(BinarySearchTree<int>& tree);

// Вставка нового элемента в дерево (итеративный)
void testInsert(BinarySearchTree<int>& tree);

// Удаление элемента из дерева (итеративный)
void testDeleteKey();

// Печать строкового изображения дерева
void testPrint(BinarySearchTree<int>& tree);

// Определения количества узлов дерева (рекурсивный)
void testGetCount(BinarySearchTree<int>& tree);

// Определения высоты дерева (рекурсивный)
void testGetHeight(BinarySearchTree<int>& tree);

// Инфиксный обход дерева (итеративный)
void testIterativeInorderWalk(BinarySearchTree<int>& tree);

// Инфиксный обход дерева (рекурсивный)
void testInorderWalk(BinarySearchTree<int>& tree);

// вывод результата тестирования
void printTest(BinarySearchTree<int>& tree, bool result = true);

#endif