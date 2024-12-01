#include <iostream>
#include <functional>


//int main()
//{
//	//const int x = 10;
//	//int* ptr = const_cast<int*>(&x); // 将 const int 指针转换为 int 指针
//	//*ptr = 20;  // 修改值
//
//	//std::cout << "x = " << x << std::endl;
//	//std::cout << "*ptr = " << *ptr << std::endl;
//	//std::cout << "ptr = " << ptr << std::endl;
//	//std::cout << "&x = " << &x << std::endl;
//
//	//uint64_t val = 1;
//	//std::cout << sizeof(val) << std::endl;
//	//std::cout << sizeof(uint64_t) << std::endl;
//
//	//return 0;
//}

class Base { virtual void func() {} };  // 必须有虚函数
class Derived : public Base {};

int main()
{	
	int A = 0;
	int* ptr1 = &A;
	char* ptr2 = reinterpret_cast<char*>(ptr1);

	
    volatile const int num = 10;
	int* ptr = const_cast<int*>(&num);
	std::cout << "Before change: num = " << num << std::endl;
	std::cout << "Before change: *ptr = " << *ptr << std::endl;
	(*ptr) += 10;
	std::cout << "After change: *ptr = " << *ptr << std::endl;
	std::cout << "Before change: num = " << num << std::endl;



	return 0;
}