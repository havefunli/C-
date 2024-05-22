#include "vector.h"

// ���ݻᵼ�µ�����ʧЧ
void test_1() {
	vector<int> v = { 1 };
	vector<int>::iterator it = v.begin();
	cout << *it << endl;

	v.resize(100, 0);
	cout << *it << endl;
}

// ������ʧЧ
void test_2() {
	vector<int> v = {1, 2, 3, 4, 5};
	
	auto it = v.begin();
	v.erase(it);
	cout << *it << endl;
}

void test_3() {
	vector<int> v = { 2, 3, 4, 5 };
	auto it = v.begin();

	while (it != v.end()) {
		if (*it % 2  == 0) {
			it = v.erase(it);
		}
		else {
			it += 1;
		}
	}

	for (auto e : v) {
		cout << e << " ";
	}
	cout << endl;

	cout << int() << endl;
}

void test_4() {
	my_Vector::vector<int> v;
	cout << v.size() << endl;

	//vector<string> v;
	//string s = "ABCD";
	//v.push_back(s);
	//cout << v[0] << endl;

	//s[0] = 'F';
	//cout << v[0] << endl;

	//v[0][0] = 'F';
	//cout << v[0] << endl;
}

void test_5() {
	my_Vector::vector<int> v;
	v.insert(v.begin(), 1);
	v.Print();

	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.Print();
}

void test_6() {
	my_Vector::vector<int> v;
	v.insert(v.begin(), 1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.Print();

	auto it = v.erase(v.begin());
	cout << *it << endl;

	v.pop_back();
	v.Print();
}

void test_7() {
	my_Vector::vector<int> v1{ 1, 2, 3, 4, 5 };
	v1.Print();

	my_Vector::vector<int> v2(10, 1);
	v2.Print();
}

void test_8() {
	my_Vector::vector<int> v1 = { 1, 2, 3, 4, };
	v1.Print();

	my_Vector::vector<int> v2 = v1;
	v2.Print();
}

void test_9() {
	my_Vector::vector<int> v1 = { 1, 2, 3 };
	my_Vector::vector<int> v2 = v1;
	v2.Print();

	v2 = v1;
	v2.Print();
}

int main() {
	// test_1();
	// test_2();
	// test_3();
	// test_4();
	// test_5();
	// test_6();
	// test_7();
	// test_8();
	test_9();

	return 0;
}
