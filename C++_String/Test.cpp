#define  _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

int main(){
	//string s0;
	//string s1("12345");
	//for (size_t i = 0; i < s1.size(); i++)
	//{
	//	cout << s1[i] << " ";
	//}
	//cout << endl;

	//string::iterator it = s1.begin();
	//while (it != s1.end()) {
	//	cout<<*it++;
	//}
	//cout << endl;
	//for (auto ch : s1) {
	//	cout << ch << " ";
	//}
	//cout << endl;

	////string::reverse_iterator rit = s1.rbegin();
	//auto rit = s1.rbegin();
	//while (rit != s1.rend()) {
	//	cout << *rit++ << " ";
	//}
	//cout << endl;

	//string a("1");
	//char b = '2';
	////char c = a + b;

	//cout <<a.size();

	/*string str("hello");
	cout << str.size() << endl;
	cout << str.capacity() << endl;*/

	/*str.reserve(100);
	cout << str.size() << endl;
	cout << str.capacity() << endl;

	str.resize(100);
	cout << str.size() << endl;
	cout << str.capacity() << endl;
	cout << str << endl;*/

	////str.assign(" world");
	////cout << str << endl;
	////cout << str.size() << endl;
	////cout << str.capacity() << endl;

	string s1("abc");
	string s2("a");

	cout << (s1 > s2);
}