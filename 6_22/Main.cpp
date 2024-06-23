#include "Map.h"

void test_1() {
	myMap::Map<int, int> map;
	map.insert({ 1, 0 });
	map.insert({ 2, 0 });
	map.insert({ 3, 0 });
	
	map.inOrder();

	auto ret = map.insert({ 1, 1 });
	cout << ret.second << endl;
}

void test_2() {
	myMap::Map<int, string> map;
	map.insert({ 1, "one" });
	map.insert({ 2, "two" });
	map.insert({ 3, "three"});

	map.inOrder();

	auto ret1 = map.find(1);
	if (ret1 != nullptr) cout << ret1->_kv.second << endl;
	else cout << "The Node is nullptr !!!" << endl;
		 
	auto ret2 = map.find(4);
	if (ret2 != nullptr) cout << ret2->_kv.second << endl;
	else cout << "The Node is nullptr !!!" << endl;
}

void test_3() {
	myMap::Map<int, string> map;
	map.insert({ 1, "one" });
	map.insert({ 2, "two" });
	map.insert({ 3, "three" });

	map[1] = "1";
	map[4] = "four";
	map.inOrder();
}

void test_4() {
	map<string, int> map;
	map["one"] = 1;
	map["two"];

	for (auto e : map) {
		cout << e.first << " " << e.second << endl;
	}
}

void test_5() {
	myMap::Map<int, string> map;
	map.insert({ 1, "one" });
	map.insert({ 2, "two" });
	map.insert({ 3, "three" });

	map.erase(1);
	map.inOrder();
}

void test_6() {
	myMap::Map<string, string> map;
	
	map["你好"] = "hello";
	map["苹果"] = "apple";
	map["土豆"] = "tomato";
	map["小猪"] = "pig";

	while (1) {
		string chinese;
		cin >> chinese;

		cout << map[chinese] << endl;
	}
}

int main() {
	// test_1();
	// test_2();
	// test_3();
	// test_4();
	// test_5();
	test_6();
	return -1;
}