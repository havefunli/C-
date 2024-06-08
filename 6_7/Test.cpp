#include <iostream>
using namespace std;

// 基类和派生类的静态成员变量是同一个

// 多继承很合理
// 但是多继承会带来一个菱形继承的问题
// 1.数据冗余 2.数据二义性
// 解决方案：虚继承(virtual)

// 多态
// 不同的对象去做同一件事情，会展现多种形态
// 1.父子类完成虚函数的重写(函数名，参数，返回值)
// 2.父类的指针或者引用调用虚函数

class Man {
public:
	Man() {
		A++;
	}

	void Print_A() {
		cout << A << endl;
	}

private:
	static int A;
	bool male = false;
	int _age = 0;
};
int Man::A = 1;

class Student {
public:
	Student() {}

private:
	int _id = 0;
	int score = 0;
};

class Base1 {
public: 
	int _b1 = 1; 
};

class Base2 {
public:
	int _b2 = 2; 
};

class Derive : public Base1, public Base2{
public: int _d = 3;
};

int main() {
	Derive D;
	return 0;
}