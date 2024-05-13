#include <iostream>
using namespace std;

// 匿名对象的生命周期在本行
// 匿名对象和临时对象都具有常性

class A {
public:
	A(int a = 1) {
		cout << "A()" << endl;
		_a = 1;
	}

	~A() {
		cout << "~A()" << endl;
	}

private:
	int _a;
};

//int main() {
//	// A(1);
//	// A(2);
//}

// malloc不会初始化，calloc会初始化
// 在堆上开辟的空间，需要指定释放
// delete -> 首先调用析构函数，再operator delete

int main() {
	// 内置类型
	int* p1 = new int(1);
	int* p2 = new int[5] {1, 2, 3, 4, 5};
	delete p1;
	delete[] p2;

	A* p3 = new A(3);
	delete[] p3; 
}
