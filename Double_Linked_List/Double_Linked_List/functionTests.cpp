#include "DoubleLinkedList.h";

void testInsertTail()
{
	// Создание списков для проверки
	DoubleLinkedList sourceList1;
	sourceList1.insertHead(3);
	sourceList1.insertHead(2);
	sourceList1.insertHead(1);
	DoubleLinkedList sourceList2;
	sourceList2.insertHead(1);
	DoubleLinkedList testList1;
	testList1.insertHead(2);
	testList1.insertHead(1);
	DoubleLinkedList testList2;

	// Выполнение методов/функций и Проверка
	std::string answer = "";
	testList1.insertTail(3);
	answer = (testList1 == sourceList1) ? "пройден" : "не пройден";
	std::cout << "Проверка метода insertTail: тест " << answer << '\n';
	testList2.insertTail(1);
	answer = (testList2 == sourceList2) ? "пройден" : "не пройден";
	std::cout << "Проверка метода insertTail: тест " << answer << '\n';
}

void testDeleteTail()
{
	// Создание списков для проверки
	DoubleLinkedList testList1;
	testList1.insertHead(2);
	testList1.insertHead(1);
	DoubleLinkedList testList2;

	// Выполнение методов/функций и Проверка
	std::string answer = "";
	answer = (testList1.deleteTail() == true) ? "пройден" : "не пройден";
	std::cout << "Проверка метода deleteTail: тест " << answer << '\n';
	answer = (testList2.deleteTail() == false) ? "пройден" : "не пройден";
	std::cout << "Проверка метода deleteTail: тест " << answer << '\n';
}

void testDeleteItem()
{
	// Создание списков для проверки
	DoubleLinkedList testList1;
	testList1.insertHead(3);
	testList1.insertHead(2);
	testList1.insertHead(1);

	// Выполнение методов/функций и Проверка
	std::string answer = "";
	answer = (testList1.deleteItem(3) == true) ? "пройден" : "не пройден";
	std::cout << "Проверка метода deleteItem: тест " << answer << '\n';
	answer = (testList1.deleteItem(1) == true) ? "пройден" : "не пройден";
	std::cout << "Проверка метода deleteItem: тест " << answer << '\n';
	answer = (testList1.deleteItem(4) == false) ? "пройден" : "не пройден";
	std::cout << "Проверка метода deleteItem: тест " << answer << '\n';
}

void testReplaceItem()
{
	// Создание списков для проверки
	DoubleLinkedList testList1;
	testList1.insertHead(2);
	testList1.insertHead(1);

	// Выполнение методов/функций и Проверка
	std::string answer = "";
	answer = (testList1.replaceItem(2, 3) == true) ? "пройден" : "не пройден";
	std::cout << "Проверка метода replaceItem: тест " << answer << '\n';
	answer = (testList1.replaceItem(4, 5) == false) ? "пройден" : "не пройден";
	std::cout << "Проверка метода replaceItem: тест " << answer << '\n';
}

void testAdd()
{
	// Создание списков для проверки
	DoubleLinkedList sourceList1;
	sourceList1.insertHead(4);
	sourceList1.insertHead(3);
	sourceList1.insertHead(2);
	sourceList1.insertHead(1);
	DoubleLinkedList testList1;
	testList1.insertHead(2);
	testList1.insertHead(1);
	DoubleLinkedList testList2;
	testList2.insertHead(4);
	testList2.insertHead(3);
	DoubleLinkedList testList3;
	DoubleLinkedList emptyList4;

	// Выполнение методов/функций и Проверка
	std::string answer = "";
	testList1.add(testList2);
	answer = ((testList1 == sourceList1) && (testList2 == emptyList4)) ? "пройден" : "не пройден";
	std::cout << "Проверка метода add: тест " << answer << '\n';
	testList3.add(testList1);
	answer = ((testList3 == sourceList1) && (testList1 == emptyList4)) ? "пройден" : "не пройден";
	std::cout << "Проверка метода add: тест " << answer << '\n';
}

void testCompareOperator()
{
	// Создание списков для проверки
	DoubleLinkedList testList1;
	testList1.insertHead(2);
	testList1.insertHead(1);
	DoubleLinkedList testList2;
	testList2.insertHead(2);
	testList2.insertHead(1);
	DoubleLinkedList testList3;
	testList3.insertHead(1);

	// Выполнение методов/функций и Проверка
	std::string answer = "";
	answer = ((testList1 == testList2) == true) ? "пройден" : "не пройден";
	std::cout << "Проверка оператора сравнения ==: тест " << answer << '\n';
	answer = ((testList1 == testList3) == false) ? "пройден" : "не пройден";
	std::cout << "Проверка оператора сравнения ==: тест " << answer << '\n';
}

void testOutOperator()
{
	// Создание списков для проверки
	DoubleLinkedList testList1;
	testList1.insertHead(2);
	testList1.insertHead(1);
	DoubleLinkedList testList2;

	// Выполнение методов/функций и Проверка
	std::cout << "Ожидаемый результат: 1 2        " << "Полученный результат: " << testList1 << '\n';
	std::cout << "Ожидаемый результат: пустой список            " << "Полученный результат: " << testList2 << '\n';
}