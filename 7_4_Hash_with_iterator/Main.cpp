#include "unordered_set.h"
#include "unordered_map.h"

void test_1_set() {
	myHash::unordered_set<int> set;
	set.insert(1);
	set.insert(2);
	set.insert(3);
	set.insert(4);
	set.insert(5);
	set.insert(6);
	set.insert(7);
	set.insert(8);
	set.insert(9);
	set.insert(10);
	set.insert(11);
	set.insert(12);
	set.insert(13);
	set.insert(14);
	set.erase(1);
}

void test_1_map() {
	myHash::unordered_map<int, int> map;
	map.insert({ 1,1 });
	map.insert({ 2,1 });
	map.insert({ 3,1 });
	map.insert({ 4,1 });
	map.insert({ 5,1 });
	map.insert({ 6,1 });
	map.insert({ 7,1 });
	map.insert({ 8,1 });
	map.insert({ 9,1 });
	map.insert({ 10,1 });
	map.insert({ 11,1 });
	map.insert({ 12,1 });
}


int main() {
	test_1_set();
	test_1_map();
	return 0;
}