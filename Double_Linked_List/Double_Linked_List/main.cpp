//
// ������� ������������� ������ DoubleLinkedList
//
#include "DoubleLinkedList.h"
#include "functionTests.h"
#include <iostream>
#include <string>

int main()
{
	setlocale(LC_ALL, "rus");

	// �������-�����
	testInsertTail();
	testDeleteTail();
	testDeleteItem();
	testReplaceItem();
	testAdd();
	testCompareOperator();
	testOutOperator();

	return 0;
}