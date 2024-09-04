#include <iostream>
using namespace std;
 
// 封装
// 数据和方法放到一起，把想要给用户访问的放到公共区域，不想给用户访问的放到私有区域或保护
// 一个类型放到另一个类型里面，通过typedef成员函数调整，封装另一个全新的类型

// 继承
// 子类的访问方式 = Min(继承方式, 父类中的访问方式)

class Man {
public:
	Man() {}

	void Print() {
		cout << _age << " " << _height << " " << _weight << endl;
	}

private:
	int _age = 0;
	int _height = 0;
	int _weight = 0;
};

void test_1() {
	Man lq;
	lq.Print();
}

int main() {
	test_1();
	return 0;
}
