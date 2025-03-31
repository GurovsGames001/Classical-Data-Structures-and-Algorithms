#include <iostream>
#include "SinglyOrderedList.h"
#include "testFunction.h"

int main()
{
	setlocale(LC_ALL, "rus");

	testInsert();
	testSearch();
	testDeleteKey();
	testMerge();
	testSubtract();
	testCross();

	return 0;
}