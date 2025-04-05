#ifndef __SINGLY_ORDERED_LIST
#define __SINGLY_ORDERED_LIST
#include <iostream>

class SinglyOrderedList
{
private:
    // Тип  Node используется для описания элемента списка, связанного со 
    // следующим с помощью поля next_ и предшествующим с помощью поле prev_
    struct Node         // может использоваться  только в классе DoubleLinkedList
    {
        int item_;        // значение элемента списка
        Node* next_;      // указатель на следующий элемент списка

        // Конструктор для создания нового элемента списка. 
        Node(int item, Node* next = nullptr) : item_(item), next_(next) { }
    };

    int count_;         // счетчик числа элементов
    Node* head_;        // первый элемент списка
    Node* tail_;        // последний элемент списка

    void swap(SinglyOrderedList& other) noexcept;

    bool insertNode(Node* item); // Добавить узёл
    Node* searchNode(int item) const; // Найти узёл

public:
    // Конструктор "по умолчанию" - создание пустого списка
    SinglyOrderedList() : head_(nullptr), tail_(nullptr), count_(0) {};
    // Конструктор копирования
    SinglyOrderedList(const SinglyOrderedList& src);
    // Деструктор
    ~SinglyOrderedList();
    
    bool insert(int item); // Добавить элемент
    bool search(int item) const; // Найти элемент
    bool deleteItem(int item); // Удалить элемент
    void print();

    void merge(SinglyOrderedList& list); // Объединение
    void subtract(const SinglyOrderedList& list); // Вычитание

    friend SinglyOrderedList cross(const SinglyOrderedList& list1, const SinglyOrderedList& list2); // Пересечение

    SinglyOrderedList& operator=(const SinglyOrderedList& right); // Оператор присваивания (копирующее присваивание)
    bool operator==(const SinglyOrderedList& list) const; // Оператор сравнения

    friend std::ostream& operator<<(std::ostream& out, SinglyOrderedList& list); // Оператор вывода
};

#endif