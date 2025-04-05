#include "functions.h"
#include "Stack.h"
#include "exceptions.h"

inline int getPriority(const char sign);
inline int getPriority(const char sign)
{
	int priority = 0;
	switch (sign)
	{
	case '(':
		priority = 0;
		break;
	case ')':
		priority = 1;
		break;
	case '+':
		priority = 2;
		break;
	case '-':
		priority = 2;
		break;
	case '*':
		priority = 3;
		break;
	case '/':
		priority = 3;
		break;
	}

	return priority;
}

bool getPostfixFromInfix(const std::string& infix, std::string& postfix, const size_t stackSize) // !!! ДОДЕЛАТЬ !!!
{
	bool isCorrectBalanceBrackets = true;
	StackArray<char> stack(stackSize);

	int i = 0;
	int j = -1;
	int nBrackets = 0;

	for (i = 0; (infix[i] != '\0') && (isCorrectBalanceBrackets); i++)
	{
		switch (infix[i])
		{
		case '(':
			nBrackets++;
			stack.push(infix[i]);
			break;
		case ')':
			if (nBrackets == 0)
			{
				isCorrectBalanceBrackets = false;
			}
			else
			{
				char temp = stack.pop();
				while (temp != '(')
				{
					postfix += temp;
					temp = stack.pop();
				}
				nBrackets--;
			}
			break;
		case '+':
			if (stack.isEmpty())
			{
				stack.push(infix[i]);
			}
			else
			{
				int priority = getPriority(infix[i]);
				while (getPriority(stack.top()) >= priority)
				{
					postfix += stack.pop();
				}
				stack.push(infix[i]);
			}
			break;
		case '-':
			if (stack.isEmpty())
			{
				stack.push(infix[i]);
			}
			else
			{
				int priority = getPriority(infix[i]);
				while (getPriority(stack.top()) >= priority)
				{
					postfix += stack.pop();
				}
				stack.push(infix[i]);
			}
			break;
		case '*':
			if (stack.isEmpty())
			{
				stack.push(infix[i]);
			}
			else
			{
				int priority = getPriority(infix[i]);
				while (getPriority(stack.top()) >= priority)
				{
					postfix += stack.pop();
				}
				stack.push(infix[i]);
			}
			break;
		case '/':
			if (stack.isEmpty())
			{
				stack.push(infix[i]);
			}
			else
			{
				int priority = getPriority(infix[i]);
				while (getPriority(stack.top()) >= priority)
				{
					postfix += stack.pop();
				}
				stack.push(infix[i]);
			}
			break;
		default:
			if (('0' <= infix[i]) && (infix[i] <= '9'))
			{
				postfix += infix[i];
			}
			else
			{
				throw InvalidСharacters();
			}
			break;
		}
	}

	while (!(stack.isEmpty()))
	{
		postfix += stack.pop();
	}

	if (nBrackets != 0)
	{
		isCorrectBalanceBrackets = false;
	}
	if (!(isCorrectBalanceBrackets))
	{
		throw IncorrectBalanceBrackets();
	}

	return 1;
}