#define  _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	int i = 1;
//	int k = 1;
//	for (i = 1; i <= 9; i++)
//	{
//		for (k = i; k <= 9; k++)
//		{
//			printf("%2d * %2d = %2d ", i, k, i * k);
//		}
//		printf("\n");
//	}
//	return 1;
//}
//#include<stdio.h>
//int main()
//{
//	int num = 0;
//	int i = 0;
//	int max = -100;
//
//	for (i; i < 10; i++)
//	{
//		scanf("%d", &num);
//		if (num > max)
//			max = num;
//	}
//	printf("%d", max);
//	return 0;
//}
//#include<stdio.h>
//#include<math.h>
//
//int main()
//{
//	int i = 1;
//	float sum = 0;
//
//	for (i = 1; i <= 100; i++)
//	{
//		sum += (float)1 / i * pow(-1, i - 1);
//	}
//	
//	printf("%f ", sum);
//	return 0;
//}
//#include<stdio.h>
//
//int main()
//{
//	int i = 9;
//	int count = 0;
//
//	for (i; i <= 100; i++)
//	{
//		if (i % 10 == 9 && i / 10 == 9)
//		{
//			count += 2;
//		}
//		else if (i % 10==9)
//		{
//			count++;
//		}
//		else if(i/10==9)
//		{
//			count++;
//		}
//	}
//
//	printf("%d ", count);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int arr[10];
//	for (int i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	int num = 0;
//	scanf("%d", &num);
//	int left = 0;
//	int right = 9;
//	int count = 0;
//	 
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (num > arr[mid])
//		{
//			left = mid + 1;
//		}
//		else if (num < arr[mid])
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			printf("%d", mid);
//			count++;
//			break;
//		}
//	}
//	if (count == 0)
//	{
//		printf("nothing");
//	}
//	return 0;
//}
//#include<stdio.h>
//
//int main()
//{
//	int a = 0, b = 0;
//	scanf("%d %d", &a, &b);
//	int c = (a > b ? a : b);
//
//	while (a % c != 0 || b % c != 0)
//	{
//		c--;
//	}
//
//	printf("%d", c);
//	return 0;
//}

//#include<stdio.h>
//#include<time.h>
//#include<stdlib.h>
// 
//void menu()
//{
//	printf("*******************\n");
//	printf("*******1 Start*****\n");
//	printf("*******0 exit******\n");
//	printf("*******************\n");
//}
//
//void game()
//{
//	int guess = 0;
//	int ret = rand() % 100 + 1;
//	while (1)
//	{
//		printf("输入猜测的数字：");
//		scanf("%d", &guess);
//		if (guess > ret)
//			printf("big\n");
//		else if (guess < ret)
//			printf("small\n");
//		else
//		{
//			printf("bingo\n");
//			break;
//		}
//	}
//}
//
//int main()
//{
//	srand((unsigned int)time(NULL));
//	int select = 0;
//	do
//	{
//		menu();
//		printf("输入你的选择：");
//		scanf("%d", &select);
//		switch (select)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			break;
//		default:
//			printf("ERROR\n");
//			break;
//		}
//	} while (select);
//}

//#include<stdio.h>
//#include<string.h>
//
//int main()
//{
//	int num = 0;
//	int i = 0;
//	scanf("%d", &num);
//
//	for (i = 1; i <= num; i++)
//	{
//		for (int k = i; k <= num; k++)
//		{
//			printf("%3d * %3d = %3d ", i, k, i * k);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//#include<stdio.h>
//
// void exchange(int* pa, int* pb)
//{
//	 int temp = *pa;
//	 *pa = *pb;
//	 *pb = temp;
//}
//
//int main()
//{
//	int a = 0, b = 0;
//	scanf("%d %d", &a, &b);
//	printf("a=%d,b=%d\n", a, b);
//
//	exchange(&a, &b);
//	printf("a=%d,b=%d\n", a, b);
//	return 0;
//}

//#include<stdio.h>
//
//void IsLeapYear(int year)
//{
//	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
//	{
//		printf("Is leap year!");
//	}
//	else
//	{
//		printf("Is not leap year!");
//	}
//}
//
//int main()
//{
//	int year = 0;
//	scanf("%d", &year);
//
//	IsLeapYear(year);
//	return 0;
//}

//#include<stdio.h>
//#include<math.h>
//
//int IsPrime(int k)
//{
//	for (int i = 2; i <= sqrt(k); i++)
//	{
//		if (k % i == 0)
//			return 0;
//	}
//	return 1;
//}
//
//int main()
//{
//	int i = 0;
//	int ret = 0;
//
//	for (i = 101; i <= 199; i += 2)
//	{
//		if (ret = IsPrime(i))
//		{
//			printf("%d ", i);
//		}	
//	}
//	
//	return 0;
//}


