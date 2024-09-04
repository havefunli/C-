//#include <iostream>
//#include <string>
//using namespace std;
//
//void swap(char& x, char& y) {
//	char temp = x;
//	x = y;
//	y = temp;
//}
//
//void work_1() {
//	string s;
//
//	cout << "请输入字符串：";
//	getline(cin, s);
//
//	int start = 0;
//	int end = s.size() - 1;
//
//	while (start <= end) {
//		swap(s[start], s[end]);
//
//		start++;
//		end--;
//	}
//
//	cout << s;
//}
//
//int index(string& s1, string& s2) {
//	if ((s1.size() < s2.size())) return -1;
//
//	int result = -1;
//	for (int i = 0; i <= s1.size() - s2.size(); i++) {
//		if (s1[i] == s2[0]) {
//			bool found = true;
//			for (int j = 0; j < s2.size(); j++) {
//				if (s1[i + j] != s2[j]) {
//					found = false;
//					break;
//				}
//			}
//			if (found) {
//				result = i;
//				break;
//			}
//		}
//	}
//
//	return result;
//}
//
//void work_2() {
//	string s1;
//	cout << "请输入s1：";
//	getline(cin, s1);
//
//	string s2;
//	cout << "请输入s2：";
//	getline(cin, s2);
//
//	cout << index(s1, s2);
//}
//
//int main() {
//	work_1();
//	work_2();
//}
//
//
//
//
//
//
//
#include <stdio.h>

typedef struct Question {
	int (*detec)(int map[7][7], int* stack, int top);
} Question;

int detec(int map[7][7], int* stack, int top) {
	for (int j = 0; j < 7; ++j) {
		if (map[j][top] == 1 && stack[top] == stack[j]) return 1;
	}
	return 0;
}

void test() {
	const char* colorarr[4] = { "粉色", "黄色", "红色", "绿色" };
	int map[7][7] = {
		{0, 1, 1, 1, 1, 1, 0},
		{1, 0, 0, 0, 0, 1, 0},
		{1, 0, 0, 1, 1, 0, 0},
		{1, 0, 1, 0, 1, 1, 0},
		{1, 0, 1, 1, 0, 1, 0},
		{1, 1, 0, 1, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 0},
	};
	int stack[7];
	int top = 0;
	int color = 0;
	stack[top++] = color;
	while (top < 7) {
		while (color < 4 && top < 7) {
			stack[top] = color;
			while (detec(map, stack, top)) {
				color++;
				stack[top] = color;
			}
			if (color < 4) {
				top++;
				color = 0;
			}
		}
		if (color >= 4) {
			top--;
			color = stack[top] + 1;
		}
	}
	for (int i = 0; i < 7; ++i) {
		printf("第%d区域颜色是: %s\n", i + 1, colorarr[stack[i]]);
	}
}

int main() {
	test();
	return 0;
}
