#ifndef _FUNCTIONS
#define _FUNCTIONS
#include <iterator>
#include <iostream>

// Тестирование сортировки
void testQuickSort();

// Вывод массива
template<class T>
void print(const T* begin, const T* end)
{
	std::copy(begin, end, std::ostream_iterator<T>(std::cout, " "));
	std::cout << std::endl;
}

// Проверка упорядоченности массива
template<class T>
bool isOrdered(const T* begin, const T* end)
{
	bool ordered = true;

	while ((begin != end) && ordered) 
	{
		const T* prev = begin;
		begin++;

		if ((begin != end) && (*prev > *begin)) 
		{
			ordered = false;
			break;
		}
	}

	return ordered;
}

#endif