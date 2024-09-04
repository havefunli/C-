#include "L_M_S.h"
using namespace std;
using namespace mySpace;

int main() {
	read_File();

	int chioce = 0;
	do {
		Main_menu();
		cin >> chioce;
		system("cls");

		switch (chioce) {
		case 0:
			Library_management();
			break;
		case 1:
			Book_query();
			break;
		case 2:
			Book_sort();
			break;
		case 3:
			view_all_book();
			break;
		}
	} while (chioce != 4);
	save_File();

	return 1;
}
