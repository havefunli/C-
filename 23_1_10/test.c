#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//int main()
//{
//	double x = 2, y = 0;
//
//	y = x + 3 / 2;
//
//	printf("%lf", y);
//}

//最小公倍数
//int main()
//{
//	int a = 0, b = 0;
//	scanf("%d %d", &a, &b);
//
//	int Max = a > b ? a : b;
//
//	while (Max % a != 0 || Max % b != 0)
//	{
//		Max++;
//	}
//
//	printf("%d", Max);
//
//	return 0;
//}

//字符串倒序
//#include <assert.h>
//
//void change(char* left, char* right)
//{
//	assert(left && right);
//
//	while (left < right)
//	{
//		char temp = 0;
//		temp = *left;
//		*left = *right;
//		*right = temp;
//		left++;
//		right--;
//	}
//}
//
//
//int main()
//{
//	char arr[100];
//	int i = 0;
//
//	while ((arr[i] = getchar()) != '\n')
//	{
//		i++;
//	}
//	arr[i] = '\0';
//
//	change(arr, arr + i - 1);
//
//	char* end = arr;
//	while (*end != '\0')
//	{
//		char* start = end;
//		while (*end != ' ' && *end != '\0')
//		{
//			end++;
//		}
//		change(start, end - 1);
//		end++;
//	}
//
//	printf(arr);
//
//	return 0;
//}

//int main()
//{
//	int n = 0xaabbccdd;
//	char* p = (char*) & n;
//
//	*p = 0;
//
//	if (n == 0x00bbccdd)
//	{
//		printf("大端存储\n");
//	}
//	else if (n == 0xaabbcc00)
//	{
//		printf("小端存储！\n");
//	}
//
//	return 0;
//}

//整型提升

int main()
{
	unsigned char a = 200;
	unsigned char b = 100;
	unsigned char c = 0;
	c = a + b;
	printf("%d %d",a+b,c);
	return 0;
}
