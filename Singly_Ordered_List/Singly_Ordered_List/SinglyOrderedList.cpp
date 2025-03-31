#include "SinglyOrderedList.h"

// Конструктор копирования
SinglyOrderedList::SinglyOrderedList(const SinglyOrderedList& src) : count_(0), head_(nullptr), tail_(nullptr)
{
	Node* temp = src.head_;
	// Пока не конец списка:
	while (temp != nullptr)
	{
		// Копируем данные:
		insert(temp->item_);
		temp = temp->next_;
	}
}

void SinglyOrderedList::swap(SinglyOrderedList& other) noexcept
{
	std::swap(head_, other.head_);
	std::swap(tail_, other.tail_);
	std::swap(count_, other.count_);
}


// Добавить узёл
bool SinglyOrderedList::insertNode(Node* newNode)
{
	if (head_ != nullptr) {
		// список был НЕ пуст
		if (newNode->item_ > tail_->item_)
		{
			tail_->next_ = newNode;
			tail_ = newNode;
			count_++;
			return 1;
		}
		else if (newNode->item_ < head_->item_)
		{
			newNode->next_ = head_;
			head_ = newNode;
			count_++;
			return 1;
		}
		else
		{
			Node* temp1 = head_;
			Node* temp2 = head_->next_;
			while (temp2->item_ < newNode->item_)
			{
				temp1 = temp2;
				temp2 = temp2->next_;
			}
			if (temp2->item_ != newNode->item_)
			{
				temp1->next_ = newNode;
				newNode->next_ = temp2;
				count_++;
				return 1;
			}
		}
	}
	else {
		// список был пуст – новый элемент будет и первым, и последним
		head_ = newNode;
		tail_ = newNode;
		count_++;
		return 1;
	}

	return 0;
}

// Найти узёл
SinglyOrderedList::Node* SinglyOrderedList::searchNode(int item) const
{
	Node* temp = head_;
	while ((temp != nullptr) && (temp->item_ <= item))
	{
		temp = temp->next_;
	}

	if (temp != nullptr)
	{
		if (temp->item_ != item)
		{
			temp = nullptr;
		}
	}
	

	return temp;
}

// Добавить элемент
bool SinglyOrderedList::insert(int item)
{
	return (insertNode(new Node(item)));
}

// Найти элемент
bool SinglyOrderedList::search(int item) const
{
	return (searchNode(item) != nullptr);
}

// Удалить элемент
bool SinglyOrderedList::deleteItem(int item)
{
	Node* temp1 = head_;
	Node* temp2 = head_;

	// Поиск нужного элемента
	while (temp1 != nullptr)
	{
		if (temp1->item_ == item)
		{
			break;
		}

		temp2 = temp1;
		temp1 = temp1->next_;
	}

	if (temp1 != nullptr)
	{
		if (temp1 == head_)
		{
			// удаляется голова списка,  второй элемент становится первым
			head_ = temp1->next_;
		}
		else
		{
			// удаляется НЕ голова
			if (temp1->item_ != tail_->item_)
			{
				// удаляется НЕ хвост
				temp2->next_ = temp1->next_;
			}
			else
			{
				// удаляется хвост
				tail_ = temp2;
				tail_->next_ = nullptr;
			}
		}

		delete temp1;
		count_--;     // число элементов списка уменьшилось

		return 1;
	}

	return 0;
}

void SinglyOrderedList::print()
{
	Node* temp = head_;

	if (temp == nullptr)
	{
		std::cout << "пустой список";
	}
	while (temp != nullptr)
	{
		std::cout << temp->item_ << " ";
		temp = temp->next_;
	}

	std::cout << '\n';
}

// Объединение
void SinglyOrderedList::merge(SinglyOrderedList& list)
{
	Node* temp1 = head_;
	Node* temp2 = head_;
	Node* temp3 = list.head_;

	while ((temp1 != nullptr) && (temp3 != nullptr))
	{
		if (temp3->item_ == temp1->item_) // удаление совпадающего элемента во втором списке
		{
			Node* current = temp3;
			temp3 = temp3->next_;
			delete current;
			list.count_--;
		}
		else if (temp3->item_ > temp1->item_)
		{
			temp2 = temp1;
			temp1 = temp1->next_;
		}
		else
		{
			Node* current = temp3;
			temp3 = temp3->next_;
			count_++;
			list.count_--;

			if (temp1->item_ != head_->item_) // добавление элемента в середину
			{
				current->next_ = temp1;
				temp2->next_ = current;
				temp2 = current;
			}
			else // добавление головы
			{
				current->next_ = head_;
				head_ = current;
			}
		}
	}

	// добавление оставшихся элементов
	if (temp3 != nullptr)
	{
		if (tail_ != nullptr) // если первый список не пуст
		{
			tail_->next_ = temp3;
		}
		else // если первый список пуст
		{
			head_ = temp3;
		}

		tail_ = list.tail_;
		count_ += list.count_;
	}

	list.head_ = nullptr;
	list.tail_ = nullptr;
	list.count_ = 0;
}

