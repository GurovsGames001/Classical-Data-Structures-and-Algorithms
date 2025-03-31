#include "DoubleLinkedList.h"
#include "DoubleLinkedList.h"
//  DoubleLinkedList.cpp - ������ ������� ������ ����� ����� - ���������� ������� ������  
//
#include <iostream>

// ����������� "�� ���������" - �������� ������� ������ - ��. �������� ������
// DoubleLinkedList::DoubleLinkedList(): count_(0), head_(nullptr), tail_(nullptr) {  }

// ����������� "�����������" � �������� ����� ���������� ������
DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList & src): count_(0), head_(nullptr), tail_(nullptr)
{
	Node* temp = src.head_;
	// ���� �� ����� ������:
	while (temp != 0)
	{   
		// �������� ������:
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

// �������� ������������ (���������� ������������)
DoubleLinkedList & DoubleLinkedList ::operator=(const DoubleLinkedList& right)
{
	if (this != &right) {
		DoubleLinkedList temp(right); // temp ����� right ��������
		swap(temp);        // ������ this ����� right, � temp ����� this
	}                    // �������� temp c ������� ������� this
	return *this;
}

// ����������� ����������� 
DoubleLinkedList::DoubleLinkedList(DoubleLinkedList&& other) noexcept:
	head_(other.head_),
	tail_(other.tail_),
	count_(other.count_)
{
	other.head_ = nullptr;
	other.tail_ = nullptr;
	other.count_ = 0;
}

// �������� ������������� ������������ 
DoubleLinkedList& DoubleLinkedList::operator=(DoubleLinkedList&& right) noexcept 
{
	if (this != &right) {
		swap(right);
	}
	return *this;
}


// ���������� ��������������� ���� � ����� ������
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
		// ������ ��� ���� � ����� ������� ����� � ������, � ���������
		head_ = x;
	}
	tail_ = x;
	count_++;
}

// ���������� ��������������� ���� � ������ ������
void DoubleLinkedList::insertHead(Node* x)
{   // x->prev_ == nullptr,  x->next_ == nullptr  
	x->next_ = head_;
	if (head_ != nullptr) {
		// ������ ��� �� ���� � ����� ������� ����� � ������, � ���������
		head_->prev_ = x;
	}
	else {
		// ������ ��� ���� � ����� ������� ����� � ������, � ���������
		tail_ = x;
	}
	head_ = x;
	count_++;  // ����� ��������� ������ �����������
}

// �������� ��������� ���� 
void DoubleLinkedList::deleteNode(Node* x)
{
	if (x == nullptr) {
		throw ("DoubleLinkedList::deleteNode  - ������� ����� ����� ���������� ����");
	}
	if (x->prev_ != nullptr) {
		// ��������� �� ������ ������
		(x->prev_)->next_ = x->next_;
	}
	else {
		// ��������� ������ ������,  ������ ������� ���������� ������
		head_ = x->next_;
	}
	if (x->next_ != nullptr) {
		// ��������� �� �����
		(x->next_)->prev_ = x->prev_;
	}
	else {
		// ��������� �����
		tail_ = x->prev_;
	}
	delete x;      // 
	count_--;     // ����� ��������� ������ �����������
}

// ����� ���� (�����) � �������� ���������  
DoubleLinkedList::Node* DoubleLinkedList::searchNode(int item)
{
	Node* x = head_;
	while (x != nullptr && x->item_ != item) {
		x = x->next_;
	}
	return x;
}

// ������ ���������� ���� �� �����
DoubleLinkedList::Node* DoubleLinkedList::replaceNode(DoubleLinkedList::Node* x, int item)
{
	x->item_ = item;
	return x;
}

// ���������� ��������� ������
//  int DoubleLinkedList::�ount()const{ return count_; }

// ������ � ���������� ��������� ���� ������
int DoubleLinkedList::headItem() const
{
	if (head_ != nullptr) {
		return head_->item_;
	}
	throw ("headItem - ������ ����!");
}

int& DoubleLinkedList::headItem()
{
	if (head_ != nullptr) {
		return head_->item_;
	}
	throw ("headItem - ������ ����!");
}

// ������ � ���������� ���������� ���� ������
int DoubleLinkedList::tailItem() const
{
	if (tail_ != nullptr) {
		return tail_->item_;
	}
	throw ("tailItem - ������ ����!");
}
int& DoubleLinkedList::tailItem()
{
	if (tail_ != nullptr) {
		return tail_->item_;
	}
	throw ("tailItem - ������ ����!");
}

// ���������� �������� � ������ ������
void DoubleLinkedList::insertHead(int item)
{   // ������� ����� ������� ������ � ��������� � ������ 
	insertHead(new Node(item));
}


// ���������� �������� � ����� ������
void DoubleLinkedList::insertTail(int item)
{   // ������� ����� ������� ������ � ��������� � ����� 
	insertTail(new Node(item));
}

// �������� �������� � ������ ������
bool DoubleLinkedList::deleteHead()
{
	if (head_ == nullptr) {
		return 0;  // ������ ����, �������� ���
	}
	deleteNode(head_);
	return 1;      // ������ ��� �� ����, �������� ������
}

// �������� �������� �� ������ ������
bool DoubleLinkedList::deleteTail()
{
	if (tail_ == nullptr) {
		return 0;  // ������ ����, �������� ���
	}
	deleteNode(tail_);
	return 1; // ������ ��� �� ����, �������� ������
}

// �������� ���� � �������� ���������
bool DoubleLinkedList::deleteItem(const int item)
{
	Node* temp = searchNode(item);
	if (temp == nullptr)
	{
		return 0;
	}
	deleteNode(temp);
	return 1; // ������ ��� �� ����, �������� ���� � �������� ���������
}

// ����� ������ � �������� ���������  
bool DoubleLinkedList::searchItem(int item)
{   // ���������� TRUE, ���� ���� ������ 
	return (searchNode(item) != nullptr);
}


// ������ ���������� ���� �� �����
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

// ����� ��������� ������ � ��������� ���� � ����������� �������� ����� 
void DoubleLinkedList::outAll()
{
	Node* current = head_;       // ��������� �� �������
	while (current != nullptr) {
		std::cout << current->item_ << ' ';
		current = current->next_;  // ������� � ���������� ��������
	}
	std::cout << std::endl;
}

// ���������� ������	
DoubleLinkedList::~DoubleLinkedList()
{
	Node* current = nullptr;   // ��������� �� �������, ���������� ��������
	Node* next = head_;        // ��������� �� ��������� �������
	while (next != nullptr) {  // ���� ���� ��� �������� � ������
		current = next;
		next = next->next_;    // ������� � ���������� ��������
		delete current;        // ������������ ������
	}
}

// ���������� � ����� ��������� ������ ��������� ������, ��������� ���������� ������
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

// �������� ��������� ==
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

//  �������� ������ <<
std::ostream& operator<<(std::ostream& out, DoubleLinkedList& list)
{
	DoubleLinkedList::Node* current = list.head_;
	if (current == nullptr)
	{
		out << "������ ������" << '\n';
	}
	while (current != nullptr)
	{
		out << current->item_ << ' ';
		current = current->next_;
	}
	return out;
}