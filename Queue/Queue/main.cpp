#include <iostream>
#include "Queue.h"
#include "BinarySearchTree.h"
#include "testFunction.h"

int main()
{
	setlocale(LC_ALL, "rus");

	try
	{
		testEnQueue();
		testDeQueue();
		testIterativeBreadthWalk();
		testCheckSimilarityTrees();
		testCheckForIdenticalKeys();

		QueueArray<int> q(5);
		q.enQueue(1);
		q.enQueue(2);
		q.enQueue(3);
		q.enQueue(4);
		q.enQueue(5);
		q.deQueue();
		q.deQueue();
		q.deQueue();
		q.enQueue(3);
		q.enQueue(4);
		q.enQueue(5);
		q.print();

		BinarySearchTree<int> t;
		std::cout << t.getHeight() << std::endl;
	}

	catch (const std::exception& error)
	{
		std::cerr << error.what() << '\n';
		return -1;
	}

	return 0;
}