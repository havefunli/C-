// 学习 C++11 新特性
#include <iostream>
#include <vector>

// Args 是一个模板参数包，args 是一个形参参数包

void _Print()
{
	std::cout << std::endl;
}

template <class T, class ...Args>
void _Print(const T& val, Args... arg)
{
	std::cout << val << std::endl;
	_Print(arg...);
}

template <class ...Args>
void Print(Args... arg)
{
	_Print(arg...);
}

template <class T>
int PrintArg(const T& val)
{
	std::cout << val << " ";
	return 0;
}

template <class ...Args>
void EasyPrint(Args... args)
{
	// args... 有几个值，函数就调用几次，调用几次就有几个返回值，arr 就开多大
	int arr[] = { PrintArg(args)... };
	std::cout << std::endl;
}

// 可变参数
void func_1()
{
	// 方案一
	// Print(1, 2, 'c');
	// 方案二
	EasyPrint(1, 2, 3, 'A');
}

// emplace_back 构造
void func_2()
{
	std::pair<int, int> pair;
}

class Test
{
public:
	Test(const int &A, const int &B)
	{
		_A = A;
		_B = B;
	}

private:
	int _A;
	int _B;
};

int main()
{
	// func_1();
	// func_2();
	
	std::pair<Test, int> pair(Test(1, 2), 3);

	// std::vector<Test> vec;
	// vec.emplace_back(1, 2);

	std::vector<std::pair<Test, int>> vec;
	vec.emplace_back(Test(1, 2), 3);

	return 0;
}