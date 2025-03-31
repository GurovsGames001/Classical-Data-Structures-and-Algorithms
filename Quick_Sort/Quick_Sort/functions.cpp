#include <cstdlib>
#include <ctime>
#include "functions.h"
#include"QuickSort.h"

const int SIZE = 6; // Размер массивов для тестов
const int BIG_SIZE = 1000; // Размер массива для среднего случая с очень большим массивом

// Тестирование сортировки
void testQuickSort()
{
	QuickSort<int> quickSort;

	////////////////////////////////////////////////////////////////
	// Лучший случай
	std::cout << "\n------------- Лучший случай -------------\n";

	int array1[SIZE] = { 4, 1, 3, 2, 6, 5 };

	std::cout << "Исходный массив: ";
	print(array1, array1 + SIZE);

	quickSort(array1, 0, SIZE - 1);

	if (isOrdered(array1, array1 + SIZE))
	{
		std::cout << "Массив отсортирован\n";
	}
	else
	{
		std::cout << "Массив не отсортирован\n";
	}

	std::cout << "Массив после сортировки: ";
	print(array1, array1 + SIZE);

	////////////////////////////////////////////////////////////////
	// Средний случай
	std::cout << "\n------------- Средний случай -------------\n";

	int array2[SIZE] = { };
	srand(time(NULL));
	for (int i = 0; i < SIZE; i++)
	{
		array2[i] = rand();
	}

	std::cout << "Исходный массив: ";
	print(array2, array2 + SIZE);

	quickSort(array2, 0, SIZE - 1);

	if (isOrdered(array2, array2 + SIZE))
	{
		std::cout << "Массив отсортирован\n";
	}
	else
	{
		std::cout << "Массив не отсортирован\n";
	}

	std::cout << "Массив после сортировки: ";
	print(array2, array2 + SIZE);

	////////////////////////////////////////////////////////////////
	// Худший случай
	std::cout << "\n------------- Худший случай -------------\n";

	int array3[SIZE] = { 0, 1, 2, 3, 4, 5 };

	std::cout << "Исходный массив: ";
	print(array3, array3 + SIZE);

	quickSort(array3, 0, SIZE - 1);

	if (isOrdered(array3, array3 + SIZE))
	{
		std::cout << "Массив отсортирован\n";
	}
	else
	{
		std::cout << "Массив не отсортирован\n";
	}

	std::cout << "Массив после сортировки: ";
	print(array3, array3 + SIZE);

	////////////////////////////////////////////////////////////////
	// Средний случай (очень большой массив)
	std::cout << "\n------------- Средний случай (очень большой массив) -------------\n";

	int array4[BIG_SIZE] = { };
	srand(time(NULL));
	for (int i = 0; i < BIG_SIZE; i++)
	{
		array4[i] = rand();
	}

	quickSort(array4, 0, BIG_SIZE - 1);

	if (isOrdered(array4, array4 + BIG_SIZE))
	{
		std::cout << "Массив отсортирован\n";
	}
	else
	{
		std::cout << "Массив не отсортирован\n";
	}
}