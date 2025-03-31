#include "DoubleLinkedList.h";

void testInsertTail()
{
	// �������� ������� ��� ��������
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

	// ���������� �������/������� � ��������
	std::string answer = "";
	testList1.insertTail(3);
	answer = (testList1 == sourceList1) ? "�������" : "�� �������";
	std::cout << "�������� ������ insertTail: ���� " << answer << '\n';
	testList2.insertTail(1);
	answer = (testList2 == sourceList2) ? "�������" : "�� �������";
	std::cout << "�������� ������ insertTail: ���� " << answer << '\n';
}

void testDeleteTail()
{
	// �������� ������� ��� ��������
	DoubleLinkedList testList1;
	testList1.insertHead(2);
	testList1.insertHead(1);
	DoubleLinkedList testList2;

	// ���������� �������/������� � ��������
	std::string answer = "";
	answer = (testList1.deleteTail() == true) ? "�������" : "�� �������";
	std::cout << "�������� ������ deleteTail: ���� " << answer << '\n';
	answer = (testList2.deleteTail() == false) ? "�������" : "�� �������";
	std::cout << "�������� ������ deleteTail: ���� " << answer << '\n';
}

void testDeleteItem()
{
	// �������� ������� ��� ��������
	DoubleLinkedList testList1;
	testList1.insertHead(3);
	testList1.insertHead(2);
	testList1.insertHead(1);

	// ���������� �������/������� � ��������
	std::string answer = "";
	answer = (testList1.deleteItem(3) == true) ? "�������" : "�� �������";
	std::cout << "�������� ������ deleteItem: ���� " << answer << '\n';
	answer = (testList1.deleteItem(1) == true) ? "�������" : "�� �������";
	std::cout << "�������� ������ deleteItem: ���� " << answer << '\n';
	answer = (testList1.deleteItem(4) == false) ? "�������" : "�� �������";
	std::cout << "�������� ������ deleteItem: ���� " << answer << '\n';
}

void testReplaceItem()
{
	// �������� ������� ��� ��������
	DoubleLinkedList testList1;
	testList1.insertHead(2);
	testList1.insertHead(1);

	// ���������� �������/������� � ��������
	std::string answer = "";
	answer = (testList1.replaceItem(2, 3) == true) ? "�������" : "�� �������";
	std::cout << "�������� ������ replaceItem: ���� " << answer << '\n';
	answer = (testList1.replaceItem(4, 5) == false) ? "�������" : "�� �������";
	std::cout << "�������� ������ replaceItem: ���� " << answer << '\n';
}

void testAdd()
{
	// �������� ������� ��� ��������
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

	// ���������� �������/������� � ��������
	std::string answer = "";
	testList1.add(testList2);
	answer = ((testList1 == sourceList1) && (testList2 == emptyList4)) ? "�������" : "�� �������";
	std::cout << "�������� ������ add: ���� " << answer << '\n';
	testList3.add(testList1);
	answer = ((testList3 == sourceList1) && (testList1 == emptyList4)) ? "�������" : "�� �������";
	std::cout << "�������� ������ add: ���� " << answer << '\n';
}

void testCompareOperator()
{
	// �������� ������� ��� ��������
	DoubleLinkedList testList1;
	testList1.insertHead(2);
	testList1.insertHead(1);
	DoubleLinkedList testList2;
	testList2.insertHead(2);
	testList2.insertHead(1);
	DoubleLinkedList testList3;
	testList3.insertHead(1);

	// ���������� �������/������� � ��������
	std::string answer = "";
	answer = ((testList1 == testList2) == true) ? "�������" : "�� �������";
	std::cout << "�������� ��������� ��������� ==: ���� " << answer << '\n';
	answer = ((testList1 == testList3) == false) ? "�������" : "�� �������";
	std::cout << "�������� ��������� ��������� ==: ���� " << answer << '\n';
}

void testOutOperator()
{
	// �������� ������� ��� ��������
	DoubleLinkedList testList1;
	testList1.insertHead(2);
	testList1.insertHead(1);
	DoubleLinkedList testList2;

	// ���������� �������/������� � ��������
	std::cout << "��������� ���������: 1 2        " << "���������� ���������: " << testList1 << '\n';
	std::cout << "��������� ���������: ������ ������            " << "���������� ���������: " << testList2 << '\n';
}