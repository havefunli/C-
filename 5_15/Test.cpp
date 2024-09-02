#include <string>
#include <iostream>
using namespace std;
//
//void test_1() {
//	string s1;
//	string s2("hello");
//	cout << s1 << endl;
//	cout << s2 << endl;
//
//	string s3(s2, 0, 5);
//	cout << s3 << endl;
//}
//
//void test_2() {
//	string s1 = "ABCD";
//	cout << s1.size() << endl;
//}
//
//void test_3() {
//	string a = "hello world";
//
//	string b = a;
//
//	if (a.c_str() == b.c_str())
//
//	{
//
//		cout << "true" << endl;
//
//	}
//
//	else cout << "false" << endl;
//
//	string c = b;
//
//	c = "";
//
//	if (a.c_str() == b.c_str())
//
//	{
//
//		cout << "true" << endl;
//
//	}
//
//	else cout << "false" << endl;
//
//	a = "";
//
//	if (a.c_str() == b.c_str())
//
//	{
//
//		cout << "true" << endl;
//
//	}
//
//	else cout << "false" << endl;
//}
//
//void test_4() {
//	string str("Hello Bit.");
//
//	str.reserve(111);
//
//	str.resize(5);
//
//	str.reserve(50);
//
//	cout << str.size() << ":" << str.capacity() << endl;
//}
//
//void main(){
//	// test_1();
//	// test_2();
//	// test_3();
//	
//	string str("ABCD");
//	cout << str.capacity() << endl;
//	// test_4();
//}

#include <iostream>
#include <stdlib.h>
using namespace std;

class Body {
public:
	Body(int height = 170, int weight = 60) {
		_height = height;
		_weight = weight;
	}

	void Print() {
		cout << _height << " " << _weight << endl;
	}

private:
	int _height;
	int _weight;
};

class Stack {
public:
	Stack(int n) {
		_arr = (int*)malloc(sizeof(int) * n);
	}

	~Stack() {
		free(_arr);
	}

	void push() {}

	void pop() {}

	void Top() {}

private:
	int* _arr;
	int size;
};

class Student {
public:
	// 这是无参的
	Student(int math = 1, int chinese = 1, int english = 1) {
		_math = math;
		_chinese = chinese;
		_english = english;
	}

	Student(const Student& S) {
		_math = S._math;
		_chinese = S._chinese;
		_english = S._english;
	}

	Student operator=(const Student& S) {
		_math = S._math;
		_chinese = S._chinese;
		_english = S._english;
	}

	~Student() {
		cout << "~Student()" << endl;
	}

	void Print() {
		cout << _math << " " << _chinese << " " << _english << endl;
	}

private:
	int _math;
	int _chinese;
	int _english;
};

int main() {
	Student Li(100, 100, 100);
	Student Zhang = Li;
	
	Student Wang(100, 100, 100);
	Student He;
	He = Wang; 

	return - 1;
}