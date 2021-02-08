#include <iostream>
#include <vector>
#include <string>
using namespace std;

string inverse(string str);

int main() {
	int N, temp;
	cin >> N;

	vector<string> password;
	password.resize(N);

	for(int i = 0; i < N; i++) {
		cin >> password[i];	
	}

	for(int i = 0; i < N; i++) {
		for(int j = 1; j < N; j++) {
			if(!inverse(password[i]).compare(password[j])) {
				// 두 스트링이 같은것
				int size = password[i].size();
				cout << size << " " << password[i][size/2];
				return 0;
			}
		}		
	}

	
}

string inverse(string str) {
	string result;

	for(auto iter = str.end(); iter != str.begin(); iter--) {
		result += *iter;
	}

	return result;
}
