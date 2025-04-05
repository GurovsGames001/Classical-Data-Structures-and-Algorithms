#include "SinglyOrderedList.h"
#include <iostream>

//
// Тесты для словаря - односвязный упорядоченный список - класс SinglyOrderedList
//

//-----------------------------------------------------------------------------------------------------------------------
// вывод словаря (для тестирования)
// вывод элементов односвязного списка 
void testPrint(SinglyOrderedList & list, bool result = true) 
{
	std::cout << std::endl <<"result =" << result << ' ';
	list.print();
}

//-----------------------------------------------------------------------------------------------------------------------
// добавление слов в словарь
void testInsert()
{
	std::cout << std::endl << "----- добавление слов в список-----" << std::endl;

	// создание пустого списка
	SinglyOrderedList list;

	// добавление первого узла - да
	bool resulInsert10 = list.insert(10);
	testPrint(list, resulInsert10);

	// добавление перед первым - да
	bool resulInsert1 = list.insert(1);
	testPrint(list, resulInsert1);

	// добавление последнего узла - да
	bool resulInsert20 = list.insert(20);
	testPrint(list, resulInsert20);

	// добавление между первым и вторым узлами - да
	bool resulInsert15 = list.insert(15);
	testPrint(list, resulInsert15);

	// добавление существующего в списке элемента - нет
	bool resulInsert15x = list.insert(15);
	testPrint(list, resulInsert15x);
}

