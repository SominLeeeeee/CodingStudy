#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    vector<int> complete;
    complete.resize(progresses.size());
    
    for(int n = 0; n < progresses.size(); n++) {
        complete[n] = ceil((100-progresses[n]) / (double)speeds[n]);
    }

    int temp = 0;
    int cache = 0;

    for(int i = 0; i < complete.size();) {
        
        if(complete[cache] >= complete[i]) {
            i++;
            temp++;
        }

        else {
            answer.push_back(temp);
            temp = 1;
            cache = i;
            i++;
        }
        
    }

    answer.push_back(temp);

    return answer;
}

int main() {

    vector<int> progresses = {93,30,55};
    vector<int> speeds = {1,30,5};

    solution(progresses, speeds);

}