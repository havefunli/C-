#include <iostream>
using namespace std;

void test_1() {
	const int A = 1;
	const int* ptr = &A;
	cout << *ptr << endl;

	// ���ʽ�������ʱ����
	const int& C = 2 * A;

	// ��ʱ������ָ�������
	// �����ڵײ��϶���Ҫ���ռ�
	int a = 0;
	int& b = a; // ���﷨�ϲ���Ҫ���ռ�
	int* p = &a;// ���﷨����Ҫ���ռ�

	// ����++�ĺ��岻ͬ��ǰ����һ����ַ�Ĵ�С����һ����ֵ��һ
	int* ptr1 = &a;
	int& r = *ptr1;

	cout << sizeof(int*) << endl;
	// �ý��ȡ����Ӧ�����͵Ĵ�С
	cout << sizeof(r) << endl;
}

void test_2() {
	// inlineֻ��һ�����飬����᲻��������ȡ���ڱ�����
	// �������������岻֧�ַ���
	// ������ʹ��һ�㶼�ǱȽϼ�̵ĺ���
}

void test_3() {

}


int main() {
	// ����
	test_1();
	// ��������
	test_2();
	// ��Ͷ���
	test_3();

	return -1;
}