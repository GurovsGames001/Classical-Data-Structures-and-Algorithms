#include "functions.h"
#include "Stack.h"

int evaluatePostfix(const std::string& infix, const size_t stackSize)
{
	std::string postfix = "";
	getPostfixFromInfix(infix, postfix, stackSize);

	int x1 = 0;
	int x2 = 0;
	StackArray<int> stack(stackSize);
	for (int i = 0; postfix[i] != '\0'; i++)
	{
		switch (postfix[i])
		{
		case '+':
			x1 = stack.pop();
			x2 = stack.pop();
			stack.push(x2 + x1);
			break;
		case '-':
			x1 = stack.pop();
			x2 = stack.pop();
			stack.push(x2 - x1);
			break;
		case '*':
			x1 = stack.pop();
			x2 = stack.pop();
			stack.push(x2 * x1);
			break;
		case '/':
			x1 = stack.pop();
			x2 = stack.pop();
			stack.push(x2 / x1);
			break;
		default:
			int number = postfix[i] -'0';
			stack.push(number);
			break;
		}
	}

	return stack.pop();
}