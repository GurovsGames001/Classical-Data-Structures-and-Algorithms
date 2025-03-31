#include "SinglyOrderedList.h"
#include <iostream>

//
// ����� ��� ������� - ����������� ������������� ������ - ����� SinglyOrderedList
//

//-----------------------------------------------------------------------------------------------------------------------
// ����� ������� (��� ������������)
// ����� ��������� ������������ ������ 
void testPrint(SinglyOrderedList & list, bool result = true) 
{
	std::cout << std::endl <<"result =" << result << ' ';
	list.print();
}

//-----------------------------------------------------------------------------------------------------------------------
// ���������� ���� � �������
void testInsert()
{
	std::cout << std::endl << "----- ���������� ���� � ������-----" << std::endl;

	// �������� ������� ������
	SinglyOrderedList list;

	// ���������� ������� ���� - ��
	bool resulInsert10 = list.insert(10);
	testPrint(list, resulInsert10);

	// ���������� ����� ������ - ��
	bool resulInsert1 = list.insert(1);
	testPrint(list, resulInsert1);

	// ���������� ���������� ���� - ��
	bool resulInsert20 = list.insert(20);
	testPrint(list, resulInsert20);

	// ���������� ����� ������ � ������ ������ - ��
	bool resulInsert15 = list.insert(15);
	testPrint(list, resulInsert15);

	// ���������� ������������� � ������ �������� - ���
	bool resulInsert15x = list.insert(15);
	testPrint(list, resulInsert15x);
}

//-----------------------------------------------------------------------------------------------------------------------
// ����� ���� � �������
void testSearch()
{
	std::cout << std::endl << "----- ����� ���� � �������-----" << std::endl;

	// �������� ������� ������
	SinglyOrderedList list;

	{
		// ���������� ������� ����
		bool resulInsert10 = list.insert(10);
		// ���������� ����� ������
		bool resulInsert1 = list.insert(1);
		// ���������� ���������
		bool resulInsert20 = list.insert(20);
		// ���������� ����� ������ � ������
		bool resulInsert15 = list.insert(15);
	}

	list.print();

	// ����� - ������� ����� ������ - ���
	bool resultSearch0 = list.search(0);
	testPrint(list, resultSearch0);
	// ����� - ������� ������ - ����
	bool resultSearch1 = list.search(1);
	testPrint(list, resultSearch1);
	// ����� - ������� ������� - ����
	bool resultSearch10 = list.search(10);
	testPrint(list, resultSearch10);
	// ����� - ������� ������� - ��� 
	bool resultSearch11 = list.search(11);
	testPrint(list, resultSearch11);
	// ����� - ������� �� ��������� - ��� 
	bool resultSearch21 = list.search(21);
	testPrint(list, resultSearch21);
}
//-----------------------------------------------------------------------------------------------------------------------
// �������� ����  �� �������
void testDeleteKey()
{
	std::cout << std::endl << "----- �������� ���� �� ������� -----" << std::endl;

	// �������� ������� ������
	SinglyOrderedList list;
	{
		// ���������� ������� ����
		bool resulInsert10 = list.insert(10);
		// ���������� ����� ������
		bool resulInsert1 = list.insert(1);
		// ���������� ���������
		bool resulInsert20 = list.insert(20);
		// ���������� ����� ������ � ������
		bool resulInsert15 = list.insert(15);
	}

	list.print();

	// �������� - ������� ����� ������ - ���
	bool resultDeleteKey0 = list.deleteItem(0);
	testPrint(list, resultDeleteKey0);

	// �������� - ������� ������ - ����
	bool resultDeleteKey1 = list.deleteItem(1);
	testPrint(list, resultDeleteKey1);

	// ����� - ������� ������ - ���
	bool resultSearch1 = list.search(1);
	
	// ���������� ����� ������ - �������������� ����������
	bool resulInsert1 = list.insert(1);

	// �������� - ������� ������� - ����
	bool resultDeleteKey10 = list.deleteItem(10);
	testPrint(list, resultDeleteKey10);

	// ��������� - ������� ������� - ��� 
	bool resultDeleteKey11 = list.deleteItem(11);
	testPrint(list, resultDeleteKey11);

	// �������� - ������� �� ��������� - ��� 
	bool resultSearch21 = list.deleteItem(21);
	testPrint(list, resultSearch21);
}
//-----------------------------------------------------------------------------------------------------------------------
// ����������� ��������
void testMerge()
{
	std::cout << std::endl << "----- ����������� �������� -----" << std::endl;

	// �������� ������� ��� �����
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

	// �������� �����o� ��� ��������
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

	// ����������� ���� �������� ������� (������� ������, ��������� � �������� � � �����; �������� ����������� ���������) - ��
	testList1.merge(testList2);
	bool resultMerge0 = ((testList1 == sourceList1) && (testList2 == emptyList));
	testPrint(testList1, resultMerge0);

	// ����������� ������� � ��������� ������� - ��
	testList3.merge(testList1);
	bool resultMerge1 = ((testList3 == sourceList1) && (testList1 == emptyList));
	testPrint(testList3, resultMerge1);
}
//-----------------------------------------------------------------------------------------------------------------------
// ��������� ��������
void testSubtract()
{
	std::cout << std::endl << "----- ��������� �������� -----" << std::endl;

	// �������� ������� ��� �����
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

	// �������� �����o� ��� ��������
	SinglyOrderedList sourceList1;
	SinglyOrderedList sourceList2(testList2);
	sourceList1.insert(2);
	sourceList1.insert(4);

	testList1.print();
	testList2.print();

	// ��������� ���� �������� ������� (�������� ������, ��������� � �������� � ������) - ��
	testList1.subtract(testList2);
	bool resultMerge0 = ((testList1 == sourceList1) && (testList2 == sourceList2));
	testPrint(testList1, resultMerge0);
}
//-----------------------------------------------------------------------------------------------------------------------
// ����������� ��������
void testCross()
{
	std::cout << std::endl << "----- ����������� �������� -----" << std::endl;

	// �������� ������� ��� �����
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

	// �������� �����o� ��� ��������
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

	// ����������� ���� �������� ������� � ������������ ���������� - ��
	SinglyOrderedList list1;
	list1 = cross(testList1, testList2);
	bool resultMerge0 = ((list1 == sourceList1) && (testList1 == sourceList2) && (testList2 == sourceList3));
	testPrint(list1, resultMerge0);

	// ����������� ���� �������� ������� � �������������� ���������� - ��
	SinglyOrderedList list2;
	list2 = cross(testList1, testList3);
	bool resultMerge1 = ((list2 == emptyList) && (testList1 == sourceList2) && (testList3 == sourceList4));
	testPrint(list2, resultMerge1);
}