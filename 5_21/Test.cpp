#include "vector.h"

// 扩容会导致迭代器失效
void test_1() {
	vector<int> v = { 1 };
	vector<int>::iterator it = v.begin();
	cout << *it << endl;

	v.resize(100, 0);
	cout << *it << endl;
}

// 迭代器失效
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
	//my_Vector::vector<int> v;
	//cout << v.size() << endl;

	vector<string> v;
	string s = "ABCD";
	v.push_back(s);
	cout << v[0] << endl;

	s[0] = 'F';
	cout << v[0] << endl;

	v[0][0] = 'F';
	cout << v[0] << endl;
}

void test_5() {
	my_Vector::vector<int> v;
	v.insert(v.begin(), 1);
	v.Print();
}

int main() {
	// test_1();
	// test_2();
	// test_3();
	// test_4();
	test_5();

	return -1;
}
