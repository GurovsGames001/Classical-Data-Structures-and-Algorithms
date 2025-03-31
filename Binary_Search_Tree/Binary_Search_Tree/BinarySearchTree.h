#ifndef __BINARY_SEARCH_TREE_H
#define __BINARY_SEARCH_TREE_H
#include <iostream>
#include "Stack.h"

template <class T>
class BinarySearchTree
{
public:
	// ����������� "�� ���������" ������� ������ ������
	BinarySearchTree() : root_(nullptr) {}
	// ����������� �����������
	BinarySearchTree(const BinarySearchTree<T>& scr) = delete;
	// ����������� �����������
	BinarySearchTree(BinarySearchTree<T>&& scr) : root_(nullptr)
	{
		root_ = scr.root_;
		scr.root_ = nullptr;
	}
	// �������� ������������ � ������������
	BinarySearchTree<T>& operator=(const BinarySearchTree<T>& src) = delete;
	// �������� ������������� ������������
	BinarySearchTree<T>& operator=(BinarySearchTree<T>&& src);
	// ���������� ����������� ������, ������� ������ ������
	virtual ~BinarySearchTree();

	// 1.1 ������� ������ �� ����� � �������� ������ ������
	bool iterativeSearch(const T& key) const;
	// 2.1 ������� ������ �������� � ������: true,���� ������� ��������;
	// false, ���� ������� ��� ���
	bool insert(const T& key);
	// 3.1 �������� �������� �� ������, �� ���������� ������� ���������
	// true,���� ������� ������; false, ���� �������� �� ����
	bool deleteKey(const T& key);
	// 4.1 ������ ���������� ����������� ������ � �������� ����� out
	void print(std::ostream& out) const;
	// 5.1 ����������� ���������� ����� ������
	int getCount() const;
	// 6.1 ����������� ������ ������
	int getHeight() const;
	// 7 ��������� ����� ������ (�����������)
	void iterativeInorderWalk() const;
	// 8.1 ��������� ����� ������ (�����������)
	void inorderWalk() const;

private:
	// �������� ��������� ���� �� �������� �� �����
	template <class T>
	struct Node {
		T key_; // �������� �����, ������������ � ����
		Node<T>* left_; // ��������� �� ����� ���������
		Node<T>* right_; // ��������� �� ������ ���������
		Node<T>* p_; // ��������� �� �������� !!! �� ������������
		// ����������� ����
		Node(T key, Node* left = nullptr, Node* right = nullptr, Node* p = nullptr) :
			key_(key), left_(left), right_(right), p_(p)
		{ }
	};

	Node<T>* root_; // ��������� �� �������� ����

	// 1.2 ������� ������ ������ ���� �� ����� � �������� ������ ������
	Node<T>* iterativeSearchNode(const T& key) const;
	// 4.2 ����������� ������� ��� ������ ����������� ������ � �������� �����
	void printNode(std::ostream& out, Node<T>* root) const;
	// 5.2 ����������� ������� ����������� ���������� ����� ������
	int getCount(const Node<T>* node) const;
	// 6.2 ����������� ������� ����������� ������ ������
	int getHeight(const Node<T>* node) const;
	// 8.2 ����������� ������� ��� ����������� ������ ����� ������.
	void inorderWalk(Node<T>* node) const;

	// �������� ������
	void deleteTree(Node<T>* node);
	// ��������� ��������
	Node<T>* getMin(Node<T>* node);
	// ����� ������������ �����
	Node<T>* findSuccessor(Node<T>* node);

};  // ����� ������� ������ TreeBinarySearchTree

// ���������� ����������� ������, ������� ������ ������
template <class T>
BinarySearchTree<T>::~BinarySearchTree()
{
	deleteTree(root_);
}

// �������� ������
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

// �������� ������������� ������������
template <class T>
BinarySearchTree<T>& BinarySearchTree<T>::operator=(BinarySearchTree<T>&& src)
{
	root_ = src.root_;
	src.root_ = nullptr;
}

// 1.1 ������� ������ �� ����� � �������� ������ ������
template <class T>
bool BinarySearchTree<T>::iterativeSearch(const T& key) const
{
	return (iterativeSearchNode(key) != nullptr);
}

