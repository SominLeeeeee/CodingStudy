// https://acmicpc.net/problem/2941
// c=, c-, dz=, d-, lj, nj, s=, z=

#include <iostream>
#include <string>
using namespace std;

int main() {
    int num = 0;
    string str;

    cin >> str;

    for(int i = 0; i < str.size(); i++) {
        if(str[i] == 'c') {
            if(str[i+1] == '=' || str[i+1] == '-') i++;
        }
        else if(str[i] == 'd') {
            if(str[i+1] == '-') i++;
            else if(str[i+1] == 'z' && str[i+2] == '=') i = i+2;
        }
        else if(str[i] == 'l') {
            if(str[i+1] == 'j') i++;
        }
        else if(str[i] == 'n') {
            if(str[i+1] == 'j') i++;
        }
        else if(str[i] == 's') {
            if(str[i+1] == '=') i++;
        }
        else if(str[i] == 'z') {
            if(str[i+1] == '=') i++;
        }
        num++;
    }
    cout << num;
}