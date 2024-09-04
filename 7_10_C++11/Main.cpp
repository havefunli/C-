#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void test_1() {
	auto func1 = [](int A, int B) ->int { return A + B; };
	func1(1, 2);

	double A = 1.5, B = 2.5, C = 3;
	auto func2 = [A, B] () -> int
		{
			return A * B;
		};
	cout << func2() << endl;
}

template<class T>
struct Less {
	bool operator()(const T& left, const T& right) {
		left < right;
	}
};

class Man {
public:
	Man(string name, int age) {
		_name = name;
		_age = age;
	}

	string _name;
	int _age;
};

struct LessForMansAge {
	bool operator()(const Man& left, const Man& right) {
		return left._age < right._age;
	}
};

void test_2() {
	vector<Man> v;
	v.emplace_back("L", 10);
	v.emplace_back("M", 11);
	v.emplace_back("N", 12);

	auto Less = [](const Man& left, const Man& right) { return left._age < right._age; };
	sort(v.begin(), v.end(), Less);
}

void test_3() {
	vector<int> v = { 1, 2, 3, 4, 5, 6 };
	for_each(v.begin(), v.end(), [](int& x) { x *= 2; });
	for_each(v.begin(), v.end(), [](int& x) { cout << x << endl; });
}

int main() {
	// test_1();
	// test_2();
	test_3();
	return 0;
}