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

//�����ַ���

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


//���Ͼ���
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
	printf("���������������ַ�������");
	scanf("%d", &num);
	printf("before��%s\n", str);
	char* double_string = (char*)malloc(2 * len + 1);//����һ�ζ�̬�ڴ�ռ��Է���˫����
	assert(double_string);//����ռ��Ƿ�����ɹ�
	strcpy(double_string, str);//�Ƚ�str������double_string
	strcat(double_string, str);//�ٽ�strƴ����double_string���������˫�����Ĺ���
	strncpy(str, double_string + num, len);//ʹ��strncpy��ɶ�Ӧ����������
	printf("after��%s\n", str);
	free(double_string);//�ͷ�֮ǰ����Ķ�̬�ڴ�ռ�

	return 0;
}