#include <iostream>
using namespace std;

// ���������������ԣ���װ �̳� ��̬
// ��װ�������ݺͷ�����װ������������ͳһ����

// thisָ�����ջ���棬��Ϊ��ҪƵ���ķ���

// ���6��Ĭ�Ϻ���
// --- ��ʼ�������� --- ���캯��
//		|		    |--- ��������
//		�������� --- ��������
//		|		 |--- ��������
//		ȡ��ַ���� --- ��ͨ����ȡ��ַ
//				   |--- const����ȡ��ַ

// �������Զ����ɵĹ��캯�������Զ������Զ������͵Ĺ��캯��
// û�й涨�Ƿ�����������

class student {
public:
	// �޲�
	//student() {
	//	_gender = 0;
	//	_age = 0;
	//	_height = 0;
	//}

	// �в�
	student(bool gender = 0, int age = 0, int height = 0) {
		_gender = gender;
		_age = age;
		_height = height;
	}

	~student(){
		cout << "Free up space!" << endl;
	}

	void init(bool gender, int age, int height) {
		_gender = gender;
		_age = age;
		_height = height;
	}

	void show_info() {
		cout << _gender << endl;
		cout << _age << endl;
		cout << _height << endl;
	}

private:
	bool _gender;
	int _age;
	int _height;
};


void test_1() {
	student lq;
	lq.init(0, 1, 1);
	lq.show_info();

	cout << "The size of class student: " << sizeof(lq) << endl;
	cout <<"The size of lq: "<< sizeof(student) << endl;
}

class Test {
public:
	void Print() {
		cout << "Print()" << endl;
	}

private:
	int _a;
};

void test_2() {
	Test* t = nullptr;
	t->Print();
}

// ���캯���ڶ������ɵ�ʱ���Զ�����
// ���������ڶ����������ڽ���ʱ�Զ������ͷſռ�
// ��������˶���student stu_1()����ͺ�����������
void test_3() {
	student stu_1;
	stu_1.show_info();

	student stu_2(1, 22, 31);
	stu_2.show_info();
}

//int main() {
//	//test_1();
//	//test_2();
//	//test_3();
//
//	return -1;
//}

int A = 2;

namespace mySpace {
	int A = 1;
}

using mySpace::A;

int main() {
	int A = 3;

	cout << A;
	return -1;
}