//#include<stdio.h>
//
//double Pow(int n, int k)
//{
//	if (k == 0)
//	{
//		return 1;
//	}
//	else if (k > 0)
//	{
//		return n * Pow(n, --k);
//	}
//	else
//	{
//		return 1 / n * Pow(n, ++k);
//	}
//}
//
//int main()
//{
//	int n = 0, k = 0;
//	scanf("%d %d", &n, &k);
//
//	double ret = Pow(n, k);
//	printf("%lf ", ret);
//
//	return 0;
//}

//#include<stdio.h>
//
//int Add(int n)
//{
//	int sum = 0;
//
//	if (n > 9)
//	{
//		return n / 10;
//	}
//	else
//	{
//		
//	}
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//
//	int ret = Add(n);
//	printf("%d", ret);
//
//	return 0;
//}

//#include<stdio.h>
//
//int Fib(int n)
//{
//	if (n <= 2)
//	{
//		return 1;
//	}
//	else
//	{
//		return Fib(n - 1) + Fib(n - 2);
//	}
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//
//	int ret = Fib(n);
//	printf("%d\n", ret);
//
//	return 0;
//}

//#include<stdio.h>
//
//int main()
//{
//	int n = 0,i = 0;
//	int a = 1, b = 1, c = 1;
//	scanf("%d", &n);
//	
//	for(int i = 3 ; i <= n ; i ++)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//	}
//	printf("%d", c);
//
//	return 0;
//}

//#include<stdio.h>
//
//void exchange(char* p)
//{
//	if ( *p != '\0')
//	{
//		exchange(++p);
//	}
//
//	printf("%c", *p);
//}
//
//int main()
//{
//	char arr[] = "abcdef";
//
//	exchange(arr);
//}

#include<stdio.h>

//int Fac(int n)
//{
//	int i = 0;
//	int mul = 1;
//
//	for (int i = 1; i <= n; i++)
//	{
//		mul *= i;
//	}
//
//	return mul;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//
//	int ret =Fac(n);
//	printf("%d", ret);
//
//	return 0;
//}

//int Fac(int n)
//{
//	if (n == 1)
//		return 1;
//	else
//	{
//		return n * Fac(n - 1);
//	}
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//
//	int ret = Fac(n);
//	printf("%d", ret);
//
//	return 0;
//}

//#include <stdio.h>
//
//#include <stdio.h>
//int main()
//{
//    int arr[] = { 1,2,(3,4),(5,6)};
//    printf("%d\n", sizeof(arr));
//    return 0;
//}

//#include<stdio.h>
//#include<string.h>
//
//int main()
//{
//	char arr1[10] = "liquan";
//	char arr2[10] = "hello";
//	char temp[10];
//
//	strcpy(temp, arr1);
//	strcpy(arr1, arr2);
//	strcpy(arr2, temp);
//
//	printf("%s\n", arr1);
//	printf("%s\n", arr2);
//
//	return 1;
//}

//#include <stdio.h>
//
//void print(int* p, int len)
//{
//	int k = 0;
//
//	for (k = 0; k < len; k++)
//	{
//		printf("%d ", *(p+k));
//	}
//	printf("\n");
//}
//
//void reverse(int* p, int len)
//{
//	int* q = p;;
//	int left = 0;
//	int right = len - 1;
//
//	while (left < right)
//	{
//		int temp;
//		temp = *(p + left);
//		*(p + left) = *(q + right);
//		*(q + right) = temp;
//		left++;
//		right--;
//	}
//}
//
//int main()
//{
//	int arr[10] = { 0 };
//	int i = 0;
//
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//
//	int len = sizeof(arr) / sizeof(arr[0]);
//	print(arr, len);
//
//	reverse(arr, len);
//	print(arr, len);
//
//	return 0;
//}


//#include <stdio.h>
//
//int main()
//{
//	int arr[10];
//	int i = 0;
//	int k = 0;
//
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//
//	for (i = 0; i < 9; i++)
//	{
//		int count = 0;
//		int temp = 0;
//		for (k = 0; k < 9 - i; k++)
//		{
//			if (arr[k] > arr[k + 1])
//			{
//				temp = arr[k];
//				arr[k] = arr[k + 1];
//				arr[k + 1] = temp;
//				count = 1;
//			}
//		}
//		if (count == 0)
//			break;
//	}
//
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 1;
//}






















