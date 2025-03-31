#ifndef __BINARY_SEARCH_TREE_H
#define __BINARY_SEARCH_TREE_H
#include <iostream>
#include "Stack.h"

template <class T>
class BinarySearchTree
{
public:
	// Конструктор "по умолчанию" создает пустое дерево
	BinarySearchTree() : root_(nullptr) {}
	// Конструктор копирования
	BinarySearchTree(const BinarySearchTree<T>& scr) = delete;
	// Конструктор перемещения
	BinarySearchTree(BinarySearchTree<T>&& scr) : root_(nullptr)
	{
		root_ = scr.root_;
		scr.root_ = nullptr;
	}
	// Оператор присваивания с копированием
	BinarySearchTree<T>& operator=(const BinarySearchTree<T>& src) = delete;
	// Оператор перемещающего присваивания
	BinarySearchTree<T>& operator=(BinarySearchTree<T>&& src);
	// Деструктор освобождает память, занятую узлами дерева
	virtual ~BinarySearchTree();

	// 1.1 Функция поиска по ключу в бинарном дереве поиска
	bool iterativeSearch(const T& key) const;
	// 2.1 Вставка нового элемента в дерево: true,если элемент добавлен;
	// false, если элемент уже был
	bool insert(const T& key);
	// 3.1 Удаление элемента из дерева, не нарушающее порядка элементов
	// true,если элемент удален; false, если элемента не было
	bool deleteKey(const T& key);
	// 4.1 Печать строкового изображения дерева в выходной поток out
	void print(std::ostream& out) const;
	// 5.1 Определение количества узлов дерева
	int getCount() const;
	// 6.1 Определение высоты дерева
	int getHeight() const;
	// 7 Инфиксный обход дерева (итеративный)
	void iterativeInorderWalk() const;
	// 8.1 Инфиксный обход дерева (рекурсивный)
	void inorderWalk() const;

private:
	// Описание структуры узла со ссылками на детей
	template <class T>
	struct Node {
		T key_; // значение ключа, содержащееся в узле
		Node<T>* left_; // указатель на левое поддерево
		Node<T>* right_; // указатель на правое поддерево
		Node<T>* p_; // указатель на родителя !!! не используется
		// Конструктор узла
		Node(T key, Node* left = nullptr, Node* right = nullptr, Node* p = nullptr) :
			key_(key), left_(left), right_(right), p_(p)
		{ }
	};

	Node<T>* root_; // Указатель на корневой узел

	// 1.2 Функция поиска адреса узла по ключу в бинарном дереве поиска
	Node<T>* iterativeSearchNode(const T& key) const;
	// 4.2 Рекурсивная функция для вывода изображения дерева в выходной поток
	void printNode(std::ostream& out, Node<T>* root) const;
	// 5.2 Рекурсивная функция определения количества узлов дерева
	int getCount(const Node<T>* node) const;
	// 6.2 Рекурсивная функция определения высоты дерева
	int getHeight(const Node<T>* node) const;
	// 8.2 Рекурсивная функция для организации обхода узлов дерева.
	void inorderWalk(Node<T>* node) const;

	// Удаление дерева
	void deleteTree(Node<T>* node);
	// Получение минимума
	Node<T>* getMin(Node<T>* node);
	// Поиск последующего ключа
	Node<T>* findSuccessor(Node<T>* node);

};  // конец шаблона класса TreeBinarySearchTree

// Деструктор освобождает память, занятую узлами дерева
template <class T>
BinarySearchTree<T>::~BinarySearchTree()
{
	deleteTree(root_);
}

// Удаление дерева
template <class T>
void BinarySearchTree<T>::deleteTree(Node<T>* node)
{
	if (node != nullptr)
	{
		deleteTree(node->left_);
		deleteTree(node->right_);
		delete node;
	}
}

// Оператор перемещающего присваивания
template <class T>
BinarySearchTree<T>& BinarySearchTree<T>::operator=(BinarySearchTree<T>&& src)
{
	root_ = src.root_;
	src.root_ = nullptr;
}

