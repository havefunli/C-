#include "Hash.h"

void test_1() {
	myHash::HashTable<int, int> map;
	map.Insert({ 1, 2 });
	map.Insert({ 1, 3 });
	map.Insert({ 2, 2 });
	map.Insert({ 3, 2 });
	map.Insert({ 4, 2 });
	map.Insert({ 5, 2 });
	map.Insert({ 6, 2 });
	map.Insert({ 7, 2 });

	map.Erase(1);
}

void test_2() {
	myHash::HashTable<string, int> map;
	map.Insert({ "abcd", 2});
	map.Insert({ "acde", 3});
}

void test_3() {
	myHash::HashBucket<string, int> map;

}

int main() {
	// test_1();
	// test_2();
	test_3();
	return 0;
}