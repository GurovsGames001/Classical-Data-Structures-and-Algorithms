#ifndef _QUICK_SORT
#define _QUICK_SORT
#include <iostream>

template <class T>
struct QuickSort
{
	void operator()(T* array, int p, int r)
	{
		int nOperation = 0;
		sort(array, p, r, nOperation);
		std::cout << "Оценка сложности: " << nOperation << std::endl;
	}

private:
	void sort(T* array, int p, int r, int& nOperation)
	{
		if (p < r)
		{
			int q = partition(array, p, r, nOperation);
			sort(array, p, q - 1, nOperation);
			sort(array, q + 1, r, nOperation);
		}
		nOperation++;
	}

	int partition(T* array, int p, int r, int& nOperation)
	{
		T x = array[r];
		int i = p - 1;
		
		for (int j = p; j <= r - 1; j++)
		{
			if (array[j] <= x)
			{
				i++;
				std::swap(array[j], array[i]);
				nOperation++;
			}
		}
		nOperation++;
		std::swap(array[r], array[i + 1]);
		
		return i + 1;
	}
};

#endif