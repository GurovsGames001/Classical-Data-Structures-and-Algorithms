#include "Stack.h"
#include "functions.h"
#include <iostream>

//
// Тесты для словаря - односвязный упорядоченный список - класс SinglyOrderedList
//

//-----------------------------------------------------------------------------------------------------------------------
// Вывод результата тестирования
void testPrint(std::string str, bool result = true)
{
	std::cout << std::endl << "result = " << result << " Тестовая строка: " << str << '\n';
}

//-----------------------------------------------------------------------------------------------------------------------
// Анализ правильности расстановки скобок
void testCheckBalanceBrackets()
{
	std::cout << '\n' << "----- Анализ правильности расстановки скобок -----" << '\n';

	std::string str1 = "(())(){{}}{}[[]][]";
	std::string str2 = "{}()()(";
	std::string str3 = "[]{}())";
	std::string str4 = "([{()}])";

	// Правильная расстановка скобок, три вида скобок, вложенность - да;
	bool resultCheck1 = checkBalanceBrackets(str1, 2);
	testPrint(str1, resultCheck1);

	// Лишняя открывающая скобка - нет;
	bool resultCheck2 = checkBalanceBrackets(str2, 1);
	testPrint(str2, resultCheck2);

	// Лишняя закрывающая скобка - нет;
	bool resultCheck3 = checkBalanceBrackets(str3, 1);
	testPrint(str3, resultCheck3);

	// Правильная расстановка скобок, вложенность с несколькими видами скобок - да;
	bool resultCheck4 = checkBalanceBrackets(str4, 4);
	testPrint(str4, resultCheck4);
}

//-----------------------------------------------------------------------------------------------------------------------
// Перевод арифметического выражения из инфиксной формы в постфиксную
void testGetPostfix()
{
	std::cout << '\n' << "----- Перевод арифметического выражения из инфиксной формы в постфиксную -----" << '\n';

	std::string str1 = "((4+5*(6-2))*9)/2";
	std::string str2 = "((4+5*(6-2f))*9#)/2";
	std::string str3 = "(((4+5*(6-2))*9)/2";
	std::string str4 = "((4+5*(6-2)))*9)/2";
	
	std::string emptyStr1 = "";
	std::string emptyStr2 = "";
	std::string emptyStr3 = "";
	std::string emptyStr4 = "";

	// Правильная инфиксная форма, все виды операторов, вложенность - да;
	bool resultGet1 = getPostfixFromInfix(str1, emptyStr1, 20);
	testPrint(str1, resultGet1);

	try
	{
		// Недопустимые символы - исключение;
		bool resultGet2 = getPostfixFromInfix(str2, emptyStr2, 20);
		testPrint(str2, resultGet2);
	}

	catch (std::exception& error)
	{
		std::cerr << error.what() << '\n';
	}

	try
	{
		// Лишняя открывающая скобка - исключение;
		bool resultGet3 = getPostfixFromInfix(str3, emptyStr3, 20);
		testPrint(str3, resultGet3);
	}

	catch (std::exception& error)
	{
		std::cerr << error.what() << '\n';
	}

	try
	{
		// Лишняя закрывающая скобка - исключение;
		bool resultGet4 = getPostfixFromInfix(str4, emptyStr4, 20);
		testPrint(str4, resultGet4);
	}

	catch (std::exception& error)
	{
		std::cerr << error.what() << '\n';
	}
}

//-----------------------------------------------------------------------------------------------------------------------
// Вычисление значения арифметического выражения в постфиксной форме
void testEvaluatePostfix()
{
	std::cout << '\n' << "----- Вычисление значения арифметического выражения в постфиксной форме -----" << '\n';

	std::string str1 = "((4+5*(6-2))*9)/2";

	// Правильная инфиксная форма, все виды операторов, вложенность - да;
	bool resultEvaluate1 = (evaluatePostfix(str1, 20) == 108);
	testPrint(str1, resultEvaluate1);
}