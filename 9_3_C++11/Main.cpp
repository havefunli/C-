// C++11 的学习
// 包装器

#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <functional>
#include <vector>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>

//int AddFunc(const int& left, const int& right)
//{
//	return left + right;
//}
//
//struct AddClass
//{
//	int operator()(const int& left, const int& right)
//	{
//		return left + right;
//	}
//};
//
//
//// 包装器包装可调用对象
//void Func_1()
//{
//	auto LamFunc = [](const int& left, const int& right) { return left + right;  };
//
//	std::function<int(int, int)> fc1 = AddFunc;
//	std::function<int(int, int)> fc2 = AddClass();
//	std::function<int(int, int)> fc3 = LamFunc;
//}
//
//// 绑定可以调整参数顺序个数
//void Func_2()
//{
//	auto Sub = [](const int& left, const int& right) { return left - right; };
//	std::cout << Sub(2, 1) << std::endl;
//
//	// 调整参数顺序
//	auto ReverseSub = std::bind(Sub, std::placeholders::_2, std::placeholders::_1);
//	std::cout << ReverseSub(2, 1) << std::endl;
//
//	// 参数绑定
//	auto BindSub = std::bind(Sub, 10, std::placeholders::_1);
//	std::cout << BindSub(1) << std::endl;
//}
//
////int main()
////{
////	// Func_1();
////	Func_2();
////	return 0;
////}
//
//#include <stdarg.h>
//
//void PrintNums(int cnt, ...)
//{
//	va_list ap;
//
//	// 初始化
//	va_start(ap, cnt);
//
//	// 遍历
//	for (int i = 0; i < cnt; i++)
//	{
//		// 遍历参数包中的所有参数
//		int num = va_arg(ap, int);
//		std::cout << num << ' ';
//	}
//	std::cout << std::endl;
//
//	// 释放
//	va_end(ap);
//}
//
//
////int main()
////{
////	// 第一个参数代表可变参数的个数
////	PrintNums(5, 1, 2, 3, 4, 5);
////	return 0;
////}
//
//
//template <class T>
//int _MyPrint(const T& val)
//{
//	std::cout << val << " ";
//	return 0;
//}
//
//template <class... Args>
//void MyPrint(Args... args)
//{
//	int arr[] = {_MyPrint(args)...};
//	std::cout << std::endl;
//}

//int main()
//{
//	std::vector<std::string> vec;
//
//	// 方式一
//	std::string s = "ABC";
//	vec.push_back(s);
//
//	// 方式二
//	vec.push_back(std::string("ABC"));
//
//	// 方式三
//	vec.emplace_back("ABC");
//
//	return 0;
//}

// 创建两个线程
// 一个线程打印 奇数
// 一个线程打印 偶数


//int main()
//{
//	bool PrintEven = true;
//	int Num = 0; // 两个线程共享的变量
//	std::mutex mtx; // 锁
//	std::condition_variable cond; // 条件变量保证打印顺序
//
//	// 打印偶数的线程
//	std::thread t1([&] ()
//		{
//			while (Num <= 100)
//			{
//				std::unique_lock<std::mutex> lck(mtx);
//				cond.wait(lck, [&] { return PrintEven; });
//				if(Num <= 100)
//					std::cout << "thread-1 => " << Num++ << std::endl;
//				PrintEven = false;
//				cond.notify_all();
//			}
//		}
//	);
//
//	// 打印奇数的线程
//	std::thread t2([&]()
//		{
//			while (Num <= 100)
//			{
//				std::unique_lock<std::mutex> lck(mtx);
//				cond.wait(lck, [&] { return !PrintEven; });
//				if (Num <= 100)
//					std::cout << "thread-2 => " << Num++ << std::endl;
//				PrintEven = true;
//				cond.notify_all();
//			}
//		}
//	);
//
//	cond.notify_all();
//
//	t1.join();
//	t2.join();
//
//	return 0;
//}

//int (*funcPtr)(const int&, const int&);
//
//
//int AddFunc(const int& left, const int& right)
//{
//	return left + right;
//}





// 函数
int AddFunc(const int& left, const int& right)
{
	return left + right;
}

// lambda 表达式
auto AddLam = [](const int& left, const int& right) { return left + right; };

// 仿函数
struct Addobject
{
	int operator()(const int& left, const int& right)
	{
		return left + right;
	}
};

template<class T>
T AddTle(const T& left, const T& right)
{
	return left + right;
}

class AddClass
{
public:
	int AddFunc(const int& left, const int& right)
	{
		return left + right;
	}
};


int main()
{
	std::function<int(int, int)> func1 = std::bind(&AddClass::AddFunc, AddClass(), std::placeholders::_1, std::placeholders::_2);
	std::cout << func1(1, 2) << std::endl;

	return 0;
}

//double my_divide(double x, double y) { return x / y; }
//
//int main()
//{
//	std::cout << my_divide(10, 1) << std::endl; // 普通调用
//
//	auto func1 = std::bind(my_divide, 20, std::placeholders::_1); // 绑定一个参数
//	std::cout << func1(10) << std::endl;
//
//	auto func2 = std::bind(my_divide, 20, 10); // 绑定两个参数
//	std::cout << func2() << std::endl;
//
//	return 0;
//}