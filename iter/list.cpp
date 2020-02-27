#include <iostream>
#include <list>

using namespace std;

int main(){

	list<int> l;


	// push_back
	l.push_back(5);
	l.push_back(6);
	l.push_back(7);
	l.push_back(8);
	l.push_back(9);
	l.push_back(10);

	// pop_back
	l.pop_back();

	// push_front
	l.push_front(4);
	l.push_front(3);
	l.push_front(1);
	l.push_front(0);

	// pop_front
	l.pop_front();

	// iterator
	list<int>::iterator iter = l.begin(); // auto iter = l.begin()도 가능

    for(; iter != l.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;

    auto it = l.begin();
    for(; it != l.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

	return 0;

}
