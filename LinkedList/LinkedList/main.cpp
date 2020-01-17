#include "doubleList.h"
using namespace std;

int main() {
	List* l = new List;

	l->addNodeLast(2);
	l->addNodeLast(3);
	l->addNodeLast(4);
	l->addNodeLast(5);
	l->addNodeLast(6);
	l->addNodeLast(8);

	l->printList();

	l->addNodeFirst(1);
	l->printList();

	l->addNode(7, 8);
	l->printList();

	l->delNode(3);
	l->printList();

	l->delNodeFirst();
	l->printList();

	l->delNodeLast();
	l->printList();

	return 0;
}