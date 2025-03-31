#include <cstdlib>
#include <ctime>
#include "functions.h"
#include"QuickSort.h"

const int SIZE = 6; // ������ �������� ��� ������
const int BIG_SIZE = 1000; // ������ ������� ��� �������� ������ � ����� ������� ��������

// ������������ ����������
void testQuickSort()
{
	QuickSort<int> quickSort;

	////////////////////////////////////////////////////////////////
	// ������ ������
	std::cout << "\n------------- ������ ������ -------------\n";

	int array1[SIZE] = { 4, 1, 3, 2, 6, 5 };

	std::cout << "�������� ������: ";
	print(array1, array1 + SIZE);

	quickSort(array1, 0, SIZE - 1);

	if (isOrdered(array1, array1 + SIZE))
	{
		std::cout << "������ ������������\n";
	}
	else
	{
		std::cout << "������ �� ������������\n";
	}

	std::cout << "������ ����� ����������: ";
	print(array1, array1 + SIZE);

	////////////////////////////////////////////////////////////////
	// ������� ������
	std::cout << "\n------------- ������� ������ -------------\n";

	int array2[SIZE] = { };
	srand(time(NULL));
	for (int i = 0; i < SIZE; i++)
	{
		array2[i] = rand();
	}

	std::cout << "�������� ������: ";
	print(array2, array2 + SIZE);

	quickSort(array2, 0, SIZE - 1);

	if (isOrdered(array2, array2 + SIZE))
	{
		std::cout << "������ ������������\n";
	}
	else
	{
		std::cout << "������ �� ������������\n";
	}

	std::cout << "������ ����� ����������: ";
	print(array2, array2 + SIZE);

	////////////////////////////////////////////////////////////////
	// ������ ������
	std::cout << "\n------------- ������ ������ -------------\n";

	int array3[SIZE] = { 0, 1, 2, 3, 4, 5 };

	std::cout << "�������� ������: ";
	print(array3, array3 + SIZE);

	quickSort(array3, 0, SIZE - 1);

	if (isOrdered(array3, array3 + SIZE))
	{
		std::cout << "������ ������������\n";
	}
	else
	{
		std::cout << "������ �� ������������\n";
	}

	std::cout << "������ ����� ����������: ";
	print(array3, array3 + SIZE);

	////////////////////////////////////////////////////////////////
	// ������� ������ (����� ������� ������)
	std::cout << "\n------------- ������� ������ (����� ������� ������) -------------\n";

	int array4[BIG_SIZE] = { };
	srand(time(NULL));
	for (int i = 0; i < BIG_SIZE; i++)
	{
		array4[i] = rand();
	}

	quickSort(array4, 0, BIG_SIZE - 1);

	if (isOrdered(array4, array4 + BIG_SIZE))
	{
		std::cout << "������ ������������\n";
	}
	else
	{
		std::cout << "������ �� ������������\n";
	}
}