// 1.2 ������� ������ ������ ���� �� ����� � �������� ������ ������
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

// 2.1 ������� ������ �������� � ������
template <class T>
bool BinarySearchTree<T>::insert(const T& key)
{
	Node<T>* x = root_;
	Node<T>* prev = nullptr;

	// ����� ����� ��� �������
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

	if (x != nullptr) // �������� ������� ������
	{
		return 0;
	}
	else // ��������� �������� �� �������
	{
		Node<T>* newNode = new Node<T>(key);

		if (prev == nullptr) // ������ ������
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

// 3.1 �������� �������� �� ������, �� ���������� ������� ���������
template <class T>
bool BinarySearchTree<T>::deleteKey(const T& key)
{
	Node<T>* x = iterativeSearchNode(key);

	if (x == nullptr) // ������� �� ������
	{
		return 0;
	}
	else // ������� ������
	{
		if ((x->left_ == nullptr) && (x->right_ == nullptr)) // � ���� ��� �����������
		{
			if (x->p_ == nullptr) // ���� - ������
			{
				root_ = nullptr;
			}
			else // ���� - �� ������
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
		else // � ���� ���� ����������
		{
			if ((x->left_ != nullptr) && (x->right_ == nullptr)) // � ���� ���� ��������� �����
			{
				if (x->p_ == nullptr) // ���� - ������
				{
					root_ = x->left_;
					x->left_->p_ = nullptr;
				}
				else // ���� - �� ������
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
			else if ((x->left_ == nullptr) && (x->right_ != nullptr)) // � ���� ���� ��������� ������
			{
				if (x->p_ == nullptr) // ���� - ������
				{
					root_ = x->right_;
					x->right_->p_ = nullptr;
				}
				else // ���� - �� ������
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
			else // � ���� ��� ����������
			{
				Node<T>* nextNode = findSuccessor(x); // ����� ������������ ����

				if ((nextNode->left_ == nullptr) && (nextNode->right_ == nullptr)) // � ������������ ���� ��� �����������
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
				else // � ������������ ���� ���� ���� ��������� (������)
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

// 4.1 ������ ���������� ����������� ������ � �������� ����� out
template <class T>
void BinarySearchTree<T>::print(std::ostream& out) const
{
	if (root_ == nullptr)
	{
		out << "������ ������";
	}
	else
	{
		printNode(out, root_);
	}
	out << '\n';
}

// 4.2 ����������� ������� ��� ������ ����������� ������ � �������� �����
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

// 5.1 ����������� ���������� ����� ������
template <class T>
int BinarySearchTree<T>::getCount() const
{
	return getCount(this->root_);
}

// 5.2 ����������� ������� ����������� ���������� ����� ������
template <class T>
int BinarySearchTree<T>::getCount(const Node<T>* node) const
{
	if (node == nullptr)
	{
		return 0;
	}

	return (1 + getCount(node->left_) + getCount(node->right_));
}

// 6.1 ����������� ������ ������
template <class T>
int BinarySearchTree<T>::getHeight() const
{
	return getHeight(this->root_) - 1;
}

// 6.2 ����������� ������� ����������� ������ ������
template <class T>
int BinarySearchTree<T>::getHeight(const Node<T>* node) const
{
	if (node == nullptr)
	{
		return 0;
	}

	return (1 + std::max(getHeight(node->left_), getHeight(node->right_)));
}

// ��������� ��������
template <class T>
BinarySearchTree<T>::Node<T>* BinarySearchTree<T>::getMin(Node<T>* node)
{
	while (node->left_ != nullptr)
	{
		node = node->left_;
	}

	return node;
}

// ����� ������������ �����
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

// 7 ��������� ����� ������ (�����������)
template <class T>
void BinarySearchTree<T>::iterativeInorderWalk() const
{
	if (root_ == nullptr)
	{
		std::cout << "������ ������";
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

// 8.1 ��������� ����� ������ (�����������)
template <class T>
void BinarySearchTree<T>::inorderWalk() const
{
	if (root_ == nullptr)
	{
		std::cout << "������ ������";
	}
	else
	{
		inorderWalk(this->root_);
	}
	std::cout << '\n';
}

// 8.2 ����������� ������� ��� ����������� ������ ����� ������.
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