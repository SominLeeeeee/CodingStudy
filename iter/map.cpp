#include <iostream>
#include <map>
#include <string>
#include <typeinfo>
using namespace std;

int main() {

	map<string, int> m;

	m.insert(make_pair("aa", 1));
	m.insert(make_pair("bb", 2));
	m.insert(make_pair("cc", 3));	
	m.insert(make_pair("dd", 4));
	m.insert(make_pair("ee", 5));
	m["ff"] = 6;	// 이런식의 삽입도 가능하다

	m["banana"] = 7;

	m.erase("dd");
	m.erase("ee");
	m.erase(m.find("ff"));

	m.erase("gg");
	// 해본 결과 없는 key를 지우라고 해도 에러를 내뱉지 않는다!

	cout << "size is " << m.size() << endl << endl;

	cout << "aa second : " << m.find("aa")->second << endl;
	cout << "bb first : " << m.find("bb")->first << endl;

	m["aa"] = 100;
	cout << "aa count : " << m.count("aa") << endl;
	// unique한 key를 가지기 때문에 추가되는 것이 아니고 값이 수정된다!

	for(auto it = m.begin(); it != m.end(); it++) {
		cout << "key : " << it->first << " value : " << it->second << endl;
	}

	auto it = m.begin();
	cout << "it type is " << typeid(it).name() << endl;
	cout << "a type is " << typeid(a).name() << endl;

	cout << m.find("aa")->second << endl;
	return 0;
}
