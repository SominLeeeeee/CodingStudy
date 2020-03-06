#include <iostream>
#include <set>
using namespace std;

int main() {

    set<int> s;

    s.insert(40);
    s.insert(10);
    s.insert(80);
    s.insert(20);
    s.insert(70);
    s.insert(90);
    s.insert(30);
    s.insert(50);
    s.insert(60);

    set<int>::iterator iter;
    for(iter = s.begin(); iter!= s.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;

    s.insert(20);
    auto it = s.begin();
    for(; it != s.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}