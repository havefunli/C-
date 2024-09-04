#include <iostream>
#include <vector>
using namespace std;

struct A {
	// explicit �ؼ��ʻ���ֹ��ʽ����ת��
	A(int a, int b)
		: _a(a)
		, _b(b)
	{}
	
	int _a;
	int _b;
};

// �б��ʼ��
// ֧�ֵ������������
// һ�нԿ����б��ʼ��
void test_1() {
	vector<int> arr{ 1, 2, 3 };

	A a1 = { 1, 2 };
}

// auto �ؼ���
// �Զ��Ƶ�����
// typeid ��ȡ��������
void test_2() {
	vector<int> arr{ 1, 2, 3 };
	auto it = arr.begin();

	cout << typeid(it).name() << endl;

	decltype(it) it1 = arr.begin();
}

// ��Χ for
// ʹ�õ��ǿ���������Ҫ��������
void test_3() {
	vector<int> arr{ 1, 2, 3 };

	for (auto& e : arr) {
		cout << e << " ";
	}
	cout << endl;
}

// ��ֵ����ֵ�Ķ���
// ��ֵ������ȡ��ַ�ı��ʽ
// ��ֵ��������ȡֵ�ı��ʽ
void test_4() {
	int A = 1;
	string str("abcd");
	// ��ֵ����
	int& ref1 = A;
	string& ref2 = str;
	// ��ֵ����
	int&& ref3 = 1;
	string&& ref4 = "abcd";
	// ��ֵ���ò�����ֱ�ӽ�����ֵ�����Ǽ��� const ����
	const string& ref5 = "abcd";
	// ��ֵ���ò�����ֱ�ӽ�����ֵ�����Ǽ��� move ����
	string&& ref6 = move(str);
}

int main() {
	// test_1();
	// test_2();
	// test_3();
	test_4();
	return 0;
}