#include <iostream>
using namespace std;

void test_1() {
	int A = 1;
	int B = 2;

	auto Swap1 = [](int& left, int& right)
		{
			int temp = left;
			left = right;
			right = temp;
		};

	Swap1(A, B);

	// 捕捉参数(默认传值捕捉)
	// mutable 可以修改传值对象
	auto Swap2 = [&A, &B]() mutable
		{
			int temp = A;
			A = B;
			B = temp;
		};
	Swap2();
}

void test_2() {
	int A = 1;
	int B = 2;
	int C = 3;

	// 传值捕捉所有的变量
	auto Func1 = [=]()->int 
		{
			return A + B + C;
		};

	cout << Func1() << endl;

	// 传引用捕捉所有的变量
	auto Func2 = [&]()->int
		{
			return A + B + C;
		};

	cout << Func2() << endl;

	// 传值，传引用混合捕捉所有的变量
	auto Func3 = [&, B]()->int
		{
			return A + B + C;
		};

	cout << Func3() << endl;
}

// 没有实现析构，拷贝构造，赋值重载的任意一个
// 就会生成一个默认的移动构造
// 对于内置类型逐字节拷贝，自定义类型调用拷贝构造

// 对不想被调用的函数
// 可以私有化
// 也可以加上 delete 表示删除
class A {
public:
	A(const int& a) = delete;
private:
	int _a = 1;
};

template<class ...Args>
void Printf(Args... args) {
	cout << sizeof...(args) << endl;
}

void test_3() {
	Printf("abcd", 2);
}

int main() {
	// test_1();
	// test_2();
	test_3();
	return 0;
}