// 1.1 Функция поиска по ключу в бинарном дереве поиска
template <class T>
bool BinarySearchTree<T>::iterativeSearch(const T& key) const
{
	return (iterativeSearchNode(key) != nullptr);
}

// 1.2 Функция поиска адреса узла по ключу в бинарном дереве поиска
template <class T>
BinarySearchTree<T>::Node<T>* BinarySearchTree<T>::iterativeSearchNode(const T& key) const
{
	Node<T>* x = root_;
	while ((x != nullptr) && (x->key_ != key))
	{
		if (x->key_ > key)
		{
			x = x->left_;
		}
		else
		{
			x = x->right_;
		}
	}

	return x;
}

// 2.1 Вставка нового элемента в дерево
template <class T>
bool BinarySearchTree<T>::insert(const T& key)
{
	Node<T>* x = root_;
	Node<T>* prev = nullptr;

	// Поиск места для вставки
	while ((x != nullptr) && (x->key_ != key))
	{
		prev = x;
		if (x->key_ > key)
		{
			x = x->left_;
		}
		else
		{
			x = x->right_;
		}
	}

	if (x != nullptr) // Подобный элемент найден
	{
		return 0;
	}
	else // Подобного элемента не найдено
	{
		Node<T>* newNode = new Node<T>(key);

		if (prev == nullptr) // Дерево пустое
		{
			root_ = newNode;
		}
		else if (key < prev->key_)
		{
			prev->left_ = newNode;
			newNode->p_ = prev;
		}
		else
		{
			prev->right_ = newNode;
			newNode->p_ = prev;
		}

		return 1;
	}
}

// 3.1 Удаление элемента из дерева, не нарушающее порядка элементов
template <class T>
bool BinarySearchTree<T>::deleteKey(const T& key)
{
	Node<T>* x = iterativeSearchNode(key);

	if (x == nullptr) // Элемент не найден
	{
		return 0;
	}
	else // Элемент найден
	{
		if ((x->left_ == nullptr) && (x->right_ == nullptr)) // У узла нет наследников
		{
			if (x->p_ == nullptr) // Узел - корень
			{
				root_ = nullptr;
			}
			else // Узел - не корень
			{
				if (x->p_->left_ == nullptr)
				{
					x->p_->right_ = nullptr;
				}
				else
				{
					if (x->p_->left_->key_ == key)
					{
						x->p_->left_ = nullptr;
					}
					else
					{
						x->p_->right_ = nullptr;
					}
				}
			}
		}
		else // У узла есть наследники
		{
			if ((x->left_ != nullptr) && (x->right_ == nullptr)) // У узла один наследник слева
			{
				if (x->p_ == nullptr) // Узел - корень
				{
					root_ = x->left_;
					x->left_->p_ = nullptr;
				}
				else // Узел - не корень
				{
					if (x->p_->left_ == nullptr)
					{
						x->p_->right_ = x->left_;
					}
					else
					{
						if (x->p_->left_->key_ == key)
						{
							x->p_->left_ = x->left_;
						}
						else
						{
							x->p_->right_ = x->left_;
						}
					}

					x->left_->p_ = x->p_;
				}
			}
			else if ((x->left_ == nullptr) && (x->right_ != nullptr)) // У узла один наследник справа
			{
				if (x->p_ == nullptr) // Узел - корень
				{
					root_ = x->right_;
					x->right_->p_ = nullptr;
				}
				else // Узел - не корень
				{
					if (x->p_->left_ == nullptr)
					{
						x->p_->right_ = x->right_;
					}
					else
					{
						if (x->p_->left_->key_ == key)
						{
							x->p_->left_ = x->right_;
						}
						else
						{
							x->p_->right_ = x->right_;
						}
					}

					x->right_->p_ = x->p_;
				}
			}
			else // У узла оба наследника
			{
				Node<T>* nextNode = findSuccessor(x); // Поиск последующего узла

				if ((nextNode->left_ == nullptr) && (nextNode->right_ == nullptr)) // У последующего узла нет наследников
				{
					x->key_ = nextNode->key_;

					if (nextNode->p_ == x)
					{
						x->right_ = nullptr;
					}
					else
					{
						nextNode->p_->left_ = nullptr;
					}
				}
				else // У последующего узла есть один наследник (справа)
				{
					x->key_ = nextNode->key_;

					if (nextNode->p_ == x)
					{
						x->right_ = nextNode->right_;
						x->right_->p_ = x;
					}
					else
					{
						nextNode->p_->left_ = nextNode->right_;
						nextNode->p_->left_->p_ = nextNode->p_;
					}
				}

				x = nextNode;
			}
		}

		delete x;
		return 1;
	}
}

