#include "DoubleLinkedList.h"
#include "DoubleLinkedList.h"
//  DoubleLinkedList.cpp - Дважды связный список целых чисел - реализация методов класса  
//
#include <iostream>

// Конструктор "по умолчанию" - создание пустого списка - см. Описание класса
// DoubleLinkedList::DoubleLinkedList(): count_(0), head_(nullptr), tail_(nullptr) {  }

// Конструктор "копирования" – создание копии имеющегося списка
DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList & src): count_(0), head_(nullptr), tail_(nullptr)
{
	Node* temp = src.head_;
	// Пока не конец списка:
	while (temp != 0)
	{   
		// Копируем данные:
		insertTail(temp->item_);
		temp = temp->next_;
	}
}

void DoubleLinkedList::swap(DoubleLinkedList& other) noexcept
{
	std::swap(head_, other.head_);
	std::swap(tail_, other.tail_);
	std::swap(count_, other.count_);
}

// Оператор присваивания (копирующее присваивание)
DoubleLinkedList & DoubleLinkedList ::operator=(const DoubleLinkedList& right)
{
	if (this != &right) {
		DoubleLinkedList temp(right); // temp копия right операнда
		swap(temp);        // теперь this копия right, а temp копия this
	}                    // удаление temp c данными старого this
	return *this;
}

// Конструктор перемещения 
DoubleLinkedList::DoubleLinkedList(DoubleLinkedList&& other) noexcept:
	head_(other.head_),
	tail_(other.tail_),
	count_(other.count_)
{
	other.head_ = nullptr;
	other.tail_ = nullptr;
	other.count_ = 0;
}

// Оператор перемещающего присваивания 
DoubleLinkedList& DoubleLinkedList::operator=(DoubleLinkedList&& right) noexcept 
{
	if (this != &right) {
		swap(right);
	}
	return *this;
}


// Добавление сформированного узла в хвост списка
void DoubleLinkedList::insertTail(Node* x)
{
	// x->prev_ == nullptr,  x->next_ == nullptr 
	x->prev_ = tail_;
	if (tail_ != nullptr)
	{
		tail_->next_ = x;
	}
	else
	{
		// список был пуст – новый элемент будет и первым, и последним
		head_ = x;
	}
	tail_ = x;
	count_++;
}

// Добавление сформированного узла в начало списка
void DoubleLinkedList::insertHead(Node* x)
{   // x->prev_ == nullptr,  x->next_ == nullptr  
	x->next_ = head_;
	if (head_ != nullptr) {
		// список был НЕ пуст – новый элемент будет и первым, и последним
		head_->prev_ = x;
	}
	else {
		// список был пуст – новый элемент будет и первым, и последним
		tail_ = x;
	}
	head_ = x;
	count_++;  // число элементов списка увеличилось
}

// Удаление заданного узла 
void DoubleLinkedList::deleteNode(Node* x)
{
	if (x == nullptr) {
		throw ("DoubleLinkedList::deleteNode  - неверно задан адрес удаляемого узла");
	}
	if (x->prev_ != nullptr) {
		// удаляется НЕ голова списка
		(x->prev_)->next_ = x->next_;
	}
	else {
		// удаляется голова списка,  второй элемент становится первым
		head_ = x->next_;
	}
	if (x->next_ != nullptr) {
		// удаляется НЕ хвост
		(x->next_)->prev_ = x->prev_;
	}
	else {
		// удаляется хвост
		tail_ = x->prev_;
	}
	delete x;      // 
	count_--;     // число элементов списка уменьшилось
}

// Поиск узла (адрес) с заданным значением  
DoubleLinkedList::Node* DoubleLinkedList::searchNode(int item)
{
	Node* x = head_;
	while (x != nullptr && x->item_ != item) {
		x = x->next_;
	}
	return x;
}

// Замена информации узла на новое
DoubleLinkedList::Node* DoubleLinkedList::replaceNode(DoubleLinkedList::Node* x, int item)
{
	x->item_ = item;
	return x;
}

// количество элементов списка
//  int DoubleLinkedList::сount()const{ return count_; }

// Доступ к информации головного узла списка
int DoubleLinkedList::headItem() const
{
	if (head_ != nullptr) {
		return head_->item_;
	}
	throw ("headItem - список пуст!");
}

