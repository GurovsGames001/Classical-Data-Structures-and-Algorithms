#ifndef _QUEUE
#define _QUEUE
#include <memory>
#include "exceptions.h"

template <class T>
class Queue
{
public:
	virtual ~Queue() {};
	virtual void enQueue(const T& e) = 0; // Добавление элемента
	virtual T deQueue() = 0; // Удаление и возвращение элемента
	virtual bool isEmpty() = 0; // Проверка на пустоту
	virtual void print() = 0; // Вывод очереди
};

template <class T>
class QueueArray : public Queue<T>
{
public:
	QueueArray(size_t size = 100);
	~QueueArray() {};

	void enQueue(const T& e) override; // Добавление элемента
	T deQueue() override; // Удаление и возвращение элемента
	bool isEmpty() override { return ((head_ == tail_) && !(isOverflow_)); }; // Проверка на пустоту
	void print() override; // Вывод очереди
private:
	std::unique_ptr<T[]> array_;
	size_t size_;
	size_t head_;
	size_t tail_;
	bool isOverflow_;
};

template <class T>
QueueArray<T>::QueueArray(size_t size) : size_(size), head_(1), tail_(1), isOverflow_(false)
{
	try
	{
		array_ = std::make_unique<T[]>(size_ + 1);
	}
	catch (...)
	{
		throw WrongQueueSize();
	}
}

// Добавление элемента
template <class T>
void QueueArray<T>::enQueue(const T& e)
{
	if (isOverflow_) // Очередь переполнена
	{
		throw QueueOverflow();
	}
	else
	{
		array_[tail_] = e;

		if (tail_ == size_)
		{
			tail_ = 1;
		}
		else
		{
			tail_++;
		}

		if (tail_ == head_)
		{
			isOverflow_ = true;
		}
	}
}

// Удаление и возвращение элемента
template <class T>
T QueueArray<T>::deQueue()
{
	if (isEmpty()) // Очередь пустая
	{
		throw QueueUnderflow();
	}
	else
	{
		T x = array_[head_];
		
		if (head_ == size_)
		{
			head_ = 1;
		}
		else
		{
			head_++;
		}

		if (isOverflow_)
		{
			isOverflow_ = false;
		}

		return x;
	}
}

// Вывод очереди
template <class T>
void QueueArray<T>::print()
{
	if (isEmpty())
	{
		std::cout << "Пустая очередь";
	}
	else
	{
		if (head_ < tail_)
		{
			for (int i = head_; i < tail_; i++)
			{
				std::cout << array_[i] << ' ';
			}
		}
		else
		{
			for (int i = head_; i <= size_; i++)
			{
				std::cout << array_[i] << ' ';
			}
			for (int i = 1; i < tail_; i++)
			{
				std::cout << array_[i] << ' ';
			}
		}
	}

	std::cout << std::endl;
}

#endif