#include <iostream>
#include <string>
using namespace std;

void test_1() {
	string s = "hello, world!";
	s.insert(0, "y");
	cout << s << endl;

	s.insert(0, 5, 'X');
	cout << s << endl;

	s.erase(0, 5);
	cout << s << endl;

	s.replace(0, 1, "hello");
	cout << s << endl;
}

int main() {
	test_1();

	return -1;
}