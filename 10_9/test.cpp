#include <iostream>
#include <vector>


void Test1() {
	int arr_cookies[3] = {1, 2, 3};
	int arr_kids[] = {1, 2};
	std::vector<int> kids(arr_kids, arr_kids + sizeof(arr_kids)/sizeof(int));
	std::vector<int> cookies(arr_cookies, arr_cookies + sizeof(arr_cookies) / sizeof(int));

	while()
}


int main() {
	Test1();

	return -1;
}