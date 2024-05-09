#include <iostream>
using namespace std;

void test_1() {
	const int A = 1;
	const int* ptr = &A;
	cout << *ptr << endl;

	// 表达式会产生临时变量
	const int& C = 2 * A;

	// 临时变量和指针的区别
	// 两者在底层上都需要开空间
	int a = 0;
	int& b = a; // 在语法上不需要开空间
	int* p = &a;// 在语法上需要开空间

	// 两者++的含义不同，前者是一个地址的大小，另一个是值加一
	int* ptr1 = &a;
	int& r = *ptr1;

	cout << sizeof(int*) << endl;
	// 该结果取决于应用类型的大小
	cout << sizeof(r) << endl;
}

void test_2() {
	// inline只是一个建议，具体会不会是内联取决于编译器
	// 内联的声明定义不支持分离
	// 内联的使用一般都是比较简短的函数
}

void test_3() {

}


int main() {
	// 引用
	test_1();
	// 内联函数
	test_2();
	// 类和对象
	test_3();

	return -1;
}