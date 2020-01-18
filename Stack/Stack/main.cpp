#include "stack.h"
#include <iostream>
using namespace std;

int main() {
	Stack* s = new Stack(5);

	for (int i = 1; i <= 6; i++) {
		s->push(i);
	}

	for (int i = 0; i < 6; i++) {
		s->pop();
	}

}