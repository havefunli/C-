#include <stdio.h>
#include <cstring>

#include <memory>
#include <algorithm>
#include <thread>
#include <vector>
#include <string>
#include <iostream>

void Func(const std::string name)
{
	int num = 0;
	std::cout << "Please Enter# ";
	std::cin >> num;

	std::cout << name << " " << num << std::endl;
} 

bool Greater(const int& left, const int& right)
{
	return left > right;
}

class GreaterClass
{
public:
	bool operator()(const int& left, const int& right)
	{
		return left > right;
	}
};

class Test
{
public:
	Test(int A)
		: _A(A)
	{}

	int _A;
};


int main()
{
	std::shared_ptr<int> Ptr;
	return 0;
} 