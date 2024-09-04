#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

void test_1() {
	// s ÊÇ×óÖµ
	string&& s1 = string("abcd");
	cout << &s1 << endl;

	const int n = 1;
	const int& A = n;
	cout << &n << endl;
	cout << A << endl;
}

struct Vegetable{

	Vegetable(string name, int prize, int weight) 
		: _name(name)
		, _prize(prize)
		, _weight(weight)
	{}

	string _name;
	int _prize;
	int _weight;
};

void test_2() {
	Vegetable tomato("tomato", 12, 23);
	Vegetable potato("potato", 10, 35);
	Vegetable apple("apple", 34, 30);

	auto Func = [](const Vegetable& left, const Vegetable& right)
		{
			return left._prize > right._prize;
		};

	vector<Vegetable> arrVegetable = { tomato, potato, apple };
	sort(arrVegetable.begin(), arrVegetable.end(), Func);
}

int main() {
	 // test_1();
	test_2();
	return 0;;
}