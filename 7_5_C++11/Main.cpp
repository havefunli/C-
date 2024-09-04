#include <iostream>
#include <vector>
using namespace std;

struct A {
	// explicit 关键词会阻止隐式类型转换
	A(int a, int b)
		: _a(a)
		, _b(b)
	{}
	
	int _a;
	int _b;
};

// 列表初始化
// 支持单参数，多参数
// 一切皆可用列表初始化
void test_1() {
	vector<int> arr{ 1, 2, 3 };

	A a1 = { 1, 2 };
}

// auto 关键字
// 自动推导类型
// typeid 获取变量类型
void test_2() {
	vector<int> arr{ 1, 2, 3 };
	auto it = arr.begin();

	cout << typeid(it).name() << endl;

	decltype(it) it1 = arr.begin();
}

// 范围 for
// 使用的是拷贝，不必要加上引用
void test_3() {
	vector<int> arr{ 1, 2, 3 };

	for (auto& e : arr) {
		cout << e << " ";
	}
	cout << endl;
}

// 左值和右值的定义
// 左值：可以取地址的表达式
// 右值：不可以取值的表达式
void test_4() {
	int A = 1;
	string str("abcd");
	// 左值引用
	int& ref1 = A;
	string& ref2 = str;
	// 右值引用
	int&& ref3 = 1;
	string&& ref4 = "abcd";
	// 左值引用不可以直接接受右值，但是加上 const 可以
	const string& ref5 = "abcd";
	// 右值引用不可以直接接受左值，但是加上 move 可以
	string&& ref6 = move(str);
}

int main() {
	// test_1();
	// test_2();
	// test_3();
	test_4();
	return 0;
}