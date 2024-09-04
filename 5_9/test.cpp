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

	// 加上const避免stu被修改
	student(const student& stu) {
		cout << "(student& stu)" << endl;

		_gender = stu._gender;
		_age = stu._age;
		_height = stu._height;
	}

	~student() {
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
	cout << "The size of lq: " << sizeof(student) << endl;
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

// 无参的，全缺省的，编译器默认生成的函数都称为默认构造函数
// 如果没有显示的去实现构造函数，编译器才会默认生成
// 默认构造函数只能存在一个


// 析构函数用于释放自定义类型的空间
// 会自动调用自定义类型的析构函数

class A {
public:
	~A() {
		cout << "~A()" << endl;
	}
};

class B {
public:
	~B() {
		cout << "~B()" << endl;
	}

private:
	A a;
};


void test_4() {
	B b;
}

// 自定义传值传参会调用拷贝构造
// 默认生成的拷贝构造是值拷贝(浅拷贝)
void test_5() {
	student lq(1, 2, 3);

	student lmy(lq);
	lmy.show_info();
}

int main() {
	//test_1();
	//test_2();
	//test_3();
	//test_4();
	test_5();

	return -1;
}