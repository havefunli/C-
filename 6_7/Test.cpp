#include <iostream>
using namespace std;

// �����������ľ�̬��Ա������ͬһ��

// ��̳кܺ���
// ���Ƕ�̳л����һ�����μ̳е�����
// 1.�������� 2.���ݶ�����
// �����������̳�(virtual)

// ��̬
// ��ͬ�Ķ���ȥ��ͬһ�����飬��չ�ֶ�����̬
// 1.����������麯������д(������������������ֵ)
// 2.�����ָ��������õ����麯��

class Man {
public:
	Man() {
		A++;
	}

	void Print_A() {
		cout << A << endl;
	}

private:
	static int A;
	bool male = false;
	int _age = 0;
};
int Man::A = 1;

class Student {
public:
	Student() {}

private:
	int _id = 0;
	int score = 0;
};

class Base1 {
public: 
	int _b1 = 1; 
};

class Base2 {
public:
	int _b2 = 2; 
};

class Derive : public Base1, public Base2{
public: int _d = 3;
};

int main() {
	Derive D;
	return 0;
}