#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string name) {
    int answer = 0;

    int visit = name.size(); // 글자 하나 완성할때마다 --, 0이 되면 모든 문자 다 완성한것    
    int ch = 0;
    int cCount = 0;
    int cursor = 0;
    int aCount = 0;
    int dir = 1;

    while(visit != 0) {
                cout << "cursor is " << cursor << endl;

        if(name[cursor] == 65) { // A가 나왔다면?
            aCount++;

            int temp = cursor;
            (dir == 1) ? temp++ : temp--;

            if(temp > name.size()-1) temp = 0;
            else if(temp < 0) temp = name.size() - 1;

            
            while(name[temp] == 65) {
                aCount++;
                (dir == 1) ? temp++ : temp--;
                if(temp > name.size()-1) temp = 0;
                else if(temp < 0) temp = name.size() - 1;
            }

            if(aCount >= cCount) {
                dir *= -1;
                cursor += (cCount * dir);
                if(cursor > name.size()-1) cursor = cursor - name.size() ;
                else if(cursor < 0) cursor = name.size() - 1 + cursor;
                visit = visit - aCount;
            }
            
            else {
                cursor += (aCount * dir);
                if(cursor > name.size()-1) cursor = cursor - name.size();
                else if(cursor < 0) cursor = name.size() - 1 + cursor;
                visit = visit - aCount;
            }
            aCount = 0;
        }

        else if (name[cursor] >= 66 && name[cursor] <= 78){ // B부터 N까지
            ch += name[cursor]-65;
            cCount++;
            (dir == 1) ? cursor++ : cursor--;
            if(cursor > name.size()-1) cursor = 0;
            else if(cursor < 0) cursor = name.size() - 1;
            visit--;
        }

        else {  // O부터 Z까지
            ch += (name[cursor]-91) * -1;
            cCount++;
            (dir == 1) ? cursor++ : cursor--;
            if(cursor > name.size()-1) cursor = 0;
            else if(cursor < 0) cursor = name.size() - 1;
            visit--;
        }
            cout << "ch is " << ch << endl;
    }
    
    answer = cCount + ch;
    cout << "cCount is " << cCount;
    cout << "ch is " << ch;
    return answer;
}

int main() {

    string name = "JAZ";
    solution(name);
}