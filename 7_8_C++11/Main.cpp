#include <iostream>
#include <vector>
using namespace std;

//void test_1() {
//	int A = 1;
//	int B = 2;
//
//	auto Swap1 = [](int& left, int& right)
//		{
//			int temp = left;
//			left = right;
//			right = temp;
//		};
//
//	Swap1(A, B);
//
//	// 捕捉参数(默认传值捕捉)
//	// mutable 可以修改传值对象
//	auto Swap2 = [&A, &B]() mutable
//		{
//			int temp = A;
//			A = B;
//			B = temp;
//		};
//	Swap2();
//}
//
//void test_2() {
//	int A = 1;
//	int B = 2;
//	int C = 3;
//
//	// 传值捕捉所有的变量
//	auto Func1 = [=]()->int 
//		{
//			return A + B + C;
//		};
//
//	cout << Func1() << endl;
//
//	// 传引用捕捉所有的变量
//	auto Func2 = [&]()->int
//		{
//			return A + B + C;
//		};
//
//	cout << Func2() << endl;
//
//	// 传值，传引用混合捕捉所有的变量
//	auto Func3 = [&, B]()->int
//		{
//			return A + B + C;
//		};
//
//	cout << Func3() << endl;
//}
//
//// 没有实现析构，拷贝构造，赋值重载的任意一个
//// 就会生成一个默认的移动构造
//// 对于内置类型逐字节拷贝，自定义类型调用拷贝构造
//
//// 对不想被调用的函数
//// 可以私有化
//// 也可以加上 delete 表示删除
//class A {
//public:
//	A(const int& a) = delete;
//private:
//	int _a = 1;
//};
//
//template<class ...Args>
//void Printf(Args... args) {
//	cout << sizeof...(args) << endl;
//}
//
//void test_3() {
//	Printf("abcd", 2);
//}
//
//void test_4() {
//	vector<pair<string, int>> v;
//	v.push_back({"abcd", 1}); // 构造->拷贝构造
//	// 会直接利用该参数去初始化结点的值
//	v.emplace_back("abcd", 1); // 构造
//}
//
//void test_5() {
//	auto A = 1;
//	cout << typeid(A).name() << endl;
//
//
//}

//int main() {
//	// test_1();
//	// test_2();
//	// test_3();
//	// test_4();
//	test_5();
//	return 0;
//}


void test_1() {
	vector<int> arr = { 1, 2, 3 ,4 };
	
	for (auto e : arr) {
		cout << e << " ";
	}
	cout << endl;
}

void test_2() {
	vector<int> arr = { 1, 2, 3 ,4 };

	for (auto e : arr) {
		++e;
	}

	for (auto e : arr) {
		cout << e << " ";
	}
	cout << endl;
}

void test_3() {
	vector<int> arr = { 1, 2, 3 ,4 };

	auto it = arr.begin();
	while (it != arr.end()) {
		cout << *it << " ";
		++it;
	}
}

class Test {
public:
	Test(int A, int B) {
		_A = A;
		_B = B;
	}
private:
	int _A;
	int _B;
};

void test_4() {
	int arr[] = { 1, 2, 3, 4 };
	Test t1 = { 1, 2 };
}

void test_5() {
	// 对内置类型初始化
	int A = { 1 };
	int B{ 2 }; // 甚至可以去除 = 

	vector<int> arr = { 1, 2, 3, 4 };

	// 对自定义类型初始化
	Test t2{ 1, 2 };

	// 对 new 表达式初始化
	int* ptr = new int[2] {1, 2};
	delete[] ptr;
}

class Base final {
public:
	virtual void Func1() {
		cout << "Base::Func1()" << endl;
	}

	void Func2() {
		cout << "Base::Func2()" << endl;
	}

private:
	int _base = 1;
};

class Derive : public Base{
public:
	void Func1() {
		cout << "Derive::Func1()" << endl;
	}

private:
	int _derive = 1;
};

void test_6() {
	Derive d = Derive();
	Base& base = d;
	base.Func1();
}

int main()
{
	// test_1();
	// test_2();
	// test_3();
	// test_4();
	test_6();
	return 0;
}