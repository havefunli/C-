#include "List.h"
using namespace my_list;
//
//// ģ�壺
//// ֻ֧��������Ϊ������ģ�����
//// ֧��ȱʡ����
//// ģ�����У��������ᰴ��ʵ����
//
//// ģ����ػ�������������ͽ������⴦��
//
////// ȫ�ػ���
////template<>
////class Data<int, char> {
////public:
////	Data() {
////		cout << "Data<int, char>" << endl;
////	}
////};
////
////// ƫ�ػ�
////template<class T>
////class Data<T, char> {
////public:
////	Data() {
////		cout << "Data<T, char>" << endl;
////	}
////};
//
//template<class T>
//class Less {
//public:
//	bool operator()(const T& left, const T& right) {
//		return left < right;
//	}
//};
//
//// ��ָ�������ػ�
//template<class T>
//class Less<T*> {
//public:
//	bool operator()(const T* left, const T* right) {
//		return *left < *right;
//	}
//};
//
//void test_1() {
//	int A = 1;
//	int B = 2;
//	int* p1 = &A;
//	int* p2 = &B;
//
//	cout << Less<int>()(A, B) << endl;
//	cout << Less<int*>()(p1, p2) << endl;
//}
//
//namespace my_list{
//	template<class T>
//	void Test<T>::Print1() {
//		cout << val << endl;
//	}
//}
//
//void test_2() {
//	Test<int> t;
//	t.Print1();
//}
//
//class A {
//public:
//	A(int a = 1) {
//		_a = a;
//	}
//private:
//	int _a;
//};
//
//void test_3() {
//	my_list::list<int> lt;
//	lt.push_back(1);
//	lt.push_back(2);
//	lt.push_back(3);
//	lt.push_back(4);
//	lt.push_back(5);
//
//	my_list::list<int>::reverse_iterator rit = lt.rbegin();
//	cout << *rit << endl;
//}
//
//// for int
//void swap(int& left, int& right) {
//	int temp = left;
//	left = right;
//	right = temp;
//}
//// for char
//void swap(char& left, char& right) {
//	int temp = left;
//	left = right;
//	right = temp;
//}

template<class T1, class T2>
void test(T1 left = int(), T2 right = int()) {
	cout << left << endl;
	cout << left << endl;
}

int main() {
	// test_1();
	// test_2();
	// test_3();
	test(1, 2.1);
	return 1;
}