// Вычитание
void SinglyOrderedList::subtract(const SinglyOrderedList& list)
{
	Node* temp1 = head_;
	Node* temp2 = head_;
	Node* temp3 = list.head_;
	Node* current = nullptr;

	// Цикл для головы
	while ((temp1 == head_) && (temp1 != nullptr) && (temp3 != nullptr))
	{
		if (temp1->item_ > temp3->item_)
		{
			temp3 = temp3->next_;
		}
		else if (temp1->item_ < temp3->item_)
		{
			temp1 = temp1->next_;
		}
		else // удаление головы
		{
			current = temp1;
			head_ = temp1->next_;
			temp1 = head_;
			temp2 = head_;
			temp3 = temp3->next_;
			delete current;
			count_--;
		}
	}

	// Цикл после головы
	while ((temp1 != nullptr) && (temp3 != nullptr))
	{
		if (temp1->item_ > temp3->item_)
		{
			temp3 = temp3->next_;
		}
		else if (temp1->item_ < temp3->item_)
		{
			temp1 = temp1->next_;
			temp2 = temp2->next_;
		}
		else
		{
			current = temp1;

			if (temp1 == tail_) // удаление хвоста
			{
				tail_ = temp2;
				tail_->next_ = nullptr;
			}
			else // удаление элемента из середины
			{
				temp2->next_ = temp1->next_;
			}

			temp1 = temp1->next_;
			temp3 = temp3->next_;
			delete current;
			count_--;
		}
	}
}

// Пересечение
SinglyOrderedList cross(const SinglyOrderedList& list1, const SinglyOrderedList& list2)
{
	SinglyOrderedList newList;

	SinglyOrderedList::Node* temp1 = list1.head_;
	SinglyOrderedList::Node* temp2 = list2.head_;

	// Цикл для добавления в новый список головы
	while ((newList.head_ == nullptr) && (temp1 != nullptr) && (temp2 != nullptr))
	{
		if (temp1->item_ < temp2->item_)
		{
			temp1 = temp1->next_;
		}
		else if (temp1->item_ > temp2->item_)
		{
			temp2 = temp2->next_;
		}
		else
		{
			SinglyOrderedList::Node* newNode = new SinglyOrderedList::Node(temp1->item_);
			newList.head_ = newNode;
			temp1 = temp1->next_;
			temp2 = temp2->next_;
			newList.count_++;
		}
	}

	SinglyOrderedList::Node* temp3 = newList.head_;

	// Цикл для добавления в новый список других элементов
	while ((temp1 != nullptr) && (temp2 != nullptr))
	{
		if (temp1->item_ < temp2->item_)
		{
			temp1 = temp1->next_;
		}
		else if (temp1->item_ > temp2->item_)
		{
			temp2 = temp2->next_;
		}
		else
		{
			SinglyOrderedList::Node* newNode = new SinglyOrderedList::Node(temp1->item_);
			temp3->next_ = newNode;
			temp3 = temp3->next_;
			temp1 = temp1->next_;
			temp2 = temp2->next_;
			newList.count_++;
		}
	}

	newList.tail_ = temp3;

	return newList;
}

// Оператор присваивания (копирующее присваивание)
SinglyOrderedList& SinglyOrderedList::operator=(const SinglyOrderedList& right)
{
	if (this != &right) {
		SinglyOrderedList temp(right); // temp копия right операнда
		swap(temp);        // теперь this копия right, а temp копия this
	}                    // удаление temp c данными старого this
	return *this;
}

// Оператор сравнения
bool SinglyOrderedList::operator==(const SinglyOrderedList& list) const
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

// Оператор вывода
std::ostream& operator<<(std::ostream& out, SinglyOrderedList& list)
{
	SinglyOrderedList::Node* current = list.head_;
	if (current == nullptr)
	{
		out << "пустой словарь" << '\n';
	}
	while (current != nullptr)
	{
		out << current->item_ << ' ';
		current = current->next_;
	}

	delete current;
	return out;
}

// Деструктор
SinglyOrderedList::~SinglyOrderedList()
{
	Node* current = nullptr;   // указатель на элемент, подлежащий удалению
	Node* next = head_;        // указатель на следующий элемент
	while (next != nullptr) {  // пока есть еще элементы в списке
		current = next;
		next = next->next_;    // переход к следующему элементу
		delete current;        // освобождение памяти
	}
}