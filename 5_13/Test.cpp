#include <iostream>
using namespace std;

// ������������������ڱ���
// �����������ʱ���󶼾��г���

class A {
public:
	A(int a = 1) {
		cout << "A()" << endl;
		_a = 1;
	}

	~A() {
		cout << "~A()" << endl;
	}

private:
	int _a;
};

//int main() {
//	// A(1);
//	// A(2);
//}

// malloc�����ʼ����calloc���ʼ��
// �ڶ��Ͽ��ٵĿռ䣬��Ҫָ���ͷ�
// delete -> ���ȵ���������������operator delete

int main() {
	// ��������
	int* p1 = new int(1);
	int* p2 = new int[5] {1, 2, 3, 4, 5};
	delete p1;
	delete[] p2;

	A* p3 = new A(3);
	delete[] p3; 
}
