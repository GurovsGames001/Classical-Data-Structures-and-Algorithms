#ifndef __STACK
#define __STACK
#include "exceptions.h"

template <class T>
class Stack
{
public:
	virtual ~Stack() {}
	virtual void push(const T& e) = 0; // ƒобавление элемента в стек
	virtual const T& pop() = 0; // ”даление и возвращение верхнего элемента
	virtual bool isEmpty() = 0; // ѕроверка стека на пустоту 
};

template <class T>
class StackArray : public Stack<T>
{
public:
	StackArray(size_t size = 100); // size задает размер стека "по умолчанию"
	StackArray(const StackArray<T>& src); // = delete;
	//StackArray(StackArray<T>&& src);
	//StackArray& operator=(const StackArray<T>& src); // = delete;
	//StackArray& operator=(StackArray<T>&& src);
	~StackArray() { delete[] array_; };
	void push(const T& e);
	const T& pop();
	const T top();
	bool isEmpty() { return top_ == 0; };
private:
	T* array_; // массив элементов стека: !!! array_[0] Ц не используетс€, top_ от 1 до size_
	size_t top_; // вершина стека, элемент занесенный в стек последним
	size_t size_; // размер стека
	void swap(StackArray<T>& src);
};

//  онструктор копировани€ Ц создание копии имеющегос€ списка, если не указано delete
template <class T>
StackArray<T>::StackArray(const StackArray<T>& src) :
	size_(src.size_),
	top_(src.top_)
{
	try {// !!! array_[0] Ц не используетс€, top_ от 1 до size_
		array_ = new T[src.size_ + 1];
	}
	catch (...) {
		throw WrongStackSize();
	}
	// копирование массива
	for (size_t i = 1; i < src.top_; i++) {
		array_[i] = src.array_[i];
	}
}

template <class T>
void StackArray<T> ::swap(StackArray<T>& src)
{
	std::swap(array_, src.array_); // (this->array_, src.array_)
	std::swap(top_, src.top_);
	std::swap(size_, src.size_);
}

template <class T>
StackArray<T>::StackArray(size_t size) :
	size_(size),
	top_(0)
{ // !!! array_[0] Ц не используетс€, top_ от 1 до size_
	try {
		array_ = new T[size + 1]; // пытаемс€ заказать пам€ть под элементы стека...
	}
	catch (...) { // если что-то случилось (например, размер слишком большой
		throw WrongStackSize(); // или отрицательный) - возникает исключительна€ ситуаци€
	}
}

template <class T>
void StackArray<T>::push(const T & e)
{
	if (top_ == size_) {
		throw StackOverflow(); // нет места дл€ нового элемента
	}
	array_[++top_] = e; // занесение элемента в стек
}

template <class T>
const T & StackArray<T>::pop()
{
	if (isEmpty()) { // (top_ == 0)
		throw StackUnderflow(); // стек пуст
	}
	return array_[top_--]; // Ёлемент физически остаетс€ в стеке, но больше "не доступен"
}

template <class T>
const T StackArray<T>::top()
{
	return array_[top_];
}

#endif