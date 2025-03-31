#ifndef _TEST_FUNCTION
#define _TEST_FUNCTION
#include "Stack.h"

//
// Тесты для стека - "ограниченный" стек - класс StackArray
//

// Анализ правильности расстановки скобок
void testCheckBalanceBrackets();

// Перевод арифметического выражения из инфиксной формы в постфиксную
void testGetPostfix();

// Вычисление значения арифметического выражения в постфиксной форме
void testEvaluatePostfix();

// вывод результата тестирования
void testPrint(std::string str, bool result);

#endif