#define  _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//int main()
//{
//	unsigned char a = 200;
//	unsigned char b = 100;
//	unsigned char c = 0;
//	c = a + b;
//	printf("%d %d", a + b, c);
//	return 0;
//}

//int main()
//{
//	int arr[100][100] = { 0 };
//	int n = 0;
//	scanf("%d", &n);
//
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		int k = 0;
//		for (k = 0; k <= i; k++)
//		{
//			if (k == 0 || k == i)
//			{
//				arr[i][k] = 1;
//				printf("%d ", arr[i][k]);
//			}
//			else
//			{
//				arr[i][k] = arr[i - 1][k - 1] + arr[i - 1][k];
//				printf("%d ", arr[i][k]);
//			}
//		}
//		printf("\n");
//	}
//
//	return 0;
//}

//常量字符串

//int main()
//{
//	/*const char* pa = "liquan";
//	const char* pb = "liquan";
//
//	printf("%p %p", pa, pb);*/
//
//	//int arr1[3] = { 1,2,3 };
//	//int arr2[3] = { 4,5,6 };
//	//int arr3[3] = { 7,8,9 };
//
//	//int* arr[3] = { arr1,arr2,arr3 };
//
//	//int i = 0;
//	//for (i = 0; i < 3; i++)
//	//{
//	//	int k = 0;
//	//	for (k = 0; k < 3; k++)
//	//	{
//	//		printf("%d ", arr[i][k]);
//	//	}
//	//	printf("\n");
//	//}
//
//	int arr[2][2] = { 1,2,3,4 };
//	
//
//	return 0;
//}


//杨氏矩阵
int main()

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>

int main()
{
	char str[] = "abcd1234";
	int len = strlen(str);
	int num = 0;
	printf("输入你想左旋的字符个数：");
	scanf("%d", &num);
	printf("before：%s\n", str);
	char* double_string = (char*)malloc(2 * len + 1);//申请一段动态内存空间以放置双倍串
	assert(double_string);//检验空间是否申请成功
	strcpy(double_string, str);//先将str拷贝给double_string
	strcat(double_string, str);//再将str拼接至double_string，即完成了双倍串的构建
	strncpy(str, double_string + num, len);//使用strncpy完成对应次数的左旋
	printf("after：%s\n", str);
	free(double_string);//释放之前申请的动态内存空间

	return 0;
}