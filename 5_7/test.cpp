#include <iostream>
using namespace std;

// 面向对象的三大特性：封装 继承 多态
// 封装：将数据和方法包装起来，方便于统一管理

// this指针存在栈上面，因为需要频繁的访问

// 类的6个默认函数
// --- 初始化和清理 --- 构造函数
//		|		    |--- 析构函数
//		拷贝复制 --- 拷贝构造
//		|		 |--- 复制重载
//		取地址重载 --- 普通对象取地址
//				   |--- const对象取地址

// 编译器自动生成的构造函数，会自动调用自定义类型的构造函数
// 没有规定是否处理内置类型

class student {
public:
	// 无参
	//student() {
	//	_gender = 0;
	//	_age = 0;
	//	_height = 0;
	//}

	// 有参
	student(bool gender = 0, int age = 0, int height = 0) {
		_gender = gender;
		_age = age;
		_height = height;
	}

	~student(){
		cout << "Free up space!" << endl;
	}

	void init(bool gender, int age, int height) {
		_gender = gender;
		_age = age;
		_height = height;
	}

	void show_info() {
		cout << _gender << endl;
		cout << _age << endl;
		cout << _height << endl;
	}

private:
	bool _gender;
	int _age;
	int _height;
};


void test_1() {
	student lq;
	lq.init(0, 1, 1);
	lq.show_info();

	cout << "The size of class student: " << sizeof(lq) << endl;
	cout <<"The size of lq: "<< sizeof(student) << endl;
}

class Test {
public:
	void Print() {
		cout << "Print()" << endl;
	}

private:
	int _a;
};

void test_2() {
	Test* t = nullptr;
	t->Print();
}

// 构造函数在对象生成的时候自动调用
// 析构函数在对象生命周期结束时自动调用释放空间
// 不可以如此定义student stu_1()，会和函数声明混淆
void test_3() {
	student stu_1;
	stu_1.show_info();

	student stu_2(1, 22, 31);
	stu_2.show_info();
}

//int main() {
//	//test_1();
//	//test_2();
//	//test_3();
//
//	return -1;
//}

int A = 2;

namespace mySpace {
	int A = 1;
}

using mySpace::A;

int main() {
	int A = 3;

	cout << A;
	return -1;
}