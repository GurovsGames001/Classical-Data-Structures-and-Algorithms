#ifndef _EXCEPTIONS
#define _EXCEPTIONS
#include <exception>

// *************** нвепедэ ***************

class WrongQueueSize : public std::exception
{
public:
	WrongQueueSize() : reason_("Wrong Queue Size") {}
	const char* what() const { return reason_; }
private:
	const char* reason_;
};

class QueueOverflow : public std::exception
{
public:
	QueueOverflow() : reason_("Queue Overflow") {}
	const char* what() const { return reason_; }
private:
	const char* reason_;
};

class  QueueUnderflow : public std::exception
{
public:
	QueueUnderflow() : reason_("Queue Underflow") {}
	const char* what() const { return reason_; }
private:
	const char* reason_;
};

// *************** ярей ***************

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

#endif