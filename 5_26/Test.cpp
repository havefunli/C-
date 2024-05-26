#include "List.h"

void test_1() {
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);

	auto it = lt.begin();
	*it += 1;
	
	for (auto e : lt) {
		cout << e << " ";
	}
	cout << endl;
}


int main() {
	test_1();
	return 0;
}