int& DoubleLinkedList::headItem()
{
	if (head_ != nullptr) {
		return head_->item_;
	}
	throw ("headItem - список пуст!");
}

// Доступ к информации хвостового узла списка
int DoubleLinkedList::tailItem() const
{
	if (tail_ != nullptr) {
		return tail_->item_;
	}
	throw ("tailItem - список пуст!");
}
int& DoubleLinkedList::tailItem()
{
	if (tail_ != nullptr) {
		return tail_->item_;
	}
	throw ("tailItem - список пуст!");
}

// Добавление элемента в голову списка
void DoubleLinkedList::insertHead(int item)
{   // создаем новый элемент списка и добавляем в голову 
	insertHead(new Node(item));
}


// Добавление элемента в хвост списка
void DoubleLinkedList::insertTail(int item)
{   // создаем новый элемент списка и добавляем в хвост 
	insertTail(new Node(item));
}

// Удаление элемента с головы списка
bool DoubleLinkedList::deleteHead()
{
	if (head_ == nullptr) {
		return 0;  // список пуст, удалений нет
	}
	deleteNode(head_);
	return 1;      // список был НЕ пуст, удаление головы
}

// Удаление элемента из хвоста списка
bool DoubleLinkedList::deleteTail()
{
	if (tail_ == nullptr) {
		return 0;  // список пуст, удалений нет
	}
	deleteNode(tail_);
	return 1; // список был НЕ пуст, удаление хвоста
}

// Удаление узла с заданным значением
bool DoubleLinkedList::deleteItem(const int item)
{
	Node* temp = searchNode(item);
	if (temp == nullptr)
	{
		return 0;
	}
	deleteNode(temp);
	return 1; // список был НЕ пуст, удаление узла с заданным значением
}

// Поиск записи с заданным значением  
bool DoubleLinkedList::searchItem(int item)
{   // возвращаем TRUE, если узел найден 
	return (searchNode(item) != nullptr);
}


// Замена информации узла на новое
bool DoubleLinkedList::replaceItem(int itemOld, int itemNew)
{
	Node* temp = searchNode(itemOld);
	if (temp != nullptr)
	{
		replaceNode(temp, itemNew);
		return 1;
	}
	return 0;
}

// Вывод элементов списка в текстовом виде в стандартный выходной поток 
void DoubleLinkedList::outAll()
{
	Node* current = head_;       // Указатель на элемент
	while (current != nullptr) {
		std::cout << current->item_ << ' ';
		current = current->next_;  // Переход к следующему элементу
	}
	std::cout << std::endl;
}

// Деструктор списка	
DoubleLinkedList::~DoubleLinkedList()
{
	Node* current = nullptr;   // указатель на элемент, подлежащий удалению
	Node* next = head_;        // указатель на следующий элемент
	while (next != nullptr) {  // пока есть еще элементы в списке
		current = next;
		next = next->next_;    // переход к следующему элементу
		delete current;        // освобождение памяти
	}
}

// Добавление в хвост исходного списка элементов списка, заданного параметром метода
void DoubleLinkedList::add(DoubleLinkedList& list)
{
	if (list.head_ != nullptr)
	{
		if (tail_ != nullptr)
		{
			tail_->next_ = list.head_;
			list.head_->prev_ = tail_;
			count_ += list.count_;
		}
		else
		{
			swap(list);
		}
	}
	list.count_ = 0;
	list.head_ = nullptr;
	list.tail_ = nullptr;
}

// Оператор сравнения ==
bool DoubleLinkedList::operator==(const DoubleLinkedList& list)
{
	bool isTrue = false;
	if (count_ == list.count_)
	{
		Node* temp1 = head_;
		Node* temp2 = list.head_;
		isTrue = true;
		for (; temp2 != nullptr; temp2 = temp2->next_, temp1 = temp1->next_)
		{
			if (temp1->item_ != temp2->item_)
			{
				isTrue = false;
				break;
			}
		}
	}
	return isTrue;
}

//  Оператор вывода <<
std::ostream& operator<<(std::ostream& out, DoubleLinkedList& list)
{
	DoubleLinkedList::Node* current = list.head_;
	if (current == nullptr)
	{
		out << "пустой список" << '\n';
	}
	while (current != nullptr)
	{
		out << current->item_ << ' ';
		current = current->next_;
	}
	return out;
}