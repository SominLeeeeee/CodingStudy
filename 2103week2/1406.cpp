#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
    list<char> str_list;
    int M;  // instruction num
    string str;

    cin >> str;
    for (auto iter = str.begin(); iter != str.end(); iter++) {
        str_list.push_back(*iter);
    }

    cin >> M;
    char instruct, ins;
    auto it = str_list.end()--;

    for (int i = 0; i < M; i++) {
        cin >> instruct;
        switch (instruct) {
            case 'L':
                if (it != str_list.begin()) it--;
                break;

            case 'D':
                if (it != str_list.end()) it++;
                break;

            case 'B':
                if (it != str_list.begin()) {
                    it--;
                    str_list.erase(it++);
                }
                break;

            case 'P':
                cin >> ins;
                str_list.insert(it, ins);
                break;
        }
    }

    for (auto iter = str_list.begin(); iter != str_list.end(); iter++) {
        cout << *iter;
    }
    cout << endl;
}