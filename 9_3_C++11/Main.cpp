// C++11 ��ѧϰ
// ��װ��

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
//// ��װ����װ�ɵ��ö���
//void Func_1()
//{
//	auto LamFunc = [](const int& left, const int& right) { return left + right;  };
//
//	std::function<int(int, int)> fc1 = AddFunc;
//	std::function<int(int, int)> fc2 = AddClass();
//	std::function<int(int, int)> fc3 = LamFunc;
//}
//
//// �󶨿��Ե�������˳�����
//void Func_2()
//{
//	auto Sub = [](const int& left, const int& right) { return left - right; };
//	std::cout << Sub(2, 1) << std::endl;
//
//	// ��������˳��
//	auto ReverseSub = std::bind(Sub, std::placeholders::_2, std::placeholders::_1);
//	std::cout << ReverseSub(2, 1) << std::endl;
//
//	// ������
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
//	// ��ʼ��
//	va_start(ap, cnt);
//
//	// ����
//	for (int i = 0; i < cnt; i++)
//	{
//		// �����������е����в���
//		int num = va_arg(ap, int);
//		std::cout << num << ' ';
//	}
//	std::cout << std::endl;
//
//	// �ͷ�
//	va_end(ap);
//}
//
//
////int main()
////{
////	// ��һ����������ɱ�����ĸ���
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
//	// ��ʽһ
//	std::string s = "ABC";
//	vec.push_back(s);
//
//	// ��ʽ��
//	vec.push_back(std::string("ABC"));
//
//	// ��ʽ��
//	vec.emplace_back("ABC");
//
//	return 0;
//}

// ���������߳�
// һ���̴߳�ӡ ����
// һ���̴߳�ӡ ż��


//int main()
//{
//	bool PrintEven = true;
//	int Num = 0; // �����̹߳���ı���
//	std::mutex mtx; // ��
//	std::condition_variable cond; // ����������֤��ӡ˳��
//
//	// ��ӡż�����߳�
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
//	// ��ӡ�������߳�
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





// ����
int AddFunc(const int& left, const int& right)
{
	return left + right;
}

// lambda ���ʽ
auto AddLam = [](const int& left, const int& right) { return left + right; };

// �º���
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
//	std::cout << my_divide(10, 1) << std::endl; // ��ͨ����
//
//	auto func1 = std::bind(my_divide, 20, std::placeholders::_1); // ��һ������
//	std::cout << func1(10) << std::endl;
//
//	auto func2 = std::bind(my_divide, 20, 10); // ����������
//	std::cout << func2() << std::endl;
//
//	return 0;
//}