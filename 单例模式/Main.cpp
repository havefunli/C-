// ����������
// ��Ҫ�漰������ģʽ
// ���в�������������

#include <iostream>
#include <string>
#include <memory>
#include <mutex>

// ֻ���ڶ��Ͽ��ٿռ�
class HeapOnly
{
private:
	HeapOnly(std::string str = nullptr)
		: _str(str)
	{}

public:
	HeapOnly(const HeapOnly&) = delete;
	HeapOnly& operator=(const HeapOnly&) = delete;

	static HeapOnly* ObjCreate(std::string str = nullptr)
	{
		return new HeapOnly(str);
	}

private:
	std::string _str;
};


void Test_1() 
{
	// HeapOnly obj;
	std::shared_ptr<HeapOnly> sp(HeapOnly::ObjCreate("123"));
}

// -------------------------------

// �ص�
// ����ģʽ

// ����ģʽ
// �ڳ�������ǰ�ʹ����ö���
// �ŵ�ʵ�ּ�
// ȱ�㾲̬��Ա��������������
// 
//class SingLeton
//{
//private:
//	SingLeton(const int& A = 0)
//		: _A(A)
//	{
//		std::cout << "&_A = " << &_A << std::endl;
//	}
//
//	SingLeton(const SingLeton&) = delete;
//	SingLeton& operator=(const SingLeton&) = delete;
//
//public:
//	static SingLeton& GetInstance()
//	{
//		return _Barchelor;
//	}
//
//	void Func()
//	{
//		std::cout << "&_A = " << &_A << std::endl;
//	}
//
//private:
//	int _A = 1;
//	static SingLeton _Barchelor;
//};
//
//SingLeton SingLeton::_Barchelor;

// ����ģʽ
// �ڳ��������󴴽��ö���
// ��Ҫע����������
std::mutex mtx;
class SingLeton
{
private:
	SingLeton(const int& A = 0)
		: _A(A)
	{
		std::cout << "&_A = " << &_A << std::endl;
	}

	SingLeton(const SingLeton&) = delete;
	SingLeton& operator=(const SingLeton&) = delete;

public:
	static SingLeton* GetInstance()
	{
		if (_Barchelor == nullptr)
		{
			std::lock_guard<std::mutex> lck(mtx);
			if (_Barchelor == nullptr)
			{
				_Barchelor = new SingLeton(1);
			}
		}

		return _Barchelor;
	}

	void Func()
	{
		std::cout << "&_A = " << &_A << std::endl;
	}

private:
	int _A = 1;
	static SingLeton* _Barchelor;
};

SingLeton* SingLeton::_Barchelor = nullptr;



void Test_2()
{
	SingLeton* obj1 = SingLeton::GetInstance();
	obj1->Func();

	SingLeton* obj2 = SingLeton::GetInstance();
	obj2->Func();
}


int main()
{
	// Test_1();
	Test_2();
	return 0;
}