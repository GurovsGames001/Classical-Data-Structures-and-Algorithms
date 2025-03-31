#include <iostream>
#include "Stack.h"
#include "functions.h"
#include "testFunction.h"

int main()
{
	setlocale(LC_ALL, "rus");

	try
	{
		testCheckBalanceBrackets();
		testGetPostfix();
		testEvaluatePostfix();
	}

	catch (std::exception& error)
	{
		std::cerr << error.what() << '\n';
		return -1;
	}

	return 0;
}