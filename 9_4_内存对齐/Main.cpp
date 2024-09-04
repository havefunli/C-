// 学习内存对齐
// 本质是利用空间换取时间 ！！！
//#pragma pack(4)
//
#include <iostream>

//struct ForTest
//{
	//ForTest()
	//{
	//	_A = 1;
	//	_B = 'A';
	//	_C = 2;
	//}


	//int _A;
	//char _B;
	//int _C;
//};

enum DAY {
	MON = 1, TUE, WED, THU, FRI, SAT, SUN
};
//struct stu1 {
//	char a[5];
//	char b[3];
//	enum DAY day;
//	int* c;
//	short d;
//	int e;
//};

//struct stu1
//{
//	char a;
//	int b;
//};
//
//struct stu2
//{
//	char a;
//	long long b;
//};
//
//class MyObject
//{
//public:
//
//	virtual void PrintAge() = 0;
//
//	int _age;
//};
//
//class Father : public MyObject
//{
//public:
//	Father()
//	{
//		_age = 60;
//	}
//
//	void PrintAge()
//	{
//		std::cout << "I am father, my age is " << _age << std::endl;
//	}
//
//};
//
//class Son : public MyObject
//{
//public:
//	Son()
//	{
//		_age = 40;
//	}
//
//	void PrintAge()
//	{
//		std::cout << "I am Son, my age is " << _age << std::endl;
//	}
//
//};
//
//int main()
//{
//	Father li;
//	Son quan;
//
//	return 0;
//}


//struct stu2 {
//	char x;
//	int y;
//	double z;
//	char v[6];
//};
//struct stu1 {
//	char a;
//	struct stu2 b;
//	int c;
//};
 
#pragma pack(8)

struct stu2
{
	int* ptr; // 4
	char ch; // 1
};

struct stu1
{
	char a;
	virtual void Print() {}
};



int main()
{
	std::cout << sizeof(stu1) << std::endl;
	return 0;
}