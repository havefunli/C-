#include "List.h"
using namespace my_list;

 //模板：
 //只支持整形作为非类型模板参数
 //支持缺省参数
 //模板类中：编译器会按需实例化

 //模板的特化，针对特殊类型进行特殊处理

// 全特化：
//template<>
//class Data<int, char> {
//public:
//	Data() {
//		cout << "Data<int, char>" << endl;
//	}
//};
//
//// 偏特化
//template<class T>
//class Data<T, char> {
//public:
//	Data() {
//		cout << "Data<T, char>" << endl;
//	}
//};

//template<class T>
//class Less {
//public:
//	bool operator()(const T& left, const T& right) {
//		return left < right;
//	}
//};
//
// // 对指针类型特化
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

class A {
public:
	A(int a = 1) {
		_a = a;
	}
private:
	int _a;
};

void test_3() {
	my_list::list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);

	my_list::list<int>::reverse_iterator rit = lt.rbegin();
	while (rit != lt.rend()) {
		cout << *rit << " ";
		rit++;
	}
	cout << endl;
}

template<class T>
class my_Greater {
public:
	bool operator()(T left, T right) {
		return *left > *right;
	}
};

void test_4() {
	int A = 5, B = 5;
	int* p1 = &A;
	int* p2 = &B;
	cout << my_Greater<int*>()(p1, p2) << endl;
}

//template<class T>
//bool Less(const T left, T right) {
//	return left < right;
//}
//
//template<>
//bool Less<int*> (int* left, int* right) {
//	return *left < *right;
//}
//
//template<class T>
//bool Greater(T base1, T base2) {
//	return base1 > base2;
//}
//
//template<>
//bool Greater<int*>(int* base1, int* base2) {
//	return *base1 > *base2;
//}

//void test_1() {
//	int A = 2, B = 1;
//	cout << Less(A, B) << endl;
//
//	double C = 1.12, D = 2.23;
//	cout << Less(C, D) << endl;
//
//	int* p1 = &A;
//	int* p2 = &B;
//	cout << Greater(p1, p2) << endl;
//}


template<class T>
class Less {
public:
	bool operator()(const T& left, const T& right) {
		return left < right;
	}
};

 // 对指针类型特化
template<class T>
class Less<T*> {
public:
	bool operator()(const T* left, const T* right) {
		return *left < *right;
	}
};

template<class T>
class my_vector {
public:
	// ...
private:
	T* _start = nullptr;
	T* _end = nullptr;
	T* _end_of_capacity = nullptr;
};

int main() {
	// test_1();
	return 0;
}