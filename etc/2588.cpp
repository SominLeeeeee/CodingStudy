#include <iostream>
using namespace std;

int main() {
	int operand1, operand2;
	int num1, num2, num3;
	
	cin >> operand1 >> operand2;
	
	num1 = operand2 / 100;
	num2 = operand2 / 10 % 10;
	num3 = operand2 % 10;
	
	cout << operand1 * num3 << '\n';
	cout << operand1 * num2 << '\n';
	cout << operand1 * num1 << '\n';
	cout << operand1 * operand2;
}
