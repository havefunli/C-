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

void test_2_setIterator() {
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

	myHash::unordered_set<int>::iterator it = set.begin();
	while (it != set.end()) {
		cout << *it << endl;
		++it;
	}
}

void test_2_mapIterator() {
	myHash::unordered_map<int, int> map;
	for (int i = 0; i < 15; i++) {
		map.insert({ i, i });
	}

	myHash::unordered_map<int, int>::iterator it = map.begin();
	while (it != map.end()) {
		cout << it->first << endl;
		++it;
	}
}

void test_3() {
	myHash::unordered_map<int, int> map;
	for (int i = 0; i < 15; i++) {
		map.insert({ i, i });
	}

	auto ret = map.insert(make_pair(1, 1 ));
	cout << ret.first->first << " " << ret.second << endl;
}

void test_4() {
	myHash::unordered_map<string, int> map;
	map["像素达到"] = 1;
	map["像素达到"]++;

	for (auto& e: map) {
		cout << e.first << " " << e.second << endl;
	}
}

int main() {
	// test_1_set();
	// test_1_map();
	// test_2_setIterator();
	// test_3();
	test_4();
	return 0;
}