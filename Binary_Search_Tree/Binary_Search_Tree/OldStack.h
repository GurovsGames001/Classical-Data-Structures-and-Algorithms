//#ifndef __STACK
//#define __STACK
//#include "exceptions.h"
//
//template <class T>
//class Stack
//{
//public:
//	virtual ~Stack() {}
//	virtual void push(const T& e) = 0; // ���������� �������� � ����
//	virtual const T& pop() = 0; // �������� � ����������� �������� ��������
//	virtual bool isEmpty() = 0; // �������� ����� �� ������� 
//};
//
//template <class T>
//class StackArray : public Stack<T>
//{
//public:
//	StackArray(size_t size = 100); // size ������ ������ ����� "�� ���������"
//	StackArray(const StackArray<T>& src); // = delete;
//	//StackArray(StackArray<T>&& src);
//	//StackArray& operator=(const StackArray<T>& src); // = delete;
//	//StackArray& operator=(StackArray<T>&& src);
//	~StackArray() { delete[] array_; };
//	void push(const T& e);
//	const T& pop();
//	const T top();
//	bool isEmpty() { return top_ == 0; };
//private:
//	T* array_; // ������ ��������� �����: !!! array_[0] � �� ������������, top_ �� 1 �� size_
//	size_t top_; // ������� �����, ������� ���������� � ���� ���������
//	size_t size_; // ������ �����
//	void swap(StackArray<T>& src);
//};
//
//// ����������� ����������� � �������� ����� ���������� ������, ���� �� ������� delete
//template <class T>
//StackArray<T>::StackArray(const StackArray<T>& src) :
//	size_(src.size_),
//	top_(src.top_)
//{
//	try {// !!! array_[0] � �� ������������, top_ �� 1 �� size_
//		array_ = new T[src.size_ + 1];
//	}
//	catch (...) {
//		throw WrongStackSize();
//	}
//	// ����������� �������
//	for (size_t i = 1; i < src.top_; i++) {
//		array_[i] = src.array_[i];
//	}
//}
//
//template <class T>
//void StackArray<T> ::swap(StackArray<T>& src)
//{
//	std::swap(array_, src.array_); // (this->array_, src.array_)
//	std::swap(top_, src.top_);
//	std::swap(size_, src.size_);
//}
//
//template <class T>
//StackArray<T>::StackArray(size_t size) :
//	size_(size),
//	top_(0)
//{ // !!! array_[0] � �� ������������, top_ �� 1 �� size_
//	try {
//		array_ = new T[size + 1]; // �������� �������� ������ ��� �������� �����...
//	}
//	catch (...) { // ���� ���-�� ��������� (��������, ������ ������� �������
//		throw WrongStackSize(); // ��� �������������) - ��������� �������������� ��������
//	}
//}
//
//template <class T>
//void StackArray<T>::push(const T& e)
//{
//	if (top_ == size_) {
//		T* temp = new T[size_ * 2 + 1];
//		// ����������� �������
//		for (size_t i = 1; i < top_; i++)
//		{
//			temp[i] = array_[i];
//		}
//		delete[] array_;
//		array_ = temp;
//		size_ *= 2;
//
//		//throw StackOverflow(); // ��� ����� ��� ������ ��������
//	}
//	array_[++top_] = e; // ��������� �������� � ����
//}
//
//template <class T>
//const T& StackArray<T>::pop()
//{
//	if (isEmpty()) { // (top_ == 0)
//		throw StackUnderflow(); // ���� ����
//	}
//	return array_[top_--]; // ������� ��������� �������� � �����, �� ������ "�� ��������"
//}
//
//template <class T>
//const T StackArray<T>::top()
//{
//	return array_[top_];
//}
//
//#endif