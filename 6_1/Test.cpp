#include <iostream>
using namespace std;
 
// ��װ
// ���ݺͷ����ŵ�һ�𣬰���Ҫ���û����ʵķŵ��������򣬲�����û����ʵķŵ�˽������򱣻�
// һ�����ͷŵ���һ���������棬ͨ��typedef��Ա������������װ��һ��ȫ�µ�����

// �̳�
// ����ķ��ʷ�ʽ = Min(�̳з�ʽ, �����еķ��ʷ�ʽ)

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
