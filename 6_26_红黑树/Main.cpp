#include "RedBlackTree.h"

int main() {
	myRBTree::RBTree<int, int> map;
	map.insert({ 1,2 });
	map.insert({ 2,2 });
	map.insert({ 3,2 });
	map.insert({ 4,2 });
	map.insert({ 5,2 });
	return 0;
}