#include <iostream>
using namespace std;

// 初始化列表
// 初始化列表可以初始化没有默认构造的自定义类
// 初始化列表可以初始化 const/引用 对象，因为 const/引用 对象只能在定义时初始化

class A {
public:
	A(const int a) {
		_a = a;
		_counts += 1;
	}

	static void Print_counts() {
		cout << _counts << endl;
	}

private:
	int _a;

	// 在静态区，不存在对象
	static int _counts;
};

// 定义
int A::_counts = 0;

class B {
public:
	B(const int b) {
		int _b = 1;
	}

private:
	int _b;
};

class C {
public:
	C(const int a = 1, const int b = 1)
		:_a(a)
		,_b(b)
	{}

private:
	A _a;
	B _b;
	int _c = 1; // 缺省值，给初始化列表使用
};

void Fun() {
	A test(1);
}

// 成员变量的初始化顺序是变量声明的顺序
// 而不是变量在初始化列表的前后顺序
int main(){
	A a_1(1);
	A a_2(2);
	A a_3(3);
	Fun();

	A::Print_counts();
}