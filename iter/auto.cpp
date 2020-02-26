#include <iostream>
#include <vector>
#include <typeinfo>
using namespace std;


void addauto(auto x, auto y) {
    cout << x+y << endl;
}

auto add(int x, int y) {
    return x + y;
}

int main() {
    vector<int> vec;

    for(int i = 0; i < 5; i++) {
        vec.push_back(i);
    }

    auto it = vec.begin();
    cout << "it type is " << typeid(it).name() << endl;
    cout << "func type is " << typeid(add(3, 4)).name() << endl;

    addauto(3, 4);

    return 0;
}