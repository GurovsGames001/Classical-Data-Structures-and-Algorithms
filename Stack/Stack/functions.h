#include <string>

bool checkBalanceBrackets(const std::string& text, const int maxDeep);
bool getPostfixFromInfix(const std::string& infix, std::string& postfix, const size_t stackSize);
int evaluatePostfix(const std::string& infix, const size_t stackSize);