// 4.1 Печать строкового изображения дерева в выходной поток out
template <class T>
void BinarySearchTree<T>::print(std::ostream& out) const
{
	if (root_ == nullptr)
	{
		out << "пустое дерево";
	}
	else
	{
		printNode(out, root_);
	}
	out << '\n';
}

// 4.2 Рекурсивная функция для вывода изображения дерева в выходной поток
template <class T>
void BinarySearchTree<T>::printNode(std::ostream& out, Node<T>* root) const
{
	if (root != nullptr)
	{
		out << '(' << root->key_;
		printNode(out, root->left_);
		printNode(out, root->right_);
		out << ')';
	}
}

// 5.1 Определение количества узлов дерева
template <class T>
int BinarySearchTree<T>::getCount() const
{
	return getCount(this->root_);
}

// 5.2 Рекурсивная функция определения количества узлов дерева
template <class T>
int BinarySearchTree<T>::getCount(const Node<T>* node) const
{
	if (node == nullptr)
	{
		return 0;
	}

	return (1 + getCount(node->left_) + getCount(node->right_));
}

// 6.1 Определение высоты дерева
template <class T>
int BinarySearchTree<T>::getHeight() const
{
	return getHeight(this->root_) - 1;
}

// 6.2 Рекурсивная функция определения высоты дерева
template <class T>
int BinarySearchTree<T>::getHeight(const Node<T>* node) const
{
	if (node == nullptr)
	{
		return 0;
	}

	return (1 + std::max(getHeight(node->left_), getHeight(node->right_)));
}

// Получение минимума
template <class T>
BinarySearchTree<T>::Node<T>* BinarySearchTree<T>::getMin(Node<T>* node)
{
	while (node->left_ != nullptr)
	{
		node = node->left_;
	}

	return node;
}

// Поиск последующего ключа
template <class T>
BinarySearchTree<T>::Node<T>* BinarySearchTree<T>::findSuccessor(Node<T>* node)
{
	if (node->right_ != nullptr)
	{
		return getMin(node->right_);
	}

	Node<T>* prev = node->p_;
	while ((prev != nullptr) && (node == prev->right_))
	{
		node = prev;
		prev = prev->p_;
	}

	return prev;
}

// 7 Инфиксный обход дерева (итеративный)
template <class T>
void BinarySearchTree<T>::iterativeInorderWalk() const
{
	if (root_ == nullptr)
	{
		std::cout << "пустое дерево";
	}
	else
	{
		StackArray<Node<T>*> parentStack;
		Node<T>* current = root_;
		while (!(parentStack.isEmpty()) || (current != nullptr))
		{
			if (current != nullptr)
			{
				parentStack.push(current);
				current = current->left_;
			}
			else
			{
				current = parentStack.pop();
				std::cout << current->key_ << ' ';
				current = current->right_;
			}
		}
	}
	std::cout << '\n';
}

// 8.1 Инфиксный обход дерева (рекурсивный)
template <class T>
void BinarySearchTree<T>::inorderWalk() const
{
	if (root_ == nullptr)
	{
		std::cout << "пустое дерево";
	}
	else
	{
		inorderWalk(this->root_);
	}
	std::cout << '\n';
}

// 8.2 Рекурсивная функция для организации обхода узлов дерева.
template <class T>
void BinarySearchTree<T>::inorderWalk(Node<T>* node) const
{
	if (node != nullptr)
	{
		inorderWalk(node->left_);
		std::cout << node->key_ << ' ';
		inorderWalk(node->right_);
	}
}

#endif