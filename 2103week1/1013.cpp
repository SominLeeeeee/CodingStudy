#include <iostream>
#include <string>
#include <regex>

using namespace std;

void pattern_exist(string str);

int main() {
    int N;  // test case number
    cin >> N;
    
    string test;
    for(int i = 0; i < N; i++) {
        cin >> test;

        pattern_exist(test);
    }
}

void pattern_exist(string str) {
    bool result = regex_match(str, regex("(100+1+|01)+"));
    cout << (result ? "YES" : "NO") << "\n";
}