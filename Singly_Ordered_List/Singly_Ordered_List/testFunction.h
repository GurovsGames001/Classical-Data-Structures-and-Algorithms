#ifndef _TEST_FUNCTION
#define _TEST_FUNCTION
#include "SinglyOrderedList.h"

//
// Тесты для словаря - односвязный упорядоченный список - класс SinglyOrderedList
//

// добавление слова в словарь
void testInsert();

// поиск слова в словаре
void testSearch();

// удаление слова из словаря
void testDeleteKey();

// объединение словарей
void testMerge();

// вычитание словарей
void testSubtract();

// пересечение словарей
void testCross();

// вывод словаря (для тестирования)
void testPrint(SinglyOrderedList& list, bool result);

#endif