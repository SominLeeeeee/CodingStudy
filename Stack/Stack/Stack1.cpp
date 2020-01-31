#include <iostream>
#include <stack>
using namespace std;

int main() {
	stack<int> s;

	s.push(1);
	s.push(2);
	s.push(3);

	s.pop();

	cout << s.top() << endl;
	
	cout << s.size() << endl;
}

void printStack(stack<int> s) {
	cout << "top" << endl << "  ";
	while (!s.empty()) {
		cout << s.top() << " - ";
		s.pop();
	}
	cout << endl << endl;
}