#include <iostream>
#include"Date.h"
using namespace std;



int main(){
	//Date D1(2024, 5, 1);
	//Date D2(2025, 1, 1);

	//int day = D2 - D1;
	//cout << day << endl;

	//return 1;
	
	Date* p1 = new Date[10];
	delete[] p1;

	return 0;
}