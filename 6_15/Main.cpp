#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>
#include <random>
using namespace std;

#define MAX 10000000

void sort_10w_nums() {
	mt19937 gen(12345);
	uniform_int_distribution<> dis(1, MAX);
	vector<int> nums(MAX);

	for (int i = 0; i < MAX; i++) {
		nums.push_back(dis(gen));
	}

	sort(nums.begin(), nums.end());
}


int main() {
	clock_t start = clock();
	sort_10w_nums();
	clock_t end = clock();
	cout << (double)(end - start) / CLOCKS_PER_SEC << endl;

	return 0;
}