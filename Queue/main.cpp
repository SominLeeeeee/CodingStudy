#include "Queue.h"
using namespace std;

int main() {
	Queue* q = new Queue;
	
	for (int i = 1; i <= 5; i++) {
		q->push(i);
	}

	//q->print();

	for (int i = 0; i < 6; i++) {
	//	q->print();
		q->pop();
	}
}