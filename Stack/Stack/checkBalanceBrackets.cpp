#include "functions.h"
#include "Stack.h"

bool checkBalanceBrackets(const std::string& text, const int maxDeep)
{
	bool isCorrectBalanceBrackets = true;
	StackArray<char> stackForBrackets;

	int deep = 0;

	for (int i = 0; (text[i] != '\0') && (deep <= maxDeep) && (isCorrectBalanceBrackets); i++)
	{
		switch (text[i])
		{
		case '(':
			deep++;
			stackForBrackets.push(text[i]);
			break;
		case '[':
			deep++;
			stackForBrackets.push(text[i]);
			break;
		case '{':
			deep++;
			stackForBrackets.push(text[i]);
			break;
		case ')':
			if (stackForBrackets.isEmpty())
			{
				isCorrectBalanceBrackets = false;
			}
			else
			{
				(stackForBrackets.pop() == '(') ? deep-- : isCorrectBalanceBrackets = false;
			}

			break;
		case ']':
			if (stackForBrackets.isEmpty())
			{
				isCorrectBalanceBrackets = false;
			}
			else
			{
				(stackForBrackets.pop() == '[') ? deep-- : isCorrectBalanceBrackets = false;
			}

			break;
		case '}':
			if (stackForBrackets.isEmpty())
			{
				isCorrectBalanceBrackets = false;
			}
			else
			{
				(stackForBrackets.pop() == '{') ? deep-- : isCorrectBalanceBrackets = false;
			}

			break;
		}
	}

	if ((deep > maxDeep) || (!(stackForBrackets.isEmpty())))
	{
		isCorrectBalanceBrackets = false;
	}

	return isCorrectBalanceBrackets;
}