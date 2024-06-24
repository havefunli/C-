#include "AVL.h"

void test_1() {
	myAVL::AVL<int, int> map;
	map.insert({ 3, 1 });
	map.insert({ 2, 1 });
	map.insert({ 1, 1 });
}

int main() {
	test_1();
	return 0;
}