#define  _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

#include <vector>

using namespace std;

//int main(void)
//
//{
//
//	/*vector<int>array;
//
//	array.push_back(100);
//
//	array.push_back(300);
//
//	array.push_back(300);
//
//	array.push_back(300);
//
//	array.push_back(300);
//
//	array.push_back(500);
//
//	vector<int>::iterator itor;
//
//	for (itor = array.begin(); itor != array.end(); itor++)
//
//	{
//
//		if (*itor == 300)
//
//		{
//
//			itor = array.erase(itor);
//
//		}
//
//	}
//
//	for (itor = array.begin(); itor != array.end(); itor++)
//
//	{
//
//		cout << *itor << " ";
//
//	}
//
//	return 0;*/
//
//	//int ar[] = { 1,2,3,4,5,6,7,8,9,10 };
//
//	//int n = sizeof(ar) / sizeof(int);
//
//	//vector<int> v(ar, ar + n);
//
//	//cout << v.size() << ":" << v.capacity() << endl;
//
//	//v.reserve(100);
//
//	//v.resize(20);
//
//	//cout << v.size() << ":" << v.capacity() << endl;
//
//	//v.reserve(50);
//
//	//v.resize(5);
//
//	//cout << v.size() << ":" << v.capacity() << endl;
//
//
//	int num = 0;
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(1);
//	v.push_back(2);
//
//	for (auto n : v) {
//		num ^= n;
//	}
//
//	cout << num;
//
//
//
//}


//﻿int main()
//
//{
//
//	int ar[] = { 1,2,3,4,5,6,7,8,9,10 };
//
//	int n = sizeof(ar) / sizeof(int);
//
//	vector<int> v(ar, ar + n);
//
//	cout << v.size() << ":" << v.capacity() << endl;
//
//	v.reserve(100);
//
//	v.resize(20);
//
//	cout << v.size() << ":" << v.capacity() << endl;
//
//	v.reserve(50);
//
//	v.resize(5);
//
//	cout << v.size() << ":" << v.capacity() << endl;
//
//}


//int main() {
//	int line = 5;
//
//	vector<vector<int>> triangle(line);
//	for (size_t i = 0; i < line; i++) {
//		triangle[i].resize(i + 1);
//		for (size_t k = 0; k <= i; k++) {
//			if (k == 0 || i == k) {
//				triangle[i][k] = 1;
//			}
//			else
//				triangle[i][k] = triangle[i - 1][k] + triangle[i - 1][k - 1];
//		}
//	}
//
//	return -1;
//}

int main() {
	vector<int> nums = { 1,2,1,2,3,4 };
	
	for (size_t i = 0; i < nums.size(); i++) {
		while ((nums.begin() + i) != nums.end()) {
			if(nums.begin()+i==)
		}
	}



}