#include "BST.h"
#include "AVL.h"

void test_1() {
	BST tree;
	tree.push(1);
	tree.push(2);
	tree.push(3);
}

void test_2() {
	BST bst;
	bst.read_file();
	bst.in_order();
}

void test_3() {
	BST bst;
	bst.push(2);
	bst.push(3);
	bst.push(4);
}

void test_4() {
	BST bst;
	bst.push(1);
}

int main() {
	int choice = 1;
	do {
		Main_menu();

		cin >> choice;

		system("cls");

		switch (choice) {
			case 1:
				Build_BST();
				break;
			case 2:
				Build_AVL();
				break;
		}
	} while (choice);

	return -1;
}