#include <iostream>
using namespace std;

void test_1() {
	int A = 1;
	int B = 2;

	auto Swap1 = [](int& left, int& right)
		{
			int temp = left;
			left = right;
			right = temp;
		};

	Swap1(A, B);

	// ��׽����(Ĭ�ϴ�ֵ��׽)
	// mutable �����޸Ĵ�ֵ����
	auto Swap2 = [&A, &B]() mutable
		{
			int temp = A;
			A = B;
			B = temp;
		};
	Swap2();
}

void test_2() {
	int A = 1;
	int B = 2;
	int C = 3;

	// ��ֵ��׽���еı���
	auto Func1 = [=]()->int 
		{
			return A + B + C;
		};

	cout << Func1() << endl;

	// �����ò�׽���еı���
	auto Func2 = [&]()->int
		{
			return A + B + C;
		};

	cout << Func2() << endl;

	// ��ֵ�������û�ϲ�׽���еı���
	auto Func3 = [&, B]()->int
		{
			return A + B + C;
		};

	cout << Func3() << endl;
}

// û��ʵ���������������죬��ֵ���ص�����һ��
// �ͻ�����һ��Ĭ�ϵ��ƶ�����
// ���������������ֽڿ������Զ������͵��ÿ�������

// �Բ��뱻���õĺ���
// ����˽�л�
// Ҳ���Լ��� delete ��ʾɾ��
class A {
public:
	A(const int& a) = delete;
private:
	int _a = 1;
};

template<class ...Args>
void Printf(Args... args) {
	cout << sizeof...(args) << endl;
}

void test_3() {
	Printf("abcd", 2);
}

int main() {
	// test_1();
	// test_2();
	test_3();
	return 0;
}