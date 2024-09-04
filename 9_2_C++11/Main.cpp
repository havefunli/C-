// ѧϰ C++11 ������
#include <iostream>
#include <vector>

// Args ��һ��ģ���������args ��һ���ββ�����

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
	// args... �м���ֵ�������͵��ü��Σ����ü��ξ��м�������ֵ��arr �Ϳ����
	int arr[] = { PrintArg(args)... };
	std::cout << std::endl;
}

// �ɱ����
void func_1()
{
	// ����һ
	// Print(1, 2, 'c');
	// ������
	EasyPrint(1, 2, 3, 'A');
}

// emplace_back ����
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