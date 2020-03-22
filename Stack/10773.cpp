// https://www.acmicpc.net/problem/10773 

#include <iostream>
#include <stack>
using namespace std;

int main() {
	int K;
	cin >> K;	// 정수 몇개?
	
	stack<int> number;
	int temp;
	int sum = 0;	// 입력받은 숫자들의 합 
	
	for(int i = 0; i < K; i++) {
		cin >> temp;
		if(temp != 0) number.push(temp);	// 그냥 숫자면 넣고 
		else number.pop(); // 0이면 있는 숫자를 빼자 
	}
	
	while(!number.empty()) {
		sum += number.top();
		number.pop();	// 최종적으로 스택에 남은 애들만 더한다 
	} 
	
	cout << sum << endl;
}
