#include <iostream>
using namespace std;

// 基类和派生类的静态成员变量是同一个

// 多继承很合理
// 但是多继承会带来一个菱形继承的问题
// 1.数据冗余 2.数据二义性
// 解决方案：虚继承(virtual)

// 多态: 不同的对象去做同一件事情，会展现多种形态

// 多态条件：
// 1.父子类完成虚函数的重写(函数名，参数，返回值)
// 2.父类的指针或者引用调用虚函数

// 虚函数重写的例外：
// 1. 协变：返回值可以不同(但必须是返回基类或者是派生类的指针或者是引用)
// 2. 析构函数的重写

// final 修饰的类叫做最终类，不可以被继承
// override 检查是否完成重写，如果没有的话会报错
 
// 虚函数表指针，简称虚表指针(只要包含虚函数   就有)

//class Man {
//public:
//	Man() {
//		A++;
//	}
//
//	virtual void Print_A() {
//		cout << "Man::" << A << endl;
//	}
//
//	virtual ~Man() {
//		cout << "~Man()" << endl;
//	}
//
//protected:
//	static int A;
//	bool male = false;
//	int _age = 0;
//};
//int Man::A = 1;
//
//class Student : public Man{
//public:
//	Student() {}
//
//	void Print_A() {
//		cout << "Student::" << A << endl;
//	}
//
//	virtual ~Student() {
//		cout << "~Student()" << endl;
//	}
//
//private:
//	int _id = 0;
//	int score = 0;
//};
//
//void Print(Man& M) {
//	M.Print_A();
//}
//
//void test_1() {
//	Student s1;
//	Print(s1);
//
//	Man m1 = s1;
//	Print(m1);
//}
//
//// 多态
//// 建议将虚函数定义为虚函数，防止发生内存泄漏
//void test_2() {
//	Man m1;
//	Student s1;
//
//	Man* p1 = new Man;
//	Man* p2 = new Student;
//
//	delete p1;
//	delete p2; // 只调用了父类的析构函数，没有调用子类的析构
//}
//
//
//void test_3() {
//}
//
////int main() {
////	// test_1();
////	// test_2();
////	test_3();
////	return -1;
////}]
//
//
//
//class A{
//public:
//  A() 
//	  :m_iVal(0) 
//  { test(); }
//
//  virtual void func(){ 
//	  std::cout << m_iVal << " ";
//  }
//
//  void test() { 
//	  func(); 
//  }
//
//public:
//  int m_iVal;
//};
//
//
//
//class B : public A{
//public:
//	B() {
//		test(); 
//	}
//
//	virtual void func(){
//		++m_iVal;
//		std::cout << m_iVal << " ";
//	}
//};

// 植物
class Plant {
public:
	Plant(string color = "GREEN") {
		_color = color;
		cout << "Plant()" << endl;
	}

	~Plant() {
		cout << "~Plant()" << endl;
	}

	string _color; // 颜色
};

// 水果
class Fruit : virtual public Plant {
public:
	Fruit(string color = "RED", int price = 0)
		:Plant(color)
	{
		_price = price;
		cout << "Fruit()" << endl;
	}

	~Fruit() {
		cout << "~Fruit()" << endl;
	}

private:
	int _price; // 价格
};

// 蔬菜
class Vegetable : public Plant {
public:
	Vegetable(int weight = 0) {
		_weight = weight;
	}

private:
	int _weight; // 重量
};

class Tomato : public Fruit, public Vegetable{
public:
	Tomato() {}

private:
	int _size;
};

void test_1() {
	Fruit f;
	Vegetable v;
}

class A {
private:
	int _a = 0;
};

class B : virtual public A{
private:
	int _b = 1;
};

class C : virtual public A {
private:
	int _c = 2;
};

class D : public B, public C {
private:
	int _d = 4;
};

void test_2() {
	B b;
	C c;
	D d;
}

//int main(){
//	// test_1();
//	test_2();
//
//	return 0;
//}

#include <iostream>
#include <vector>
using namespace std;

void sort(vector<int>& arr, int first, int last) {
    if (first >= last) return; // 当区间只有一个元素或者为空，结束递归

    int left = first;
    int right = last;
    int pivot = arr[left]; // 选择第一个元素作为基准

    while (left < right) {
        // 从右向左找到第一个小于等于基准的元素
        while (left < right && arr[right] > pivot) {
            right--;
        }
        if (left < right) {
            arr[left] = arr[right];
            left++;
        }

        // 从左向右找到第一个大于基准的元素
        while (left < right && arr[left] <= pivot) {
            left++;
        }
        if (left < right) {
            arr[right] = arr[left];
            right--;
        }
    }

    // 将基准放到正确的位置
    arr[left] = pivot;

    // 分别对左右子数组进行排序
    sort(arr, first, left - 1);
    sort(arr, left + 1, last);
}


int main() {
    int n = 0;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, 0, arr.size() - 1);

    for (auto e : arr) {
        cout << e << " ";
    }
    cout << endl;


    return 0;
}