#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void test_1() {
	vector<int> v = { 1, 3, 4, 5, 1, 4, 9 };
	for (auto e : v) {
		cout << e << " ";
	}
	cout << endl;

	// Ĭ�������򣬼���greater����
	sort(v.begin(), v.end(), greater<int>());
	for (auto e : v) {
		cout << e << " ";
	}
	cout << endl;
}

int main() {
	test_1();
	return -1;
}