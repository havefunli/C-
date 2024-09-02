#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Arr {
	Arr(size_t size = 1)
		:_ptr(nullptr)
		,_size(0)
	{
		_ptr = new int[size];
		_size = size;
	}

	Arr(const Arr& arr) {
		_ptr = new int[arr._size];
		_size = arr._size;
	}

	void Swap(Arr&& arr) {
		std::swap(_ptr, arr._ptr);
		std::swap(_size, arr._size);
	}

	Arr(Arr&& arr) {
		Swap(move(arr));
	}

	Arr& operator=(Arr&& arr) {
		Swap(move(arr));
		return *this;
	}

	~Arr() {
		delete[] _ptr;
		_ptr = nullptr;
	}

	int *_ptr;
	size_t _size;
};

//void test_1() {
//	Arr a1(Arr(5));
//}
//
//void test_2() {
//	int A = 1;
//	int&& ref1 = 1;
//
//	cout << typeid(ref1).name() << endl;
//}

Arr Func() {
	Arr temp(1);
	return temp;
}

void test_3() {
	Arr arr = Func();
}

void test_4() {
	Arr arr1(1);
	// 普通的拷贝构造
	Arr arr2 = arr1;
	// 将 arr1 转化为将亡值，进行移动构造 
	Arr arr3 = move(arr1);
}

void Fun(int& x) { cout << "左值引用" << endl; }
void Fun(const int& x) { cout << "const 左值引用" << endl; }
void Fun(int&& x) { cout << "右值引用" << endl; }
void Fun(const int&& x) { cout << "const 右值引用" << endl; }


template<class T>
void PerfectForward(T&& t)
{
	Fun(t);
}

void test_5() {
	int A = 1;
	PerfectForward(A);

	PerfectForward(1);
}

int main() {
	// test_1();
	// test_2();
	// test_3();
	// test_4();
	//test_5();
	const int A = 1;
	cout << &A << endl;

	return 0;
}