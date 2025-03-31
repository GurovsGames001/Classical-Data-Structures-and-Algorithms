#ifndef __SINGLY_ORDERED_LIST
#define __SINGLY_ORDERED_LIST
#include <iostream>

class SinglyOrderedList
{
private:
    // ���  Node ������������ ��� �������� �������� ������, ���������� �� 
    // ��������� � ������� ���� next_ � �������������� � ������� ���� prev_
    struct Node         // ����� ��������������  ������ � ������ DoubleLinkedList
    {
        int item_;        // �������� �������� ������
        Node* next_;      // ��������� �� ��������� ������� ������

        // ����������� ��� �������� ������ �������� ������. 
        Node(int item, Node* next = nullptr) : item_(item), next_(next) { }
    };

    int count_;         // ������� ����� ���������
    Node* head_;        // ������ ������� ������
    Node* tail_;        // ��������� ������� ������

    void swap(SinglyOrderedList& other) noexcept;

    bool insertNode(Node* item); // �������� ���
    Node* searchNode(int item) const; // ����� ���

public:
    // ����������� "�� ���������" - �������� ������� ������
    SinglyOrderedList() : head_(nullptr), tail_(nullptr), count_(0) {};
    // ����������� �����������
    SinglyOrderedList(const SinglyOrderedList& src);
    // ����������
    ~SinglyOrderedList();
    
    bool insert(int item); // �������� �������
    bool search(int item) const; // ����� �������
    bool deleteItem(int item); // ������� �������
    void print();

    void merge(SinglyOrderedList& list); // �����������
    void subtract(const SinglyOrderedList& list); // ���������

    friend SinglyOrderedList cross(const SinglyOrderedList& list1, const SinglyOrderedList& list2); // �����������

    SinglyOrderedList& operator=(const SinglyOrderedList& right); // �������� ������������ (���������� ������������)
    bool operator==(const SinglyOrderedList& list) const; // �������� ���������

    friend std::ostream& operator<<(std::ostream& out, SinglyOrderedList& list); // �������� ������
};

#endif