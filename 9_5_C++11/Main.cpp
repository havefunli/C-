//#include <iostream>
//#include <memory>
//
//// ���� auto_ptr
//// ��ֵ����������󣬱�����ᱻ���գ�������ת�ƹ���Ȩ��
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
//// ���� unique_ptr
//void Func_2()
//{
//	std::unique_ptr<int> sp(new int);
//	int* ptr = sp.get();
//}
//
//// ���� shared_ptr
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


#include "SharedPtr.hpp"

int main()
{
	MyPtr::SharedPtr<int> sp1(new int(0));
	MyPtr::SharedPtr<int> sp2(new int(0));
	
	sp1 = sp2;

	std::cout << sp1.use_count() << std::endl;

	return 0;}