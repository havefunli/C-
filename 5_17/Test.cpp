#include <string>
#include <iostream>
using namespace std;

void test_1() {
	string s = "Liquan is a student.";
	int pos = -1;

	// 满足字串的任意一个
	while ((pos = s.find_first_of("Liquan")) != string::npos) {
		s[pos] = '*';
	}

	cout << s << endl;
}

void test_2() {
	string s = to_string(123344);
	cout << s << endl;
}

int main() {
	//test_1();
	test_2();

	return - 1;
}