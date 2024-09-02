#include "AVL.h"

void test_1() {
	myAVL::AVL<int, int> map;
	map.insert({ 11, 1 });
	map.insert({ 7, 1 });
	map.insert({ 17, 1 });
	map.insert({ 5, 1 });
	map.insert({ 9, 1 });
	map.insert({ 14, 1 });
	map.insert({ 19, 1 });
	map.insert({ 8, 1 });
	map.insert({ 12, 1 });
	map.insert({ 18, 1 });
	map.insert({ 27, 1 });
	map.insert({ 23, 1 });

	map.erase(5);
}

int main() {
	test_1();
	return 0;
}