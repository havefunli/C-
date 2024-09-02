#include "RedBlackTree.h"

//int main() {
//	myRBTree::RBTree<int, int> map;
//	map.insert({ 1,2 });
//	map.insert({ 2,2 });
//	map.insert({ 3,2 });
//	map.insert({ 4,2 });
//	map.insert({ 5,2 });
//	return 0;
//}

template<class T>
bool Less(const T& left, const T& right) {
	return left < right;
}

template<class T, class K>
bool Less(const T& left, const K& right) {
	return left.first < right;
}

#include <set>

struct A{
	A() 
		: pair(1, 1)
	{}
	pair<int, int> pair;
};

struct Node {
	pair<int, int>* operator->() {
		return &(ptr->pair);
	}

	A* ptr = new A;
};

int main() {
	Node ptr;
	cout << ptr->first << endl;

	return 0;
}