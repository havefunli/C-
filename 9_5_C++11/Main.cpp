//#include <iostream>
#define _CRT_SECURE_NO_WARNINGS 1 
#include <memory>
//
//// 测试 auto_ptr
//// 赋值给其他对象后，本对象会被悬空（本质是转移管理权）
//void _Func_1(std::auto_ptr<int> ptr)
//{
//	*ptr = 1;
//}
//
//void Func_1()
//{
//	std::auto_ptr<int> sp1(new int[2]);
//	std::auto_ptr<int> sp2(sp1);
//	// _Func_1(sp1);
//}
//
//// 测试 unique_ptr
//void Func_2()
//{
//	std::unique_ptr<int> sp(new int);
//	int* ptr = sp.get();
//}
//
//// 测试 shared_ptr
//void Func_3()
//{
//	int* ptr = new int(1);
//	std::shared_ptr<int> sp1(ptr);
//	std::shared_ptr<int> sp2(ptr);
//}
//
//
//int main()
//{
//	// Func_1();
//	// Func_2();
//	Func_3();
//
//	return 0;
//}

#include <string>
#include "SharedPtr.hpp"

template <class T>
class SmartPtr
{
public:
	SmartPtr(T* Ptr)
		:_Ptr(Ptr)
	{}

	// Ohther Functions... 

	~SmartPtr()
	{
		std::cout << "Delete Ptr" << std::endl;
		delete _Ptr;
	}

private:
	T* _Ptr;
};

class MyClass
{
public:
	MyClass()
		:_A(1)
	{}

	void DoSomething()
	{
		std::cout << "I am working!" << std::endl;
	}

	~MyClass()
	{
		std::cout << "~MyClass()" << std::endl;
	}
private:
	int _A;
};


void Ptr_1()
{
	std::unique_ptr<MyClass> up1(new MyClass); 
	up1->DoSomething();

	std::unique_ptr<MyClass> up2(move(up1)); // 移动构造
	std::cout << up1 << std::endl; // up1 这时已被悬空
}

void Ptr_2()
{
	std::shared_ptr<MyClass> sp1(new MyClass); // 构造 
	std::shared_ptr<MyClass> sp2(sp1); // 拷贝构造
	sp2->DoSomething();

	std::cout << "The use counts = " << sp1.use_count() << std::endl; // 查看计数器
}

struct Node
{
	Node(int val)
		:_val(val)
	{}

	~Node()
	{
		std::cout << "~Node()" << std::endl;
	} 

	int _val;
	std::weak_ptr<Node> _prev;
	std::weak_ptr<Node> _next;
};

void Ptr_3()
{
	std::shared_ptr<Node> sp1(new Node(1));
	std::shared_ptr<Node> sp2(new Node(2));
	
	// 相互指向
	sp1->_next = sp2;
	sp2->_prev = sp1;
}

void Ptr_4()
{
	// std::weak_ptr<int> wp(new int(1)); // 错误的使用方法 weak_ptr 不能直接管理对象的生命周期

	std::shared_ptr<int> sp(new int(1));
	std::weak_ptr<int> wp(sp);
	std::cout << wp.use_count() << std::endl; // weak_ptr 并不拥有它所指向的对象，因此不会增加或减少对象的引用计数。
}

void Ptr_5()
{
	std::shared_ptr<FILE> sp(fopen("test.txt", "w"), [](FILE* file) { fclose(file); });
}

int main()
{
	// Ptr_1();
	// Ptr_2();
	// Ptr_3();
	// Ptr_4();
	// Ptr_5();
	
	int* ptr = new int(1);
	delete ptr;

	std::cout << ptr << std::endl;
	
	return 0;
}