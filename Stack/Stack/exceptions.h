#ifndef __EXCEPTION
#define __EXCEPTION
#include <exception>

// ������ StackOverflow � StackUnderflow ������������ ��� ��������
// �������������� ��������, ������� ����� ���������� ��� ������ �� ������
class StackOverflow : public std::exception
{
public:
	StackOverflow() : reason_("Stack Overflow") {}
	const char* what() const { return reason_; }
private:
	const char* reason_; // ! const
};

class StackUnderflow : public std::exception
{
public:
	StackUnderflow() : reason_("Stack Underflow") {}
	const char* what() const { return reason_; }
private:
	const char* reason_; // ! const
};

class WrongStackSize : public std::exception
{
public:
	WrongStackSize() : reason_("Wrong Stack Size") {}
	const char* what() const { return reason_; }
private:
	const char* reason_; // ! const
};

class IncorrectBalanceBrackets: public std::exception
{
public:
	IncorrectBalanceBrackets() : reason_("Incorrect Balance of Brackets") {}
	const char* what() const { return reason_; }
private:
	const char* reason_; // ! const
};

class Invalid�haracters : public std::exception
{
public:
	Invalid�haracters() : reason_("Invalid �haracters") {}
	const char* what() const { return reason_; }
private:
	const char* reason_; // ! const
};

#endif