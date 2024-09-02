#define  _CRT_SECURE_NO_WARNINGS 1
#define Max 1024
#include <stdio.h>
#include <string.h>
#include <math.h>

//int main()
//{
//	int arr[8] = { 0 };
//	int* p = arr;
//	int i = 0;
//	for (i; i < 8; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//
//	for (i = 0; i < 8; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//  return 0
//}

//ÄæÐò×Ö·û´®ÄÚÈÝ

//void exchange(char* left, char* right)
//{
//	char temp;
//	while (left <= right)
//	{
//		temp = *left;
//		*left = *right;
//		*right = temp;
//
//		left++;
//		right--;
//	}
//}
//
//int main()
//{
//	char arr[Max];
//	gets(arr);
//	int len = strlen(arr);
//
//	char* left = arr;
//	char* right = arr + len - 1;
//
//	exchange(left, right);
//
//	printf("%s", arr);
//
//	return 0;
//}

//Ë®ÏÉ»¨Êý

//int how_many_bits(int n)
//{
//
//	static int  count = 0;
//	if (n <= 9)
//	{
//		return count=1;
//	}
//	else
//	{
//		how_many_bits(n / 10);
//		count++;
//	}
//
//	return count;
//}
//
//
//int main()
//{
//	int i = 0;
//
//	for (i; i < 100000; i++)
//	{
//		int num = i;
//		int count = 0;
//		int n = how_many_bits(i);
//		while (num)
//		{
//			count += pow(num % 10, n);
//			num = num / 10;
//		}
//		if (i == count)
//			printf("%d ", i);
//	}
//	
//	return 0;
//}

//int main()
//{
//	int count = 0;
//	int n = 0;
//	int i = 0;
//	scanf("%d", &n);
//
//	for (i; i < 4; i++)
//	{
//		n = n * 10 + 2;
//		count += n;
//	}
//	count += 2;
//
//	printf("%d", count);
//
//	return 0;
//}

int main()
{
	int n = 0;
	int i = 1;
	scanf("%d", &n);

	for (i; i <= n; i += 2)
	{
		int j = n - i;
		while (j--)
		{
			printf(" ");
		}
		
		int k = i;
		while (k--)
		{
			printf("* ");
		}
		printf("\n");
	}

	for (i = n - 2; i > 0; i -= 2)
	{
		int j = n - i;
		while (j--)
		{
			printf(" ");
		}

		int k = i;
		while (k--)
		{
			printf("* ");
		}
		printf("\n");
	}

}