#include "String.h"

// 构造，析构，拷贝构造，赋值
void test_1() {
	// 构造函数
	my_Space::String s1("abcdefg");
	cout << s1.c_str() << endl;

	// 拷贝构造函数
	my_Space::String s2(s1);
	cout << s2.c_str() << endl;

	// 赋值
	my_Space::String s3;
	s3 = s1;
	cout << s2.c_str() << endl;
}

// 扩容，下标访问，尾插
void test_2() {
	// 扩容
	my_Space::String s1("hello, world!");
	s1.reserve(20);
	cout << s1.c_str() << endl;

	// 下标访问
	for (int i = 0; i < s1.size(); i++) {
		cout << s1[i] << " ";
	}
	cout << endl;

	// 尾插
	s1.push_back('!');
	cout << s1.c_str() << endl;
}

// 迭代器
void test_3() {
	my_Space::String s1("Hello, world!");
	for (auto s : s1) {
		cout << s << " ";
	}
	cout << endl;
}

// 追加字符串
void test_4() {
	my_Space::String s1("Hello, world!");
	s1.append("xxxxxxxx");
	cout << s1.c_str() << endl;
}

// 流插入流提取
void test_5() {
	my_Space::String s1("Hello, world!");
	cout << s1 << endl;

	cin >> s1;
	cout << s1 << endl;
}

void test_6() {
	//std::string s1("abc");
	//cout << s1 << endl;

	//s1.insert(1, 1, 'A');
	//cout << s1 << endl;

	my_Space::String s2("abc");
	cout << s2 << endl;
	
	s2.insert(3, 'A');
	cout << s2 << endl;

	s2.insert(0, "ABCD");
	cout << s2 << endl;
}

int main() {
	// test_1();
	// test_2();
	// test_3();
	// test_4();
	// test_5();
	test_6();

	return 0;
}