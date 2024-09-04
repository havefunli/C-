#include <iostream>
using namespace std;

// ��ʼ���б�
// ��ʼ���б���Գ�ʼ��û��Ĭ�Ϲ�����Զ�����
// ��ʼ���б���Գ�ʼ�� const/���� ������Ϊ const/���� ����ֻ���ڶ���ʱ��ʼ��

class A {
public:
	A(const int a) {
		_a = a;
		_counts += 1;
	}

	static void Print_counts() {
		cout << _counts << endl;
	}

private:
	int _a;

	// �ھ�̬���������ڶ���
	static int _counts;
};

// ����
int A::_counts = 0;

class B {
public:
	B(const int b) {
		int _b = 1;
	}

private:
	int _b;
};

class C {
public:
	C(const int a = 1, const int b = 1)
		:_a(a)
		,_b(b)
	{}

private:
	A _a;
	B _b;
	int _c = 1; // ȱʡֵ������ʼ���б�ʹ��
};

void Fun() {
	A test(1);
}

// ��Ա�����ĳ�ʼ��˳���Ǳ���������˳��
// �����Ǳ����ڳ�ʼ���б��ǰ��˳��
int main(){
	A a_1(1);
	A a_2(2);
	A a_3(3);
	Fun();

	A::Print_counts();
}