//-----------------------------------------------------------------------------------------------------------------------
// поиск слов в словаре
void testSearch()
{
	std::cout << std::endl << "----- поиск слов в словаре-----" << std::endl;

	// создание пустого списка
	SinglyOrderedList list;

	{
		// добавление первого узла
		bool resulInsert10 = list.insert(10);
		// добавление перед первым
		bool resulInsert1 = list.insert(1);
		// добавление последним
		bool resulInsert20 = list.insert(20);
		// добавление между первым и вторым
		bool resulInsert15 = list.insert(15);
	}

	list.print();

	// поиск - элемент перед первым - нет
	bool resultSearch0 = list.search(0);
	testPrint(list, resultSearch0);
	// поиск - элемент первый - есть
	bool resultSearch1 = list.search(1);
	testPrint(list, resultSearch1);
	// поиск - элемент средний - есть
	bool resultSearch10 = list.search(10);
	testPrint(list, resultSearch10);
	// поиск - элемент средний - нет 
	bool resultSearch11 = list.search(11);
	testPrint(list, resultSearch11);
	// поиск - элемент за последним - нет 
	bool resultSearch21 = list.search(21);
	testPrint(list, resultSearch21);
}
//-----------------------------------------------------------------------------------------------------------------------
// удаление слов  из словаря
void testDeleteKey()
{
	std::cout << std::endl << "----- удаление слов из словаря -----" << std::endl;

	// создание пустого списка
	SinglyOrderedList list;
	{
		// добавление первого узла
		bool resulInsert10 = list.insert(10);
		// добавление перед первым
		bool resulInsert1 = list.insert(1);
		// добавление последним
		bool resulInsert20 = list.insert(20);
		// добавление между первым и вторым
		bool resulInsert15 = list.insert(15);
	}

	list.print();

	// удаление - элемент перед первым - нет
	bool resultDeleteKey0 = list.deleteItem(0);
	testPrint(list, resultDeleteKey0);

	// удаление - элемент первый - есть
	bool resultDeleteKey1 = list.deleteItem(1);
	testPrint(list, resultDeleteKey1);

	// поиск - элемент первый - НЕТ
	bool resultSearch1 = list.search(1);
	
	// добавление перед первым - восстановление удаленного
	bool resulInsert1 = list.insert(1);

	// удаление - элемент средний - есть
	bool resultDeleteKey10 = list.deleteItem(10);
	testPrint(list, resultDeleteKey10);

	// удалениие - элемент средний - нет 
	bool resultDeleteKey11 = list.deleteItem(11);
	testPrint(list, resultDeleteKey11);

	// удаление - элемент за последним - нет 
	bool resultSearch21 = list.deleteItem(21);
	testPrint(list, resultSearch21);
}
//-----------------------------------------------------------------------------------------------------------------------
// объединение словарей
void testMerge()
{
	std::cout << std::endl << "----- объединение словарей -----" << std::endl;

	// создание списков для теста
	SinglyOrderedList testList1;
	SinglyOrderedList testList2;
	testList1.insert(1);
	testList1.insert(4);
	testList2.insert(0);
	testList2.insert(2);
	testList2.insert(4);
	testList2.insert(5);
	testList2.insert(6);
	SinglyOrderedList testList3;

	// создание спискoв для проверки
	SinglyOrderedList sourceList1;
	sourceList1.insert(0);
	sourceList1.insert(1);
	sourceList1.insert(2);
	sourceList1.insert(4);
	sourceList1.insert(5);
	sourceList1.insert(6);
	SinglyOrderedList emptyList;

	testList1.print();
	testList2.print();

	// объединение двух непустых списков (вставка головы, элементов в середину и в хвост; удаление совпадающих элементов) - да
	testList1.merge(testList2);
	bool resultMerge0 = ((testList1 == sourceList1) && (testList2 == emptyList));
	testPrint(testList1, resultMerge0);

	// объединение пустого и непустого списков - да
	testList3.merge(testList1);
	bool resultMerge1 = ((testList3 == sourceList1) && (testList1 == emptyList));
	testPrint(testList3, resultMerge1);
}
//-----------------------------------------------------------------------------------------------------------------------
// вычитание словарей
void testSubtract()
{
	std::cout << std::endl << "----- вычитание словарей -----" << std::endl;

	// создание списков для теста
	SinglyOrderedList testList1;
	SinglyOrderedList testList2;
	testList1.insert(0);
	testList1.insert(1);
	testList1.insert(2);
	testList1.insert(3);
	testList1.insert(4);
	testList1.insert(5);
	testList2.insert(0);
	testList2.insert(1);
	testList2.insert(3);
	testList2.insert(5);

	// создание спискoв для проверки
	SinglyOrderedList sourceList1;
	SinglyOrderedList sourceList2(testList2);
	sourceList1.insert(2);
	sourceList1.insert(4);

	testList1.print();
	testList2.print();

	// вычитание двух непустых списков (удаление головы, элементов в середине и хвоста) - да
	testList1.subtract(testList2);
	bool resultMerge0 = ((testList1 == sourceList1) && (testList2 == sourceList2));
	testPrint(testList1, resultMerge0);
}
//-----------------------------------------------------------------------------------------------------------------------
// пересечение словарей
void testCross()
{
	std::cout << std::endl << "----- пересечение словарей -----" << std::endl;

	// создание списков для теста
	SinglyOrderedList testList1;
	SinglyOrderedList testList2;
	SinglyOrderedList testList3;
	testList1.insert(0);
	testList1.insert(1);
	testList1.insert(2);
	testList1.insert(3);
	testList1.insert(4);
	testList2.insert(0);
	testList2.insert(2);
	testList2.insert(4);
	testList2.insert(9);
	testList3.insert(5);
	testList3.insert(6);

	// создание спискoв для проверки
	SinglyOrderedList emptyList;
	SinglyOrderedList sourceList1;
	SinglyOrderedList sourceList2(testList1);
	SinglyOrderedList sourceList3(testList2);
	SinglyOrderedList sourceList4(testList3);
	sourceList1.insert(0);
	sourceList1.insert(2);
	sourceList1.insert(4);

	testList1.print();
	testList2.print();
	testList3.print();

	// пересечение двух непустых списков с совпадающими элементами - да
	SinglyOrderedList list1;
	list1 = cross(testList1, testList2);
	bool resultMerge0 = ((list1 == sourceList1) && (testList1 == sourceList2) && (testList2 == sourceList3));
	testPrint(list1, resultMerge0);

	// пересечение двух непустых списков с несовпадающими элементами - да
	SinglyOrderedList list2;
	list2 = cross(testList1, testList3);
	bool resultMerge1 = ((list2 == emptyList) && (testList1 == sourceList2) && (testList3 == sourceList4));
	testPrint(list2, resultMerge1);
}