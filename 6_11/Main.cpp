//#include <iostream>
//using namespace std;

// 虚表中存储的是虚函数的地址而不是虚函数
// 虚函数存在于常量区
// 子类有虚函数，继承的父类有虚函数就有虚表，子类对象中就不需要单独建立虚表


//class A {
//public:
//	virtual void Func1() {
//		cout << "A_Func()" << endl;
//	}
//
//	int _a = 0;
//};
//
//class B : public A{
//public:
//	virtual void Func1() {
//		cout << "B_Func()" << endl;
//	}
//
//	virtual void Func2() {
//		cout << "B_Func2()" << endl;
//	}
//
//	int _b = 1;
//};
//void test_1(){
//	A a;
//	B b;
//	A* p1= new B;
//	cout << sizeof(B) << endl;
//}

//int main() {
//	test_1();
//
//	return 0;
//}

#include <iostream>
#include <vector>
using namespace std;

int sort_k(vector<int>& arr, int first, int end, int k) {
    if (first == end) return arr[first];

    int i = first;
    int j = end - 1;
    int pivot = arr[i];

    while (i < j) {
        while (i < j && arr[i] <= pivot) {
            i++;
        }
        while (i < j && arr[j] > pivot) {
            j--;
        }
        if (i < j) swap(arr[i], arr[j]);
    }

    int num = i - first + 1;
    if (num >= k) return sort_k(arr, first, i, k);
    else return sort_k(arr, i + 1, end, k - num);
}

int main() {
    int n, k;
    cin >> n >> k;


    int num = 0;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << sort_k(arr, 0, n, k) << endl;

    return 0;
}